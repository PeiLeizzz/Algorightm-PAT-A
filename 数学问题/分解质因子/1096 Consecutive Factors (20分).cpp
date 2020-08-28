#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);
	ll s = (ll)sqrt(1.0 * n), len = 0, first = 0;
	for (ll i = 2; i <= s; i++) {
		ll tmp = 1, j = i;
		while (true) {
			tmp *= j;
			if (n % tmp != 0) break;
			if (j - i + 1 > len) {
				len = j - i + 1;
				first = i;
			}
			j++;
		}
	}
	if (len == 0) {
		printf("1\n%lld", n);
	}
	else {
		printf("%d\n", len);
		for (ll i = first; i < first + len; i++) {
			if (i > first) printf("*");
			printf("%lld", i);
		}
	}
	return 0;
}
