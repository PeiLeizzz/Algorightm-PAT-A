#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
int n, in[maxn], post[maxn];
string res = "";
struct TreeNode {
	int val;
	TreeNode *left = NULL, *right = NULL;
	TreeNode(int v) {
		val = v;
	}
};

void create(TreeNode* &node, int il, int ir, int pl, int pr) {
	if (il > ir) return;
	int r = post[pr];
	int k = il;
	for (; k <= ir; k++) {
		if (in[k] == r) break;
	}
	int num = k - il;
	node = new TreeNode(r);
	create(node->left, il, k - 1, pl, pl + num - 1);
	create(node->right, k + 1, ir, pl + num, pr - 1);
}

void bfs(TreeNode* root) {
	deque<TreeNode*> q;
	q.push_back(root);
	int f = -1, cnt = 1;
	//交替 f 即队列和栈轮流 push 和 pop 头加头取、尾加尾取
	while (!q.empty()) {
		int l = q.size();
		TreeNode* tmp = NULL;
		while (l--) {
			if (f == 1) {
				tmp = q.front();
				q.pop_front();
				if (tmp->left) q.push_back(tmp->left);
				if (tmp->right) q.push_back(tmp->right);
				res += to_string(tmp->val) + " ";
			}
			else {
				tmp = q.back();
				q.pop_back();
				// 一定注意下面的左右顺序交换！！！！ 核心！！ 很容易出错！！
				if (tmp->right) q.push_front(tmp->right);
				if (tmp->left) q.push_front(tmp->left);
				res += to_string(tmp->val) + " ";
			}
		}
	  	cnt++;
		if (cnt == 2) {
			f = -f;
			cnt = 1;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	TreeNode* root = NULL;
	create(root, 0, n - 1, 0, n - 1);
	bfs(root);
	res.pop_back();
	cout << res << endl;
	fclose(stdin);
	return 0;
}
