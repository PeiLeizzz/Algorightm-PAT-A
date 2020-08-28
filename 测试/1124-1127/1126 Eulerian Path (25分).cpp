#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n, m;
int degree[maxn], vis[maxn], g[maxn][maxn];

void dfs(int v) {
	vis[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && g[v][i]) {
			dfs(i);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		degree[v1]++;
		degree[v2]++;
		g[v1][v2] = 1;
		g[v2][v1] = 1;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i > 1) printf(" ");
		printf("%d", degree[i]);
		if (degree[i] % 2 == 1) cnt++;
	}
	// 判断是不是连通图
	dfs(1);
	int flag = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			flag = 0;
			break;
		}
	}
	printf("\n");
	if (cnt == 0 && flag == 1) printf("Eulerian");
	else if (cnt == 2 && flag == 1) printf("Semi-Eulerian");
	else printf("Non-Eulerian");
	return 0;
}
