#include <bits/stdc++.h>
using namespace std;
int N, M, K;
const int maxn = 1005;
vector<vector<int>> g(maxn, vector<int>(maxn, 0)), temp;
int visited[maxn] = {0};

void dfs(int v, int& c) {
	if (v == c) return;
	visited[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (!visited[i] && temp[v][i]) {
			dfs(i, c);
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		g[c1][c2] = 1;
		g[c2][c1] = 1;
	}
	for (int i = 0; i < K; i++) {
		temp = g;
		memset(visited, 0, sizeof(visited));
		int c;
		scanf("%d", &c);
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (j != c && !visited[j]) {
				dfs(j, c);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}
