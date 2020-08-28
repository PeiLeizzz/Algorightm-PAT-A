#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
vector<int> prime(maxn, 1);

void initPrime() {
	prime[0] = prime[1] = 0;
	for (ll i = 2; i < maxn; i++) {
		if (!prime[i]) continue;
		for (ll j = i * i; j < maxn; j += i) {
			prime[j] = 0;
		}
	}
}

int reverseToRadix(int n, int d) {
	string r = "";
	do {
		r.push_back((n % d) + '0');
		n /= d;
	} while (n > 0);
	for (int i = 0; i < r.size(); i++) {
		n = n * d + r[i] - '0';
	}
	return n;
}

int main() {
	initPrime();
	int n, d;
	while (scanf("%d", &n), n > 0) {
		scanf("%d", &d);
		if (!prime[n]) {
			printf("No\n");
			continue;
		}
		int r = reverseToRadix(n, d);
		if (!prime[r]) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
