#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
#define lowbit(i) ((i)&(-i))
struct node {
	int val, pos;
} tmp[maxn];
int a[maxn], c[maxn];

bool cmp(node n1, node n2) {
	return n1.val < n2.val;
}

void update(int x, int v) {
	for (int i = x; i <= n; i += lowbit(i)) {
		c[i] += v;
	}
}

int getSum(int x) {
	int sum = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		sum += c[i];
	}
	return sum;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v);
		tmp[i].val = v, tmp[i].pos = i;
	}
	sort(tmp, tmp + n, cmp);
	for (int i = 0; i < n; i++) {
		if (i == 0 || tmp[i].val != tmp[i-1].val) {
			a[tmp[i].pos] = i + 1;
		}
		else {
			a[tmp[i].pos] = a[tmp[i-1].pos];
		}
	}
	for (int i = 0; i < n; i++) {
		update(a[i], 1);
		printf("%d %d\n", getSum(a[i] - 1), a[i] - 1);
	}
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", getSum(a[i] - 1), a[i] - 1);
	}
	return 0;
}
