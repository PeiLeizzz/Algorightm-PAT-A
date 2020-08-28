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
	// �Ҳ�������-1
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
		// ע�Ͳ�����ʹ��lower_bound����ʱ�����
		// j = lower_bound(coins + i + 1, coins + n, m - coins[i]) - coins;
		// if (coins[i] + coins[j] == m) {
			// �����lower_bound() ��ӡ����д������
			// ��������� 1 1 1 ������� No Solution
			// ���������ӡ�������� i = 0, j = 1������coins[j]Ĭ��ֵ��0������Ҳ��������
			// ��������Ļ� coins[i] < up �����㣬���Բ������ѭ����Ҳ�Ͳ����ӡ��
			// ������ lower_bound Ҳ�л���������Ҳ�����Ҳһ���᷵��һ������λ�ã���������Ϊ��-1
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
