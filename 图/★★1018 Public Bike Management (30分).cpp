#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, inf = 0x3fffffff;
int C, N, S, M;
struct node {
	int id, dis;
	node(int _id, int _dis): id(_id), dis(_dis) {}
};
vector<node> g[maxn];
vector<int> pre[maxn], path, tmp;
int bikes[maxn], dis[maxn], vis[maxn];
int minNeed = inf, minRemain = inf;

void init() {
	scanf("%d %d %d %d", &C, &N, &S, &M);
	fill(dis, dis + maxn, inf);
	fill(vis, vis + maxn, 0);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &bikes[i]);
		bikes[i] -= C / 2;
	}
	for (int i = 0; i < M; i++) {
		int s1, s2, n;
		scanf("%d %d %d", &s1, &s2, &n);
		g[s1].push_back(node(s2, n));
		g[s2].push_back(node(s1, n));
	}
	dis[0] = 0;
	bikes[0] = 0;
}

void dijkstra() {
	for (int i = 0; i <= N; i++) {
		int u = -1, minL = inf;
		for (int j = 0; j <= N; j++) {
			if (!vis[j] && minL > dis[j]) {
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

// 小顶堆优化
void dijkstra2() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(dis[0], 0));
	while (!q.empty()) {
		int l = q.top().first, id = q.top().second;
		q.pop();
		// if (vis[id]) continue; 是否添加这句不影响
		vis[id] = 1;
		for (int i = 0; i < g[id].size(); i++) {
			int v = g[id][i].id, d = g[id][i].dis;
			if (!vis[v] && dis[v] > l + d) {
				dis[v] = l + d;
				pre[v].clear();
				pre[v].push_back(id);
				q.push(make_pair(dis[v], v));
			}
			else if (!vis[v] && dis[v] == l + d) {
				pre[v].push_back(id);
				q.push(make_pair(dis[v], v));
			}
		}
	}
}

void dfs(int v) {
	if (v == 0) {
		tmp.push_back(v);
		int need = 0, remain = 0;
		// 必须倒着枚举：还原真实的路径
		for (int i = tmp.size() - 1; i >= 0; i--) {
			int id = tmp[i];
			if (bikes[id] > 0) {
				remain += bikes[id];
			}
			else {
				if (abs(bikes[id]) < remain) {
					remain -= abs(bikes[id]);
				}
				else {
					need += abs(bikes[id]) - remain; // 减负数
					remain = 0;
				}
			}
		}
		if (need < minNeed) {
			minNeed = need;
			minRemain = remain;
			path = tmp;
		}
		else if (need == minNeed && minRemain > remain) {
			minRemain = remain;
			path = tmp;
		}
		tmp.pop_back(); // 别忘了 pop_back()
		return;
	}
	tmp.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		int p = pre[v][i];
		dfs(p);
	}
	tmp.pop_back();
}

int main() {
	init();
	dijkstra2();
	dfs(S);
	printf("%d ", minNeed);
	for (int i = path.size() - 1; i >= 0; i--) {
		printf("%d", path[i]);
		if (i > 0) printf("->");
	}
	printf(" %d", minRemain);
	return 0;
}
