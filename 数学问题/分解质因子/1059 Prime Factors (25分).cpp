#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
typedef long long ll;
vector<int> prime(maxn, 1);

struct f {
	int x, cnt;
}fac[10];

void initPrime() {
	prime[0] = prime[1] = 1;
	for (ll i = 2; i < maxn; i++) {
		if (prime[i] == 1) {
			for (ll j = i * i; j < maxn; j += i) {
				prime[j] = 0;
			}
		}
	}
}

int main() {
	initPrime();
	int n;
	scanf("%d", &n);
	if (n == 1) {
		printf("1=1");
		return 0;
	}
	int t = 0, r = n;
	for (int i = 2; i <= sqrt(n); i++) {
		if (prime[i] == 1 && n % i == 0) {
			fac[t].x = i;
			fac[t].cnt = 1;
			n /= i;
			while (n % i == 0) {
				fac[t].cnt++;
				n /= i;
			}
			t++;
		}
		if (n == 1) break; // ¼ôÖ¦
	}
	if (n != 1) {
		fac[t].x = n;
		fac[t++].cnt = 1;
	}
	printf("%d=", r);
	for (int i = 0; i < t; i++) {
		if (i > 0) printf("*");
		printf("%d", fac[i].x);
		if (fac[i].cnt > 1) printf("^%d", fac[i].cnt);
	}
	return 0;
}
