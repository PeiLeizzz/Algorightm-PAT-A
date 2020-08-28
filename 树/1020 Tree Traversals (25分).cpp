#include <bits/stdc++.h>
using namespace std;

int n;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v) {
		val = v;
		left = NULL;
		right = NULL;
	}
};

TreeNode* createTree(int post[], int in[], int pl, int pr, int il, int ir) {
	if (pl > pr) return NULL;
	int k;
	for (int i = il; i <= ir; i++) {
		if (in[i] == post[pr]) {
			k = i;
			break;
		}
	}
	TreeNode* root = new TreeNode(post[pr]);
	root->left = createTree(post, in, pl, pl+k-il-1, il, k-1);
	root->right = createTree(post, in, pl+k-il, pr-1, k+1, ir);
	return root;
}

void levelOrder(TreeNode* root) {
	if (root == NULL) return;
	queue<TreeNode*> q;
	q.push(root);
	int cnt = 0;
	while (!q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();
		if (tmp != NULL) {
			printf("%d", tmp->val);
			cnt++;
			if (cnt < n) printf(" ");
			q.push(tmp->left);
			q.push(tmp->right);
		}
	}
}

int main() {
	scanf("%d", &n);
	int post[n], in[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	TreeNode* root = createTree(post, in, 0, n-1, 0, n-1);
	levelOrder(root);
	return 0;
}
