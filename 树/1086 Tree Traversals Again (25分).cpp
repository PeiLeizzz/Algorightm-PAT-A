#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
const int maxn = 31;
int N, n = 0;
int pre[maxn];
int in[maxn];
stack<int> s;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v) {
		val = v;
		left = right = NULL;
	}
};

TreeNode* createTree(int pl, int pr, int il, int ir) {
	if (pl > pr) return NULL;
	TreeNode* root = new TreeNode(pre[pl]);
	int k;
	for (k = il; k <= ir; k++) {
		if (pre[pl] == in[k]) break;
	}
	root->left = createTree(pl+1, pl+k-il, il, k-1);
	root->right = createTree(pl+k-il+1, pr, k+1, ir);
	return root;
}

void postOrder(TreeNode* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	if (n > 0) {
		printf(" ");
	}
	else {
		n = 1;
	}
	printf("%d", root->val);
}

int main() {
	scanf("%d\n", &N);
	int pi = 0, ii = 0;
	for (int i = 0; i < 2 * N; i++) {
		char str[5];
		scanf("%s", str);
		if (strcmp(str, "Push") == 0) {
			scanf("%d\n", &pre[pi]);
			s.push(pre[pi]);
			pi++;
		}
		else {
			in[ii++] = s.top();
			s.pop();
		}
	}
	TreeNode* root = createTree(0, pi-1, 0, ii-1);
	postOrder(root);
	return 0;
}
