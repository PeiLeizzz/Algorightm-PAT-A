#include <bits/stdc++.h>
using namespace std;
int N;
const int maxn = 10005;
vector<int> g[maxn], res;
int visited[maxn] = {0}, maxd = 0, flag = 0;

void dfs(int v, int deep) {
	if (deep > maxd) {
		maxd = deep;
		flag = 1;
	}
	// 不能写 else if (deep == maxd) 因为可能之前的递归中进入上一个分支将 maxd = deep
	// 然后就会错误地使 flag = 2，实际上 flag 应该为 1
	// 只有 flag == 0 时遇到相等才是真正地相等
	else if (!flag && deep == maxd) {
		flag = 2;
	}
	visited[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		if (!visited[g[v][i]]) {
			dfs(g[v][i], deep + 1);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}
	
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i, 0);
			cnt++;
		}
	}
	if (cnt != 1) {
		printf("Error: %d components", cnt);
		return 0;
	}
	
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));
		flag = 0;
  		dfs(i, 0);
  		if (flag == 1) {
			res.clear();
			res.push_back(i);
		}
		else if (flag == 2) {
			res.push_back(i);
		}
	}
	sort(res.begin(), res.end());
	for (int r: res) {
		printf("%d\n", r);
	}
	return 0;
}
