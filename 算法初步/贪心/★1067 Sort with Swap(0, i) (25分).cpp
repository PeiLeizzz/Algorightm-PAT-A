#include <bits/stdc++.h>
using namespace std;
map<int, int> a;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		if (k != i) {
			a[k] = i;
		}
	}
	
	int cnt = 0, t = a.size();
	// 设置循环条件 t > 0目的是为了当a本来就有序的情况下不进入循环
	while (t > 0) {
		if (a[0] != 0) {
			int b = a[0];
			a[0] = a[b];
			a.erase(b);
			// 删的只剩下 0 了，就完成了
			if (a.size() == 1) {
				cnt++;
				break;
			}
		}
		else if (a[0] == 0) {
			// 如果0在0位，就随便选一个不在本位的和它交换
			// 这里直接选择0后面那个（因为map有序）
			a[0] = (++a.begin())->second;
			a[(++a.begin())->first] = 0;
		}
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}


