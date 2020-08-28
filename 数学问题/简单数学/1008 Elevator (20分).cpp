#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n, last = 0;
	ll res = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int cur;
		scanf("%d", &cur);
		int dis = cur - last;
		if (dis > 0) {
			res += dis * 6 + 5;
		}
		else {
			dis = -dis;
			res += dis * 4 + 5;
		}
		last = cur;
	}
	printf("%lld", res);
	return 0;
}
