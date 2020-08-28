#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int coins[maxn];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coins[i]);
	}
	sort(coins, coins + n);
	int i = 0, j = n - 1;
	while (i < j) {
		int v1 = coins[i], v2 = coins[j];
		int sum = v1 + v2;
		if (sum == m) {
			printf("%d %d", v1, v2);
			return 0;
		}
		else if (sum < m) {
			i++;
		}
		else {
			j--;
		}
	}
	printf("No Solution");
	return 0;
}
