#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int a[maxn], b[maxn];

int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
	}
	// 这点很重要，防止数组越界
	a[n] = b[m] = (1 << 30) - 1;
	int mid = (m + n - 1) / 2, cnt = 0;
	int i = 0, j = 0;
	while (cnt < mid) {
		if (a[i] < b[j]) i++;
		else j++;
		cnt++;
	}
	if (a[i] < b[j]) printf("%d", a[i]);
	else printf("%d", b[j]);
	return 0;
}
