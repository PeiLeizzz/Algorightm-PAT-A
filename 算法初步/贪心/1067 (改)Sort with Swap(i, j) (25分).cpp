#include <bits/stdc++.h>
using namespace std;
map<int, int> a;

void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void check() {
	// 如果存在两个可以直接完美交换
	for (auto it = a.begin(); it != a.end(); it++) {
		int i = it->first, j = it->second;
		if (a[i] == j && a[j] == i) {
			a.erase(i);
			a.erase(j);
			return;
		}
	}
	// 如果存在一次交换可以使得下次完美
	int flag = 1, ii, jj, mm, nn;
	for (auto it = a.begin(); it != a.end(); it++) {
		int i = it->first, j = it->second;
		for (auto it2 = ++it; it2 != a.end(); it2++) {
			int m = it2->first, n = it2->second;
			if (j == m && a[a[n]] == i) {
				a[i] = n;
				a.erase(m);
				return;
			}
			else if (j == m && flag == 1) {
				flag = 0;
				ii = i;
				jj = j;
				mm = m;
				nn = n;
			}
		}
		it--;
	}
	// 如果只存在普通交换
	a[ii] = nn;
	a.erase(mm);
	return;
}

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
	int cnt = 0;
	while (a.size() > 0) {
		check();
		for (auto it = a.begin(); it != a.end(); it++) {
			printf("%d %d\n", it->first, it->second);
		}
		printf("\n");
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}


