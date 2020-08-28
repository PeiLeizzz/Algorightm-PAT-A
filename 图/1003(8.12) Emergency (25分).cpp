#include <iostream>
#include <vector>
using namespace std;
const int maxn = 502, inf = 0x3fffffff;
int N, M, st, en;
struct node {
	int id, dis;
	node(int _id, int _dis) {
		id = _id, dis = _dis;
	}
};
vector<node> g[maxn];
int teams[maxn], dis[maxn], paths[maxn], rescue[maxn], vis[maxn];

void init() {
	fill(paths, paths+N, 0);
	fill(rescue, rescue+N, 0);
	fill(vis, vis+N, 0);
	fill(dis, dis+N, inf);
	for (int i = 0; i < N; i++) {
		scanf("%d", &teams[i]);
	}
	for (int i = 0; i < M; i++) {
		int c1, c2, l;
		scanf("%d %d %d", &c1, &c2, &l);
		g[c1].push_back(node(c2, l));
		g[c2].push_back(node(c1, l));
	}
	rescue[st] = teams[st];
	paths[st] = 1;
	dis[st] = 0;
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
			if (!vis[v] && dis[u] + d < dis[v]) {
				dis[v] = dis[u] + d;
				rescue[v] = rescue[u] + teams[v];
				paths[v] = paths[u];
			}
			else if (!vis[v] && dis[u] + d == dis[v]) {
				rescue[v] = max(rescue[v], rescue[u] + teams[v]);
				paths[v] += paths[u];
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &N, &M, &st, &en);
	init();
	dijkstra();
	printf("%d %d", paths[en], rescue[en]);
	return 0;
}
