#include <iostream>
#include <vector>
using namespace std;
int N, M, S, D;
const int maxn = 505, inf = 0x3fffffff;
struct node {
	int id, dis;
	node(int _id, int _dis) {
		id = _id, dis = _dis;
	}
};
vector<node> g[maxn];
vector<int> pre[maxn], tmpPath, path;
int vis[maxn], cost[maxn][maxn], dis[maxn], totalCost = inf, tmpCost = 0;

void init() {
	fill(vis, vis+N, 0);
	fill(dis, dis+N, inf);
	for (int i = 0; i < M; i++) {
		int c1, c2, dis, c;
		scanf("%d %d %d %d", &c1, &c2, &dis, &c);
		g[c1].push_back(node(c2, dis));
		g[c2].push_back(node(c1, dis));
		cost[c1][c2] = c;
		cost[c2][c1] = c;
	}
	dis[S] = 0;
}

void dijkstra() {
	for (int i = 0; i < N; i++) {
		int u = -1, minL = inf;
		for (int j = 0; j < N; j++) {
			if (!vis[j] && dis[j] < minL) {
				minL = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j].id, d = g[u][j].dis;
			if (!vis[v] && dis[v] > dis[u] + d) {
				dis[v] = dis[u] + d;
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (!vis[v] && dis[v] == dis[u] + d) {
				pre[v].push_back(u);
			}
		}
	}
}

void dfs(int v) {
	if (v == S) {
		if (tmpCost < totalCost) {
			totalCost = tmpCost;
			path = tmpPath;
			path.push_back(v);
			return;
		}
	}
	tmpPath.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		int id = pre[v][i];
		tmpCost += cost[v][id];
		dfs(id);
		tmpCost -= cost[v][id];
	}
	tmpPath.pop_back();
}

int main() {
	scanf("%d %d %d %d", &N, &M, &S, &D);
	init();
	dijkstra();=
	dfs(D);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d ", path[i]);
	}
	printf("%d %d", dis[D], totalCost);
	return 0;
}
