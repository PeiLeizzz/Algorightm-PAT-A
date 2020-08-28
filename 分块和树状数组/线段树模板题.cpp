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

// 下传
void push_down(int k) {
	if (tree[k].lazy != 0) {
		tree[k << 1].lazy += tree[k].lazy;
		tree[k << 1 | 1].lazy += tree[k].lazy;
		tree[k << 1].sum += tree[k].lazy * (tree[k << 1].right - tree[k << 1].left + 1);
		tree[k << 1 | 1].sum += tree[k].lazy * (tree[k << 1 | 1].right - tree[k << 1 | 1].left + 1);
		tree[k].lazy = 0;
	}
}

// 区间修改
void add(int k, int x, int y, int w) {
	if (tree[k].left >= x && tree[k].right <= y) {
		tree[k].sum += w * (tree[k].right - tree[k].left + 1);
		tree[k].lazy += w;
		return;
	}
	if (tree[k].right < x || tree[k].left > y) return;
	push_down(k);
	if (tree[k << 1].right >= x) add(k << 1, x, y, w);
	if (tree[k << 1 | 1].left <= y) add(k << 1 | 1, x, y, w);
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
}

// 区间查询
int search(int k, int x, int y) {
	if (tree[k].left >= x && tree[k].right <= y) {
		return tree[k].sum;
	}
	if (tree[k].right < x || tree[k].left > y) return 0;
	push_down(k);
	int res = 0;
	if (tree[k << 1].right >= x) res += search(k << 1, x, y);
	if (tree[k << 1 | 1].left <= y) res += search(k << 1 | 1, x, y);
	return res;
}

// 单点修改
void add(int k, int x, int w) {
    if (tree[k].left == tree[k].right) {
        tree[k].sum += w;
        return;
    }
    push_down(k);
    int mid = (tree[k].left + tree[k].right) >> 1;
    if (x <= mid) add(k << 1, x, w);
    else add(k << 1 | 1, x, w);
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
}

int search(int k, int x) {
    if (tree[k].left == tree[k].right) {
        return tree[k].sum;
    }
    push_down(k);
    int mid = (tree[k].left + tree[k].right) >> 1;
    if (x <= mid) return search(k << 1, x);
    else return search(k << 1 | 1, x);
}
