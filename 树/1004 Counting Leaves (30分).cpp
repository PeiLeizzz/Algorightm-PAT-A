#include <vector>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
// memset ͷ�ļ� <string.h> �� <memory.h>
using namespace std;
const int maxn = 105;
int N, M, D;
struct TreeNode {
	vector<int> child;
} node[maxn];
int depth[maxn];

void bfs(int root) {
	queue<int> q;
	q.push(root);
	int d = 0;
	while (!q.empty()) {
		int l = q.size();
		while (l--) {
			int t = q.front();
			q.pop();
			if (node[t].child.size() == 0) {
				depth[d]++;
			}
			else {
				for (int i: node[t].child) {
					q.push(i);
				}
			}
		}
		d++;
	}
	D = d; // ��¼�������ȣ�d=��������+1 ��depth�����Ԫ�ظ�����
}

int main() {
	memset(depth, 0, sizeof(depth));
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
	for (int i = 0; i < D; i++) {
		if (i > 0) printf(" ");
		printf("%d", depth[i]);
	}
	return 0;
}
