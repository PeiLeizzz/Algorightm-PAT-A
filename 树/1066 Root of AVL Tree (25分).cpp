#include <bits/stdc++.h>
using namespace std;
int N;
struct TreeNode {
	int val, height;
	TreeNode *left, *right;
	TreeNode(int v) {
		val = v;
		height = 1;
		left = right = NULL;
	}
} *root = NULL;

int getHeight(TreeNode* root) {
	if (root == NULL) return 0;
	return root->height;
}

void updateHeight(TreeNode* root) {
	if (root == NULL) return;
	root->height = max(getHeight(root->left) + 1, getHeight(root->right) + 1);
}

int getBalanceFactor(TreeNode* root) {
	if (root == NULL) return 0;
	return getHeight(root->left) - getHeight(root->right);
}

TreeNode* L(TreeNode* root) {
	TreeNode* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	updateHeight(root);
	updateHeight(tmp);
	return tmp;
}

TreeNode* R(TreeNode* root) {
	TreeNode* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	updateHeight(root);
	updateHeight(tmp);
	return tmp;
}

TreeNode* insert(TreeNode* root, int v) {
	if (root == NULL) {
		root = new TreeNode(v);
		return root;
	}
	// 在右子树中插入
	if (v > root->val) {
		root->right = insert(root->right, v);
		updateHeight(root);
		if (getBalanceFactor(root) == -2) {
			// RR
			if (getBalanceFactor(root->right) == -1) {
				root = L(root);
			}
			// RL
			else if (getBalanceFactor(root->right) == 1) {
				root->right = R(root->right);
				root = L(root);
			}
		}
	}
	// 在左子树中插入
	else {
		root->left = insert(root->left, v);
		updateHeight(root);
		if (getBalanceFactor(root) == 2) {
			// LL
			if (getBalanceFactor(root->left) == 1) {
				root = R(root);
			}
			// LR
			else if (getBalanceFactor(root->left) == -1) {
				root->left = L(root->left);
				root = R(root);
			}
		}
	}
	return root;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int val;
		scanf("%d", &val);
		root = insert(root, val);
	}
	printf("%d", root->val);
	return 0;
}
