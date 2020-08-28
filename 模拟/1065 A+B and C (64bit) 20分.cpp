#include <bits/stdc++.h>
using namespace std;

int main() {
	long long a, b, c;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		long long res = a + b;
		bool flag;
		if (a > 0 && b > 0 && res < 0) {
			flag = true;
		}
		else if (a < 0 && b < 0 && res >= 0) {
			flag = false;
		}
		else if (res > c) {
			flag = true;
		}
		else {
			flag = false;
		}
		if (flag) {
			printf("Case #%d: true\n", i);
		}
		else {
			printf("Case #%d: false\n", i);
		}
	}
	return 0;
}
