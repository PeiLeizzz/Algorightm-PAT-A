#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> numble;
int main() {
	int n;
	ll p;
	scanf("%d %lld", &n, &p);
	for (int i = 0; i < n; i++) {
		ll a;
		scanf("%lld", &a);
		numble.push_back(a);
	}
	sort(numble.begin(), numble.end());
	int len = 1;
	for (int i = 0; i < n; i++) {
		// Ѱ�� [i+1, n]֮���һ������ p * numble[i]����������λ�ø� j
		int j = upper_bound(numble.begin() + i + 1, numble.end(), p * numble[i]) - numble.begin();
		len = max(len, j - i); // j - i ʵ������ j - 1 - i + 1 , ���һ����������������λ���� j - 1
	}
	printf("%d", len);
	return 0;
}
