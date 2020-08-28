#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> numble;
int main() {
	int n;
	ll p;
	scanf("%d %lld", &n, &p);
	for (int i = 0; i < n; i++) {
		ll t;
		scanf("%lld", &t);
		numble.push_back(t);
	}
	sort(numble.begin(), numble.end());
	// 初始res必须设为1，因为有可能无法进入下面的while循环
	int i = 0, j = 0, res = 1;
	while (i + res < n && j < n) {
		while (j < n && numble[j] <= numble[i] * p) j++;
		res = max(res, j - i);
		i++;
	}
	printf("%d", res);
	return 0;
}
