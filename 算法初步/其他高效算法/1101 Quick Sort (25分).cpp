#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn], leftA[maxn];

int main() {
	int n;
	scanf("%d", &n);
	int maxLeft = 0;
	for (int i = 0; i < n; i++) {
		leftA[i] = maxLeft;
		scanf("%d", &a[i]);
		maxLeft = max(maxLeft, a[i]);
	}
	int minRight = 1e9 + 7;
	vector<int> res;
	for (int i = n - 1; i >= 0; i--) {
		if (leftA[i] <= a[i] && minRight >= a[i]) {
			res.push_back(a[i]);
		}
		minRight = min(minRight, a[i]);
	}
	int m = res.size();
	printf("%d\n", m);
	for (int i = m - 1; i >= 0; i--) {
		printf("%d", res[i]);
		if (i > 0) printf(" ");
	}
	printf("\n");
	return 0;
}
