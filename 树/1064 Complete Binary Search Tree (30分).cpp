#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int level[maxn], nodes[maxn];
// level[1, N] 存放完全二叉树的层序序列   nodes 存放中序序列
int N, index = 0;

// 中序遍历 level 中存放的完全二叉树 并赋值
void inOrder(int root) {
	if (root > N) return;
	// 由于存放的是层序序列 所以左孩子是 root * 2，右孩子是 root * 2 + 1
	inOrder(root * 2);
	level[root] = nodes[index++];
	inOrder(root * 2 + 1);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nodes[i]);
	}
	sort(nodes, nodes + N);
	inOrder(1);
	for (int i = 1; i <= N; i++) {
		if (i > 1) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
