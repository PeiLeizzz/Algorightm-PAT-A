#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, inf = 0x3fffffff;
int N, M, st, en;
struct node {
	int id, dis;
	node(int _id, int _dis) {
		id = _id, dis = _dis;
	}
};
vector<node> g[maxn];
int teams[maxn], dis[maxn], paths[maxn], rescue[maxn];
set<int> pre[maxn]; // 不能用 vector 因为一个结点会访问多次 所以会 insert 多次

void init() {
	scanf("%d %d %d %d", &N, &M, &st, &en);
	fill(dis, dis + N, inf);
	fill(paths, paths + N, 0);
	fill(rescue, rescue + N, 0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &teams[i]);
	}
	for (int i = 0; i < M; i++) {
		int c1, c2, d;
		scanf("%d %d %d", &c1, &c2, &d);
		g[c1].push_back(node(c2, d));
		g[c2].push_back(node(c1, d));
	}
}

void bellmanFord() {
	dis[st] = 0;
	paths[st] = 1;
	rescue[st] = teams[st];
	for (int i = 0; i < N - 1; i++) { // 外层循环 n - 1 次
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < g[j].size(); k++) {
				int v = g[j][k].id, d = g[j][k].dis;
				if (dis[j] + d < dis[v]) {
					dis[v] = dis[j] + d;
					rescue[v] = rescue[j] + teams[v];
					paths[v] = paths[j];
					pre[v].clear();
					pre[v].insert(j);
				}
				else if (dis[j] + d == dis[v]) {
					rescue[v] = max(rescue[v], rescue[j] + teams[v]);
					paths[v] = 0;
					pre[v].insert(j);
					for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++) {
						paths[v] += paths[*it];
					}
					// 不能 paths[v] += paths[j]
					// 因为一个 v 会遇到 j 多次
				}
			}
		}
	}
}

int main() {
	init();
	bellmanFord();
	printf("%d %d", paths[en], rescue[en]);
	return 0;
}
