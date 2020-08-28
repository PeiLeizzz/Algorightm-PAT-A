#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, res = 0, a = 1;
	int left, right, now;
	scanf("%d", &n);
	while (n / a) {
		left = n / (a * 10);
		now = n / a % 10;
		right = n % a;
		if (now == 0) res += left * a;
		else if (now == 1) res += left * a + right + 1;
		else res += (left + 1) * a;
		a *= 10;
	}
	printf("%d", res);
	return 0;
}
