#include <bits/stdc++.h>
using namespace std;
struct bign {
	int d[25], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};
char s[25];
int has[10];

bign doubleBign(bign& a) {
	bign b = bign();
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int temp = a.d[i] * 2 + carry;
		b.d[b.len++] = temp % 10;
		carry = temp / 10;
	}
	while (carry != 0) {
		b.d[b.len++] = carry % 10;
		carry /= 10;
	}
	return b;
}

bool isHas(bign& a, bign& b) {
	if (a.len != b.len) return false;
	for (int i = 0; i < b.len; i++) {
		has[b.d[i]]++;
	}
	for (int i = 0; i < a.len; i++) {
		has[a.d[i]]--;
		if (has[a.d[i]] < 0) return false;
	}
	return true;
}

int main() {
	memset(has, 0, sizeof(has));
	scanf("%s", s);
	bign a = bign();
	int l = strlen(s);
	for (int i = l-1; i >= 0; i--) {
		a.d[i] = s[l-i-1] - '0';
	}
	a.len = l;
	bign b = doubleBign(a);
	bool flag = isHas(a, b);
	if (flag) printf("Yes\n");
	else printf("No\n");
	for (int i = b.len-1; i >= 0; i--) {
		printf("%d", b.d[i]);
	}
	return 0;
}
