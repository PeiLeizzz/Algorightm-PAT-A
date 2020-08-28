#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char ch[4] = {'+', '-', '*', '/'};
struct rational {
	ll up, down, in;
};
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
// »¯¼ò
rational sim(rational a) {
	if (a.down < 0) {
		a.up = -a.up;
		a.down = -a.down;
	}
	ll r = gcd(abs(a.up), a.down);
	a.up /= r;
	a.down /= r;
	if (abs(a.up) >= a.down) {
		a.in = abs(a.up) / a.down;
		if (a.up < 0) a.in = -a.in;
		a.up = abs(a.up) % a.down;
	}
	else {
		a.in = 0;
	}
	return a;
}
rational add(rational a, rational b) {
	rational res;
	res.up = a.up * b.down + b.up * a.down;
	res.down = a.down * b.down;
	return sim(res);
}
rational dif(rational a, rational b) {
	rational res;
	res.up = a.up * b.down - b.up * a.down;
	res.down = a.down * b.down;
	return sim(res);
}
rational pro(rational a, rational b) {
	rational res;
	res.up = a.up * b.up;
	res.down = a.down * b.down;
	return sim(res);
}
rational div(rational a, rational b) {
	rational res;
	res.up = a.up * b.down;
	res.down = a.down * b.up;
	return sim(res);
}
void printone(rational a) {
	if (a.in < 0 && a.up != 0) {
		printf("(%lld %lld/%lld)", a.in, a.up, a.down);
	}
	else if (a.in > 0 && a.up != 0) {
		printf("%lld %lld/%lld", a.in, a.up, a.down);
	}
	else if (a.in > 0 && a.up == 0) {
		printf("%lld", a.in);
	}
	else if (a.in < 0 && a.up == 0) {
		printf("(%lld)", a.in);
	}
	else if (a.in == 0 && a.up < 0) {
		printf("(%lld/%lld)", a.up, a.down);
	}
	else if (a.in == 0 && a.up > 0) {
		printf("%lld/%lld", a.up, a.down);
	}
	else if (a.in == 0 && a.up == 0) {
		printf("0");
	}
}
void print(rational a, rational b, rational res[], int n) {
	a = sim(a);
	b = sim(b);
	printone(a);
	printf(" %c ", ch[n]);
	printone(b);
	printf(" = ");
	printone(res[n]);
	printf("\n");
}
int main() {
	rational a, b, res[4];
	scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
	res[0] = add(a, b);
	res[1] = dif(a, b);
	res[2] = pro(a, b);
	for (int i = 0; i < 3; i++) {
		print(a, b, res, i);
	}
	if (b.up == 0) {
		a = sim(a);
		printone(a);
		printf(" / 0 = Inf\n");
	}
	else {
		res[3] = div(a, b);
		print(a, b, res, 3);
	}
	return 0;
}
