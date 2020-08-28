#include <bits/stdc++.h>
using namespace std;

void output() {
	int n;
	string res = "";
	scanf("%d", &n);
	do {
		int r = n % 13;
		if (r >= 10) {
			res.push_back('A' + r - 10);
		}
		else {
			res.push_back(r + '0');
		}
		n /= 13;
	} while (n > 0);
	int len = res.size();
	if (len == 1) {
		// 不用cout输出string的方法
		char c[2];
		strcpy(c, res.c_str());
		printf("0%s", c);
	}
	else {
		printf("%c%c", res[1], res[0]);
	}
}

int main() {
	printf("#");
	for (int i = 0; i < 3; i++) {
		output();
	}
	return 0;
}
