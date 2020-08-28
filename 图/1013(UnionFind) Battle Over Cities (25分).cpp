#include <bits/stdc++.h>
using namespace std;
int N, M, K, cnt;
const int maxn = 1005;
int node[maxn];
vector<int> g[maxn];

void init() {
	for (int i = 1; i <= N; i++) {
		node[i] = i;
	}
}

int find(int x) {
	if (x != node[x]) {
		return node[x] = find(node[x]);
	}
	return x;
}

void Union(int c1, int c2) {
	int r1 = find(c1), r2 = find(c2);
	if (r1 != r2) {
		node[r1] = r2;
		cnt--;
	}
}


int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++) {
		int c1, c2;
		scanf("%d %d", &c1, &c2);
		g[c1].push_back(c2);
		g[c2].push_back(c1);
	}
	for (int i = 0; i < K; i++) {
		cnt = N - 1; // 除去被删除的点，初始有 n - 1 个联通分量
		int c;
		scanf("%d", &c);
		init();
		for (int v = 1; v <= N; v++) {
			for (int u = 0; u < g[v].size(); u++) {
				int c1 = v, c2 = g[v][u];
				if (c1 == c || c2 == c) continue;
				Union(c1, c2);
			}
		}
		printf("%d\n", cnt - 1);
	}
	return 0;
}
