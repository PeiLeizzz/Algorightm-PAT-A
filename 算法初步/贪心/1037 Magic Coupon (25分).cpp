#include <bits/stdc++.h>
using namespace std;

long long Nc[100005], Np[100005];

int main() {
	int c, p;
	scanf("%d", &c);
	for (int i = 0; i < c; i++) {
		scanf("%lld", &Nc[i]);
	}
	scanf("%d", &p);
	for (int i = 0; i < p; i++) {
		scanf("%lld", &Np[i]);
	}
	long long res = 0;
	sort(Nc, Nc + c);
	sort(Np, Np + p);
	for (int i = 0; i < c && i < p && Nc[i] < 0 && Np[i] < 0; i++) {
		res += Nc[i] * Np[i];
	}
	for (int i = c - 1, j = p - 1; i >= 0 && j >= 0 && Nc[i] > 0 && Np[j] > 0; i--, j--) {
		res += Nc[i] * Np[j];
	}
	printf("%lld", res);
	return 0;
}
