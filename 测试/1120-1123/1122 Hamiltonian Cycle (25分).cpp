#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int g[maxn][maxn];
int vis[maxn];
int n, m, k;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		g[v1][v2] = g[v2][v1] = 1;
	}
	scanf("%d", &k);
	while (k--) {
		int t, flag = 1, cnt = 1;
		scanf("%d", &t);
		fill(vis, vis + maxn, 0);
		int st;
		scanf("%d", &st);
		int p = st;
		for (int i = 1; i < t; i++) {
			int v;
			scanf("%d", &v);
			// 如果之前访问过（已形成环）或者 不存在边 或者 访问到起点的时候不是最后一个点，都不满足
			if (!flag || vis[v] || g[p][v] == 0 || (i < t - 1 && v == st)) {
				flag = 0;
				continue;
			}
			else {
				cnt++;
				vis[v] = 1;
			}
			p = v;
		}
		// 如果访问到的顶点数量不足 n，或者访问时已经错误(flag = 0) 或者终点和起点不同
		if (cnt < n || !flag || p != st) {
			printf("NO\n");
		}
		else printf("YES\n");
	}
	return 0;
}
