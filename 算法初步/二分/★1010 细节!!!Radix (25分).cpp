#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 序列不变，进制越高，它的十进制值就越大（单调递增）

ll switchRadix(char s[], ll radix) {
	ll n = 0;
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		char ch = s[i];
		if (ch >= 'a' && ch <= 'z') {
			n = n * radix + ch - 'a' + 10;
		}
		else {
			n = n * radix + ch - '0';
		}
	}
	return n;
}

// 二分查找 找到但不退出循环版本：
ll binarySearch(ll left, ll right, ll n1, char s2[]) {
	// 查找区间 [left, right]
	// 查找最小的 mid 进制，使得 n2 == n1
	// 即查找第一个 mid，使得 n2 >= n1
	while (left < right) {
		ll mid = (left + right) / 2;
		ll n2 = switchRadix(s2, mid);
		// 最最最核心的一个地方 一定要判断 n2 是否小于 0，因为如果进制很大的话，ll 也会溢出
		// 题目隐含保证了 n1 的十进制数一定小于 ll的范围，所以如果 n2 小于 0的话，肯定比 n1 大了！！
		if (n2 < 0 || n2 >= n1) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	// 最后还需要判断一下 此时的left位置满不满足
	ll n2 = switchRadix(s2, left);
	if (n2 != n1) return -1;
	return left;
}

// 由于n2关于radix是单调递增函数，所以不存在同时两个radix满足使得n2 == n1
// 因此 二分查找的函数 可以改写为：一旦找到就退出循环：
ll binarySearch2(ll left, ll right, ll n1, char s2[]) {
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll n2 = switchRadix(s2, mid);
		if (n2 < 0 || n2 > n1) {
			// n2 > n1 区间变为 [left, mid-1]
			right = mid - 1;
		}
		else if (n2 < n1) {
			// n2 < n1 区间变为 [mid+1, right]
			left = mid + 1;
		}
		else {
			// 找到 直接返回
			return mid;
		}
	}
	// 找不到 返回 -1
	return -1;
}

int main() {
	char s1[15], s2[15];
	int tag, radix;
	scanf("%s %s %d %d", s1, s2, &tag, &radix);
	// 交换 s1 和 s2 保证 radix 始终是 s1 的进制
	if (tag == 2) {
		char tmp[15];
		strcpy(tmp, s1);
		strcpy(s1, s2);
		strcpy(s2, tmp);
	}
	int l1 = strlen(s1), l2 = strlen(s2);
	// 将 s1 转为 10 进制
	ll n1 = switchRadix(s1, radix);
	char mc = '0';
	for (int i = 0; i < l2; i++) {
		if (s2[i] > mc) {
			mc = s2[i];
		}
	}
	// left 表示比 s2 中最大数多 1 的进制数
	ll left = (mc >= 'a' && mc <= 'z')? mc - 'a' + 11: mc - '0' + 1;
	// 注意这里 right 的选值！！
	ll right = max(left, n1) + 1;
	ll res = binarySearch(left, right, n1, s2);
	if (res == -1) printf("Impossible");
	else printf("%lld", res);
	return 0;
}
