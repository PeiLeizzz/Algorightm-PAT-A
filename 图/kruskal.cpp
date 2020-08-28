#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, inf = 0x3ffffff;
struct edge {
	int v, u, dis;
	edge(int _v, int _u, int _dis): v(_v), u(_u), dis(_dis) {}
};
bool cmp(edge e1, edge e2) {
	return e1.dis < e2.dis;
}
int father[maxn];
void init() {
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
	}
}

int find(int x) {
	if (x != father[x]) {
		return father[x] = find(father[x]);
	}
	return x;
}

int main() {
	int n;
	while (scanf("%d", &n), n != 0) {
		vector<edge> g;
		int m = n * (n - 1) / 2;
		for (int i = 0; i < m; i++) {
			int c1, c2, l;
			scanf("%d %d %d", &c1, &c2, &l);
			g.push_back(edge(c1, c2, l));
		}
		sort(g.begin(), g.end(), cmp);
		init();
		int num = 0, res = 0;
		for (int i = 0; i < g.size(); i++) {
			int c1 = g[i].v, c2 = g[i].u;
			int r1 = find(c1), r2 = find(c2);
			if (r1 != r2) {
				father[r1] = r2;
				num++; // 增加一条边
				res += g[i].dis;
			}
			if (num == n - 1) break;
		}
		printf("%d\n", res);
	}
	return 0;
}
