#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bign {
	int d[200], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

void initBign(bign& a, string& s) {
	int l = s.size();
	for (int i = l-1; i >= 0; i--) {
		a.d[i] = s[l-1-i] - '0';
	}
	a.len = l;
}

bool isPalindrome(bign& a) {
	int i = 0, j = a.len - 1;
	while (i < j) {
		if (a.d[i] != a.d[j]) return false;
		i++;
		j--;
	}
	return true;
}

bign addReverse(bign& a) {
	bign b = bign();
	for (int i = 0; i < a.len; i++) {
		b.d[i] = a.d[a.len-1-i];
	}
	b.len = a.len;
	bign c = bign();
	int carry = 0;
	for (int i = 0; i < a.len; i++) {
		int sum = a.d[i] + b.d[i] + carry;
		c.d[i] = sum % 10;
		carry = sum / 10;
	}
	c.len = a.len;
	if (carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

void print(bign& a) {
	for (int i = a.len-1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int main() {
	string s;
	int step;
	cin >> s >> step;
	bign a = bign();
	initBign(a, s);
	if (isPalindrome(a)) {
		print(a);
		printf("0");
		return 0;
	}
	for (int i = 1; i <= step; i++) {
  		a = addReverse(a);
		if (isPalindrome(a)) {
			print(a);
			printf("%d", i);
			return 0;
		}
	}
	print(a);
	printf("%d", step);
	return 0;
}
