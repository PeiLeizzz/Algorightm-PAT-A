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
	// ��ʼres������Ϊ1����Ϊ�п����޷����������whileѭ��
	int i = 0, j = 0, res = 1;
	while (i + res < n && j < n) {
		while (j < n && numble[j] <= numble[i] * p) j++;
		res = max(res, j - i);
		i++;
	}
	printf("%d", res);
	return 0;
}
