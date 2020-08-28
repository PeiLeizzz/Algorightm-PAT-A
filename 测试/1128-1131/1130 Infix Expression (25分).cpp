#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int n;
struct TreeNode {
	string str;
	int left, right;
	TreeNode() {}
	TreeNode(string s, int l, int r) {
		str = s, left = l, right = r;
	}
} node[maxn];
int father[maxn];
string res = "";

void inOrder(int root) {
	if (root == -1) return;
	int flag = 0;
	if (node[root].left != -1 || node[root].right != -1) {
		flag = 1;
		res.push_back('(');
	}
	inOrder(node[root].left);
	res += node[root].str;
	inOrder(node[root].right);
	if (flag) res.push_back(')');
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> node[i].str >> node[i].left >> node[i].right;
		father[node[i].left] = father[node[i].right] = 1;
	}
	int root = 1;
	for (; root <= n; root++) {
		if (father[root] == 0) break;
	}
	inOrder(root);
	if (res.size() > 2) { // ���ܱ��ʽ����һ�㣬res Ϊ�գ���ʱ��Ҫ�ж�һ��
		res = res.substr(1); // ȥ����λ�����һ������
		res.pop_back();
	}
	cout << res << endl;
	return 0;
}
