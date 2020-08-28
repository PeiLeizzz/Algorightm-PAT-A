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

// 单点查询
int search(int k, int x) {
    if (tree[k].left == tree[k].right) {
        return tree[k].left;
    }
    push_down(k);
    if (tree[k << 1].sum >= x) return search(k << 1, x);
    else return search(k << 1 | 1, x - tree[k << 1].sum);
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
