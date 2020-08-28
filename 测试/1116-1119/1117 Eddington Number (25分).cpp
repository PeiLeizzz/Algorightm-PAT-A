#include <bits/stdc++.h>
// 找出一个数e，满足该数字串中大于e的数大于等于e个
using namespace std;
const int maxn = 10000005;
int dis[maxn], more[maxn]; // more[i]: 比 i 距离大的天数
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		dis[d]++;
	}
	int e = 0;
	for (int i = maxn - 2; i >= 0; i--) {
		more[i] = more[i + 1] + dis[i + 1];
		if (more[i] >= i) { // 注意是 >= 不是 >
			e = i;
			break;
		}
	}
	printf("%d", e);
	/**
	另一种思路：
	bool cmp(int a, int b) {
		return a > b;
	}
	int d[100005];
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	sort(d, d + n, cmp);
	int e = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > e + 1) e++; // e 代表比 e 大的数的个数
		// 之所以是 d[i] > e + 1 是要保证 e 加 1 后仍满足条件
		// 即 d[i] 仍然是比 e（增加后） 大的数，不然 d[i] 不满足定义 e 也就不能增加
		// 也就代表 比 e 大的数有 e 个，比 e + 1 大的数也只有 e 个，所以最终结果是 e
		else break;
	}
	**/
	return 0;
}
