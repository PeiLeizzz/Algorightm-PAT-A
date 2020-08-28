#include <bits/stdc++.h>
using namespace std;

int diamonds[100005], n, m;
vector<pair<int, int>> res;
//   3   2   1   5   4   6   8   7   16   10   15   11   9   12   14   13
// 0 3   5   6  11  15  21  29  36   52   62   77   88   97  109  123  136

int binarySearch(int left, int right) {
	int a = diamonds[left];
	// [left, right] 找第一个位置使得 diamonds[mid] - a >= m
	while (left < right) {
		int mid = (left + right) / 2;
		if (diamonds[mid] - a >= m) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	scanf("%d %d", &n, &m);
	memset(diamonds, 0, sizeof(diamonds));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &diamonds[i]);
		// 这样的话，数组就是递增的了，可以使用二分查找
		diamonds[i] += diamonds[i-1];
	}
	// O(NlogN)
	int minPrice = 1e9;
	// 枚举左端点i，寻找符合条件的右端点j，则[i+1, j]即是所找区间
	for (int i = 0; i <= n; i++) {
		int j = binarySearch(i, n);
		// 下面的是使用内置函数 lower_bound()找第一个符合条件的位置
		// lower_bound(val):返回容器中第一个值【大于或等于】val的元素的iterator位置。
        // upper_bound(val): 返回容器中第一个值【大于】...的位置
		// int j = lower_bound(diamonds + i, diamonds + n, diamonds[i] + m) - diamonds;
		int t = diamonds[j] - diamonds[i];
		if (t < minPrice && t >= m) {
			minPrice = t;
			res.clear();
			res.push_back(make_pair(i+1, j));
		}
		else if (t == minPrice) {
			res.push_back(make_pair(i+1, j));
		}
	}
	for (vector<pair<int, int>>::iterator it = res.begin(); it != res.end(); it++) {
		printf("%d-%d\n", it->first, it->second);
	}
	return 0;
}
