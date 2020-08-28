#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int n;
struct TreeNode {
	int val, height = 0;
	TreeNode *left = NULL, *right = NULL;
	TreeNode(int v) {
		val = v, height = 1;
	}
};

int getHeight(TreeNode* node) {
	if (node == NULL) return 0;
	return node->height;
}

void updateHeight(TreeNode* node) {
	if (node == NULL) return;
	node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

int getBalanceFactor(TreeNode* node) {
	if (node == NULL) return 0;
	return getHeight(node->left) - getHeight(node->right);
}

void L(TreeNode* &node) { // 一定要写引用
	if (node == NULL) return;
	TreeNode* tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	updateHeight(node); // 更新顺序不能错
	updateHeight(tmp);
	node = tmp;
}

void R(TreeNode* &node) {
	if (node == NULL) return;
	TreeNode* tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	updateHeight(node);
	updateHeight(tmp);
	node = tmp;
}

TreeNode* insert(TreeNode* node, int v) {
	if (node == NULL) {
		return new TreeNode(v);
	}
	if (v > node->val) {
		node->right = insert(node->right, v);
		updateHeight(node); // 别忘了更新高度
		if (getBalanceFactor(node) == -2) {
			if (getBalanceFactor(node->right) == -1) {
				L(node);
			}
			else if (getBalanceFactor(node->right) == 1) {
				R(node->right);
				L(node);
			}
		}
	}
	else {
		node->left = insert(node->left, v);
		updateHeight(node);
		if (getBalanceFactor(node) == 2) {
			if (getBalanceFactor(node->left) == 1) {
				R(node);
			}
			else if (getBalanceFactor(node->left) == -1) {
				L(node->left);
				R(node);
			}
		}
	}
	return node;
}

bool bfs(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	int cnt = 0, f1 = 0, f2 = 0;
	while (!q.empty()) {
		int l = q.size();
		while (l--) {
			TreeNode* tmp = q.front();
			q.pop();
			if (cnt > 0) printf(" ");
			printf("%d", tmp->val);
			cnt = 1;
			if (tmp->left) {
				q.push(tmp->left);
				if (f1 == 1) f2 = 1;
			}
			else f1 = 1;
			if (tmp->right) {
				q.push(tmp->right);
				if (f1 == 1) f2 = 1;
			}
			else f1 = 1;
		}
	}
	if (f2 == 1) return false;
	return true;
}

int main() {
	TreeNode* root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		root = insert(root, v);
	}
	if (bfs(root)) printf("\nYES");
	else printf("\nNO");
	return 0;
}
