#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, inf = 0x3fffffff;
struct node {
	int id, dis;
	node(int _id, int _dis): id(_id), dis(_dis) {}
	friend bool operator < (const node& n1, const node& n2) {
		return n1.dis > n2.dis; // 小顶堆
	}
};
int n, m;
int vis[maxn], dis[maxn];

void init(vector<vector<node>>& g) {
	m = n * (n - 1) / 2;
	fill(vis, vis + maxn, 0);
	fill(dis, dis + maxn, inf);
	for (int i = 0; i < m; i++) {
		int c1, c2, l;
		scanf("%d %d %d", &c1, &c2, &l);
		g[c1].push_back(node(c2, l));
		g[c2].push_back(node(c1, l));
	}
}

int prim(vector<vector<node>>& g) {
	int res = 0;
	dis[1] = 0;
	priority_queue<node, vector<node>> q;
	q.push(node(1, dis[1]));
	while (!q.empty()) {
		node top = q.top();
		q.pop();
		int v = top.id;
		if (vis[v]) continue; // 必须要有这个判断
		res += top.dis; 
		vis[v] = 1;
		// cout << v << " " << top.dis << endl;
		for (int i = 0; i < g[v].size(); i++) {
			int u = g[v][i].id, d = g[v][i].dis;
			if (!vis[u] && dis[u] > d) {
				dis[u] = d;
				q.push(node(u, dis[u]));
			}
		}
	}
	return res;
}

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf("%d", &n), n != 0) {
		vector<vector<node>> g(maxn, vector<node>());
		init(g);
		printf("%d\n", prim(g));
	}
	//fclose(stdin);
	return 0;
}
