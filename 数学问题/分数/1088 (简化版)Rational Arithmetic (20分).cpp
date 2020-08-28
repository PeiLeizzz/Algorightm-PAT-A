#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	return !b? a: gcd(b, a % b);
}

void reduction(ll& up, ll& down) {
	if (down < 0) {
		down = -down;
		up = -up;
	}
	ll r = gcd(abs(up), down);
	up /= r;
	down /= r;
}

string handle(ll up, ll down) {
	reduction(up, down);
	string res = "";
	if (up < 0) res.push_back('(');
	if (down == 1) res += to_string(up);
	else if (abs(up) > down) {
		res += to_string(up / down);
		if (abs(up) % down) res += " " + to_string(abs(up) % down) + "/" + to_string(down);
	}
	else res += to_string(up) + "/" + to_string(down);
	if (up < 0) res.push_back(')');
	return res;
}

int main() {
	ll up1, down1, up2, down2;
	scanf("%lld/%lld %lld/%lld", &up1, &down1, &up2, &down2);
	cout << handle(up1, down1) << " + " << handle(up2, down2) << " = " << handle(up1*down2+up2*down1, down1*down2) << endl;
	cout << handle(up1, down1) << " - " << handle(up2, down2) << " = " << handle(up1*down2-up2*down1, down1*down2) << endl;
	cout << handle(up1, down1) << " * " << handle(up2, down2) << " = " << handle(up1*up2, down1*down2) << endl;
	cout << handle(up1, down1) << " / " << handle(up2, down2) << " = ";
	if (down1*up2 == 0) cout << "Inf" << endl;
	else cout << handle(up1*down2, down1*up2);
	return 0;
}
