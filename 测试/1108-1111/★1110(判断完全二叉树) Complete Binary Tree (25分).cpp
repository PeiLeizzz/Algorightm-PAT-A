#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int n, root, leave;
struct TreeNode {
	int left = -1, right = -1;
} node[maxn];

int father[maxn];

// Ҳ������ dfs �ҳ����һ���ڵ���±�ֵ��rootΪ0�����������ң� �����սڵ�����
// ������±�ֵ > Ԫ�ظ��� n ˵��ǰ���пսڵ� ������ȫ������
bool bfs(int root) {
	queue<pair<int, int>> q;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		int l = q.size();
		while (l--) {
			int tmp = q.front().first;
			int id = q.front().second;
			if (tmp == -1) { // �ڵ�Ϊ�գ�ֻ�е��ڵ��� >= n ��������ȫ������
				if (id < n) return false;
				else if (id == n) return true;
			}
			leave = tmp; // �������һ���ڵ�
			q.pop();
			q.push(make_pair(node[tmp].left, 2 * id + 1));
			q.push(make_pair(node[tmp].right, 2 * id + 2));
			
		}
	}
}
// ��һ�� bfs ˼·��������һ���ڵ�
// ���������ӣ���ǰ�����ĳ���ڵ����˶��ӣ��� flag1 = 1 ��� flag2 = 1�����û��������� flag1 = 1
// ������һ���ڵ�û���Ҷ���
// ��� flag1 = 1��� flag2 = 1�������� flag1 = 1
// ������Ҷ��ӣ���ǰ�����ĳ���ڵ����˶��ӣ��� flag1 = 1 ��� flag2 = 1�����û���Ҷ����� flag1 = 1
// ������˳�򣺴����ң�����ĳ���ڵ�����������Ҷ���Ҳ���Լ�����

// ��Ϊ��ȫ��������ĳ���ڵ�û�ж��ӣ�������������нڵ㶼û�ж���
/**
	if (node[tmp].left != -1) {
		if (f1 == 1) f2 = 1;
		q.push(node[tmp].left);
	}
	else {
		f1 = 1;
	}
	if (node[tmp].right != -1){
		if (f1 == 1) f2 = 1;
		q.push(node[tmp].right);
	}
	else {
		f1 = 1;
	}
**/

int main() {
	scanf("%d", &n);
	fill(father, father + n, -1);
	for (int i = 0; i < n; i++) {
		string s;
		int child;
		cin >> s;
		if (s[0] != '-') {
			child = atoi(s.c_str());
			node[i].left = child;
			father[child] = i;
		}
		cin >> s;
		if (s[0] != '-') {
			child = atoi(s.c_str());
			node[i].right = child;
			father[child] = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (father[i] == -1) {
			root = i;
			break;
		}
	}
	if (bfs(root)) {
		printf("YES %d", leave);
	}
	else {
		printf("NO %d", root);
	}
	return 0;
}
