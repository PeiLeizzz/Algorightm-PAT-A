#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N, L;
vector<int> g[maxn]; // g[i]: 第 i 个人的粉丝列表

int BFS(int v) {
	int visited[N + 1]; // 坑：因为编号从1开始，所以数组要开大一位
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(v);
	visited[v] = 1;
	int level = 1, res = 0;
	while (!q.empty() && level <= L) {
		int l = q.size();
		while (l--) {
			int t = q.front();
			q.pop();
			for (int i = 0; i < g[t].size(); i++) {
				int target = g[t][i];
				if (!visited[target]) {
					q.push(target);
					visited[target] = 1;
					res++;
				}
			}
		}
		level++;
	}
	return res;
}

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; i++) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int u;
			scanf("%d", &u);
			g[u].push_back(i);
		}
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int q;
		scanf("%d", &q);
		printf("%d\n", BFS(q));
	}
	return 0;
}
