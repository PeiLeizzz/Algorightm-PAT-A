#include <bits/stdc++.h>
using namespace std;
int k, n;
const int maxn = 1005;
int arr[maxn];
bool check(int x1, int y1, int x2, int y2) {
	if (y1 == y2) return false;
	if (abs(x1 - x2) == abs(y1 - y2)) return false;
	return true;
}

int main() {
	scanf("%d", &k);
	while (k--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		int flag = 1;
		for (int i = 2; i <= n; i++) {
			if (!flag) break;
			for (int j = i - 1; j >= 1; j--) {
				if (check(i, arr[i], j, arr[j]) == false) {
					flag = 0;
					break;
				}
			}
		}
		printf("%s\n", flag? "YES": "NO");
	}
	return 0;
}
