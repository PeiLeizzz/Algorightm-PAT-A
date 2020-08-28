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
				add(1, t, t, -1);
				printf("%d\n", t);
			}
		}
		else if (str[1] == 'e') {
			if (s.empty()) printf("Invalid\n");
			else {
				int l = 1, r = maxn, p = (s.size() + 1) / 2;
				while (l < r) {
					int mid = (l + r) / 2;
					if (search(1, 1, mid) < p) l = mid + 1;
					else r = mid;
				}
				printf("%d\n", l);
			}
		}
		else {
			int t;
			scanf("%d", &t);
			s.push(t);
			add(1, t, t, 1);
		}
	}
	return 0;
}
