#include <bits/stdc++.h>
using namespace std;
int N, M, st, en;
const int maxn = 505, inf = 0x3fffffff;
struct node {
	int id, dis;
	node(int _id, int _dis): id(_id), dis(_dis) {}
};
vector<node> g[maxn];
set<int> pre[maxn];
int teams[maxn], paths[maxn], rescue[maxn], dis[maxn], inq[maxn];

void init() {
	scanf("%d %d %d %d", &N, &M, &st, &en);
	fill(paths, paths + N, 0);
	fill(rescue, rescue + N, 0);
	fill(inq, inq + N, 0);
	fill(dis, dis + N, inf);
	for (int i = 0; i < N; i++) {
		scanf("%d", &teams[i]);
	}
	for (int i = 0; i < M; i++) {
		int c1, c2, d;
		scanf("%d %d %d", &c1, &c2, &d);
		g[c1].push_back(node(c2, d));
		g[c2].push_back(node(c1, d));
	}
	paths[st] = 1;
	rescue[st] = teams[st];
	dis[st] = 0;
}

void SPFA() {
	queue<int> q;
	q.push(st);
	inq[st] = 1;
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		inq[t] = 0;
		for (int i = 0; i < g[t].size(); i++) {
			int v = g[t][i].id, d = g[t][i].dis;
			if (dis[v] > dis[t] + d) {
				dis[v] = dis[t] + d;
				rescue[v] = rescue[t] + teams[v];
				pre[v].clear();
				pre[v].insert(t);
				paths[v] = paths[t];
				if (!inq[v]) {
					q.push(v);
					inq[v] = 1;
				}
			}
			else if (dis[v] == dis[t] + d) {
				rescue[v] = max(rescue[v], rescue[t] + teams[v]);
				paths[v] = 0;
				pre[v].insert(t);
				for (set<int>::iterator it = pre[v].begin(); it != pre[v].end(); it++) {
					paths[v] += paths[*it];
				}
				if (!inq[v]) { // 需要再次入队 因为可能经过 v 点后面的路径得到的 rescue 更大
					q.push(v);
					inq[v] = 1;
				}
			}
		}
	}
}

int main() {
	init();
	SPFA();
	printf("%d %d", paths[en], rescue[en]);
	return 0;
}
