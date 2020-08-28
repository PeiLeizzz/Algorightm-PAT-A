#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 105;
int N, index = 0;
int values[maxn];
struct TreeNode {
	int val, left, right;
} node[maxn];

void inOrder(int root) {
	if (root == -1) return;
	inOrder(node[root].left);
	node[root].val = values[index++];
	inOrder(node[root].right);
}

void levelOrder(int root) {
	index = 0;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t != -1) {
			if (index++ > 0) printf(" ");
			printf("%d", node[t].val);
			q.push(node[t].left);
			q.push(node[t].right);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		node[i].left = l;
		node[i].right = r;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &values[i]);
	}
	sort(values, values + N);
	inOrder(0);
	levelOrder(0);
	return 0;
}
