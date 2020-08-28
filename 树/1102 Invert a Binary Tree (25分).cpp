#include <iostream>
#include <queue>
using namespace std;
int N, n = 0;
struct TreeNode {
	int left = -1, right = -1, father = -1;
} tree[10];

void leverOrder(int root) {
	if (root == -1) return;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (t != -1) {
			TreeNode node = tree[t];
			if (n > 0) printf(" ");
			printf("%d", t);
			q.push(node.left);
			q.push(node.right);
			n++;
			if (n == N) {
				printf("\n");
				n = 0;
			}
		}
	}
}

void inOrder(int root) {
	if (root == -1) return;
	TreeNode node = tree[root];
	inOrder(node.left);
	if (n > 0) printf(" ");
	printf("%d", root);
	n++;
	inOrder(node.right);
}

int main() {
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++) {
		char l, r;
		// 最关键的地方，交换左右子树，也可以正常读入，然后通过后序遍历交换
		scanf("%c %c", &r, &l);
		getchar();
		if (r == '-') tree[i].right = -1;
		else {
			tree[i].right = r-'0';
			tree[r-'0'].father = i;
		}
		if (l == '-') tree[i].left = -1;
		else {
			tree[i].left = l-'0';
			tree[l-'0'].father = i;
		}
	}
	int root;
	for (int i = 0; i < N; i++) {
		if (tree[i].father == -1) {
			root = i;
			break;
		}
		//cout << i << " " << tree[i].left << " " << tree[i].right << endl;
	}
	leverOrder(root);
	inOrder(root);
	return 0;
}
