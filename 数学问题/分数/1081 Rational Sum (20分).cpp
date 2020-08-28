#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
typedef long long ll;

struct rational {
	ll nu, de;
};

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

vector<rational> v(maxn);

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld/%lld", &v[i].nu, &v[i].de);
	}
	rational res = v[0];
	for (int i = 1; i < n; i++) {
		ll r = lcm(abs(res.de), v[i].de);
		res.nu = res.nu * (r / res.de) + v[i].nu * (r / v[i].de);
		// 最好在每次乘法后都约分，避免溢出
		res.de = r;
	}
	ll r = gcd(abs(res.nu), res.de);
	res.nu /= r;
	res.de /= r;
	// 此题没有分母为负数的情况，否则更加复杂
	if (res.nu < 0) {
		printf("-");
		res.nu = -res.nu;
	}
	ll integer = res.nu / res.de;
	res.nu %= res.de;
	if (res.nu == 0) {
		printf("%lld", integer);
	}
	else if (integer == 0) {
		printf("%lld/%lld", res.nu, res.de);
	}
	else {
		printf("%lld %lld/%lld", integer, res.nu, res.de);
	}
	return 0;
}
