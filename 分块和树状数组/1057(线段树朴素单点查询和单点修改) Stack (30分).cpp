#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
stack<int> s;
struct node {
	int sum, left, right, lazy;
} tree[maxn << 2];

// 建树
void build(int k, int l, int r) {
	tree[k].left = l;
	tree[k].right = r;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
}

// 单点修改
void add(int k, int x, int w) {
    if (tree[k].left == tree[k].right) {
        tree[k].sum += w;
        return;
    }
    int mid = (tree[k].left + tree[k].right) >> 1;
    if (x <= mid) add(k << 1, x, w); // 沿左子树走
    else add(k << 1 | 1, x, w); // 沿右子树走
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum; // 状态合并
}

// 二分递归实现的单点查询
int search(int k, int x) {
	if (tree[k].left == tree[k].right) return tree[k].left;
	if (tree[k << 1].sum >= x) return search(k << 1, x); // 沿左子树往下查询
	else return search(k << 1 | 1, x - tree[k << 1].sum);
    // 这里的 p - tree[k << 1].sum 是将左右子树割裂开来，左子树的 sum 已经全部加上
    // 还差 p - tree[k << 1].sum，需要在右子树中寻找这个剩余值（单点）
}

int main() {
	build(1, 1, maxn);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[15];
		scanf("%s", str);
		if (str[1] == 'o') {
			if (s.empty()) printf("Invalid\n");
			else {
				int t = s.top();
				s.pop();
				add(1, t, -1);
				printf("%d\n", t);
			}
		}
		else if (str[1] == 'e') {
			if (s.empty()) printf("Invalid\n");
			else {
				int l = 1, r = maxn, p = (s.size() + 1) / 2;
				int res = search(1, p);
				printf("%d\n", res);
			}
		}
		else {
			int t;
			scanf("%d", &t);
			s.push(t);
			add(1, t, 1);
		}
	}
	return 0;
}
