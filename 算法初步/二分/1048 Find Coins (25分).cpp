#include <bits/stdc++.h>
using namespace std;
int coins[100005];

int binarySearch(int left, int right, int x) {
	// [left, right]
	while (left <= right) {
		int mid = (left + right) / 2;
		if (coins[mid] == x) {
			return mid;
		}
		else if (coins[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	// 找不到返回-1
	return -1;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coins[i]);
	}
 	int up = m / 2 + 1;
	sort(coins, coins + n);
	for (int i = 0; i < n && coins[i] < up; i++) {
		// 注释部分是使用lower_bound函数时的语句
		// j = lower_bound(coins + i + 1, coins + n, m - coins[i]) - coins;
		// if (coins[i] + coins[j] == m) {
			// 如果用lower_bound() 打印必须写在里面
			// 特殊情况： 1 1 1 必须输出 No Solution
			// 但是如果打印放在外面 i = 0, j = 1，由于coins[j]默认值是0，所以也符合条件
			// 放在里面的话 coins[i] < up 不满足，所以不会进入循环，也就不会打印了
			// 所以用 lower_bound 也有坏处，如果找不到它也一定会返回一个合理位置，而不像人为的-1
			// printf("%d %d", coins[i], coins[j]);
   			// return 0;
		// }
		int j = binarySearch(0, n - 1, m - coins[i]);
		if (j != -1 && j != i) {
			printf("%d %d", coins[i], coins[j]);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
