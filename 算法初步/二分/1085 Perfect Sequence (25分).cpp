#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> numble;
int main() {
	int n;
	ll p;
	scanf("%d %lld", &n, &p);
	for (int i = 0; i < n; i++) {
		ll a;
		scanf("%lld", &a);
		numble.push_back(a);
	}
	sort(numble.begin(), numble.end());
	int len = 1;
	for (int i = 0; i < n && i + len < n; i++) {
		int left = i + 1;
		int right = n;
		// 查找区间 [left, right]
		// right 取 n 的原因：可能整个序列都满足条件，那么left 最多可以到 n
		// 即 len = n 符合条件
		// 如果取 right = n - 1 需要单独判断 numble[n-1] > cmpNum
		ll cmpNum = numble[i] * p;
		// 寻找第一个 mid 使 numble[mid] > cmpNum
		while (left < right) {
			int mid = (left + right) / 2;
			if (numble[mid] > cmpNum) {
				// 区间：[left, mid]
				right = mid;
			}
			else {
				// 区间：[mid+1, right]
				left = mid + 1;
			}
		}
		len = max(len, left - i);
	}
	printf("%d", len);
	return 0;
}
