#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 105;
int N, M, D = 1, R = 1;
struct TreeNode {
	vector<int> child;
} node[maxn];

void bfs(int root) {
	queue<int> q;
	q.push(root);
	int d = 0;
	while (!q.empty()) {
		int l = q.size();
		if (R < l) {
			R = l;
			D = d + 1;
		}
		while (l--) {
			int t = q.front();
			q.pop();
			for (int i: node[t].child) {
				q.push(i);
			}
		}
		d++;
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int f, n;
		scanf("%02d %d", &f, &n);
		for (int j = 0; j < n; j++) {
			int c;
			scanf("%02d", &c);
			node[f].child.push_back(c);
		}
	}
	bfs(1);
	printf("%d %d", R, D);
	return 0;
}
