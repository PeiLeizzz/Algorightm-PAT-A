#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	a += b;
	if (a < 0) {
		printf("-");
		a = -a;
	}
	string res = to_string(a);
	int len = res.size();
	for (int i = 0; i < len; i++) {
		// len - i代表还剩下几个数字
		if (i != 0 && (len - i) % 3 == 0) {
			printf(",");
		}
		printf("%c", res[i]);
	}
	return 0;
}
