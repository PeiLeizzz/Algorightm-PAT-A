#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, inf = 0x3fffffff;
struct node {
	int id, len, time;
	node(int _id, int _len, int _time): id(_id), len(_len), time(_time) {}
};
vector<node> g[maxn];
vector<int> pre1(maxn, -1), pre2(maxn, -1);
int vis[maxn], dis1[maxn], tim1[maxn], dis2[maxn], tim2[maxn];
int n, m;

void init() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int c1, c2, one, l, t;
		scanf("%d %d %d %d %d", &c1, &c2, &one, &l, &t);
		g[c1].push_back(node(c2, l, t));
		if (one == 0) g[c2].push_back(node(c1, l, t));
	}
}

void dijkstra(int st, int dis[], int tim[], vector<int>& pre, int f) {
	fill(vis, vis + n, 0);
	fill(dis, dis + n, inf);
	fill(tim, tim + n, inf);
	dis[st] = 0;
	tim[st] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minl = inf;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] < minl) {
				minl = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j].id, l = g[u][j].len, t = g[u][j].time;
			if (f == 1) {
				l = t;
				t = 1; // 第二条路经要求：时间最短，时间相同时要求节点最少
				// 则可以将路径长度变为 1 代表一个节点
			}
			if (dis[v] > l + dis[u]) {
				dis[v] = l + dis[u];
				tim[v] = t + tim[u];
				pre[v] = u;
			}
			else if (dis[v] == l + dis[u] && tim[v] > tim[u] + t) {
				tim[v] = tim[u] + t;
				pre[v] = u;
			}
		}
	}
}

void dfs(int v, int st, vector<int>& pre, string& s) {
	if (v == st) {
		s = to_string(v) + s;
		return;
	}
	s = " -> " + to_string(v) + s;
	dfs(pre[v], st, pre, s);
}

int main() {
	init();
	int st, en;
	scanf("%d %d", &st, &en);
	dijkstra(st, dis1, tim1, pre1, 0);
	dijkstra(st, tim2, dis2, pre2, 1);
	if (pre1.size() == pre2.size() && pre1 == pre2) {
		printf("Distance = %d; Time = %d: ", dis1[en], tim2[en]);
		string p = "";
		dfs(en, st, pre1, p);
		cout << p;
	}
	else {
		printf("Distance = %d: ", dis1[en]);
		string p = "";
		dfs(en, st, pre1, p);
		cout << p;
		printf("\nTime = %d: ", tim2[en]);
		p = "";
		dfs(en, st, pre2, p);
		cout << p;
	}
	return 0;
}
