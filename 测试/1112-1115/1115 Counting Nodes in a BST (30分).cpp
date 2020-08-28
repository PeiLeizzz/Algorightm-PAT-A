#include <bits/stdc++.h>
using namespace std;
int n;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v) {
		val = v, left = right = NULL;
	}
};

TreeNode* insert(TreeNode* node, int v) {
	if (node == NULL) return new TreeNode(v);
	if (node->val < v) node->right = insert(node->right, v);
	else node->left = insert(node->left, v);
	return node;
}

void bfs(TreeNode* root) {
	if (root == NULL) return;
	int s1 = 0, s2 = 0;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int l = q.size();
		int s = 0;
		while (l--) {
			TreeNode* tmp = q.front();
			q.pop();
			s++;
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
		}
		s2 = s1;
		s1 = s;
	}
	printf("%d + %d = %d", s1, s2, s1 + s2);
}

int main() {
	TreeNode* root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		root = insert(root, v);
	}
	bfs(root);
	return 0;
}
