// 这里只针对正数间的运算，负数的运算比较麻烦
#include <bits/stdc++.h>
using namespace std;
struct bign {
	int d[1000], len;
	bign() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
}a, b;
char s[1001];

void initBign(bign& a) {
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		a.d[len - i - 1] = s[i] - '0';
	}
	a.len = len;
}

void printBign(bign& a) {
	for (int i = a.len - 1; i >= 0; i--) {
		printf("%d", a.d[i]);
	}
	printf("\n");
}

int cmp(bign& a, bign& b) {
	if (a.len > b.len) return 1;
	else if (a.len < b.len) return -1;
	else {
		for (int i = a.len - 1; i >= 0; i--) {
			if (a.d[i] > b.d[i]) return 1;
			else if (a.d[i] < b.d[i]) return -1;
		}
	}
	return 0;
}

bign add(bign& a, bign& b) {
	bign c = bign();
	int temp = 0, len = max(a.len, b.len);
	for (int i = 0; i < a.len || i < b.len; i++) {
		int sum = a.d[i] + b.d[i] + temp;
		c.d[i] = sum % 10;
		temp = sum / 10;
	}
	// 增加高位
	if (temp != 0) c.d[len++] = temp;
	c.len = len;
	return c;
}

bign sub(bign& a, bign& b) {
	bign c = bign();
	for (int i = 0; i < a.len || i < b.len; i++) {
		if (a.d[i] < b.d[i]) {
			a.d[i+1]--;
			a.d[i] += 10;
		}
		c.d[c.len++] = a.d[i] - b.d[i];
	}
	// 去除高位的 0 但至少保留最后一位
	while (c.len-1 >= 1 && c.d[c.len-1] == 0) {
		c.len--;
	}
	return c;
}

// bign 和 int 的乘法
bign mul(bign& a, int b) {
	bign c = bign();
	int temp = 0;
	for (int i = 0; i < a.len; i++) {
		int m = a.d[i] * b + temp;
		c.d[c.len++] = m % 10;
		temp = m / 10; // 高位当作进位
	}
	while (temp != 0) {
		c.d[c.len++] = temp % 10;
		temp /= 10;
	}
	return c;
}

// bign 和 int 的除法
bign div(bign& a, int b, int r = 0) {
	bign c = bign();
	c.len = a.len;
	for (int i = a.len - 1; i >= 0; i--) {
		r = r * 10 + a.d[i];
		c.d[i] = r / b;
		r %= b;
	}
	while (c.len-1 >= 1 && c.d[c.len-1] == 0) {
		c.len--;
	}
	return c;
}

int main() {
	initBign(a);
	initBign(b);
	bign c = add(a, b);
	printBign(c);
	int cm = cmp(a, b);
	if (cm < 0) {
		bign tmp = a;
		a = b;
		b = tmp;
		printf("-");
	}
	c = sub(a, b);
	printBign(c);
	c = mul(b, 100);
	printBign(c);
	c = div(b, 100);
	printBign(c);
	return 0;
}
