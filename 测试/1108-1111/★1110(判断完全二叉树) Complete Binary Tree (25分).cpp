#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
int n, root, leave;
struct TreeNode {
	int left = -1, right = -1;
} node[maxn];

int father[maxn];

// 也可以用 dfs 找出最后一个节点的下标值（root为0，依次向下找） 遇到空节点跳过
// 如果该下标值 > 元素个数 n 说明前面有空节点 不是完全二叉树
bool bfs(int root) {
	queue<pair<int, int>> q;
	q.push(make_pair(root, 0));
	while (!q.empty()) {
		int l = q.size();
		while (l--) {
			int tmp = q.front().first;
			int id = q.front().second;
			if (tmp == -1) { // 节点为空，只有当节点编号 >= n 才满足完全二叉树
				if (id < n) return false;
				else if (id == n) return true;
			}
			leave = tmp; // 保存最后一个节点
			q.pop();
			q.push(make_pair(node[tmp].left, 2 * id + 1));
			q.push(make_pair(node[tmp].right, 2 * id + 2));
			
		}
	}
}
// 另一种 bfs 思路，当遇到一个节点
// 如果有左儿子，且前面存在某个节点少了儿子，即 flag1 = 1 则记 flag2 = 1，如果没有左儿子令 flag1 = 1
// 当遇到一个节点没有右儿子
// 如果 flag1 = 1则记 flag2 = 1，否则令 flag1 = 1
// 如果有右儿子，且前面存在某个节点少了儿子，即 flag1 = 1 则记 flag2 = 1，如果没有右儿子令 flag1 = 1
// 检查儿子顺序：从左到右，这样某个节点无左儿子有右儿子也可以检查出来

// 因为完全二叉树：某个节点没有儿子，那它后面的所有节点都没有儿子
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
