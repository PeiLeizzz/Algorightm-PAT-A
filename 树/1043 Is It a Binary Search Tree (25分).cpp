#include <stdio.h>
using namespace std;
const int maxn = 1005;
int N, pre[maxn], rpre[maxn], index = 0;
struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int v) {
		val = v;
		left = right = NULL;
	}
} *root = NULL, *rootMirror = NULL;

TreeNode* insert(TreeNode* node, int v) {
	if (node == NULL) {
		node = new TreeNode(v);
		return node;
	}
	if (v >= node->val) node->right = insert(node->right, v);
	else node->left = insert(node->left, v);
	return node;
}

TreeNode* insertMirror(TreeNode* node, int v) {
	if (node == NULL) {
		node = new TreeNode(v);
		return node;
	}
	// Ô­Ê÷ >= ÔÚÓÒ±ß ËùÒÔ¾µÏñÊ÷ >= ÔÚ×ó±ß
	if (v >= node->val) node->left = insertMirror(node->left, v);
	else node->right = insertMirror(node->right, v);
	return node;
}

void preOrder(TreeNode* node) {
	if (node == NULL) return;
	rpre[index++] = node->val;
	preOrder(node->left);
	preOrder(node->right);
}

void postOrder(TreeNode* node) {
	if (node == NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	if (index++ > 0) printf(" ");
	printf("%d", node->val);
}

bool isSame() {
	for (int i = 0; i < N; i++) {
		if (pre[i] != rpre[i]) return false;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		pre[i] = t;
		root = insert(root, t);
		rootMirror = insertMirror(rootMirror, t);
	}
	
	preOrder(root);
	for (int i = 0;  i< N; i++) {
		printf("%d ", rpre[i]);
	}
	printf("\n");
	
	int flag = 0;
	if (isSame()) flag = 1;
	index = 0;
	preOrder(rootMirror);
	
	for (int i = 0;  i< N; i++) {
		printf("%d ", rpre[i]);
	}
	printf("\n");
	
	if (!flag && isSame()) flag = 2;
	index = 0;
	
	switch(flag) {
		case 0: {
			printf("NO");
			break;
		}
		// ·Ç¾µÏñ
		case 1: {
			printf("YES\n");
			postOrder(root);
			break;
		}
		// ¾µÏñ
		case 2: {
			printf("YES\n");
			postOrder(rootMirror);
			break;
		}
	}
	return 0;
}
