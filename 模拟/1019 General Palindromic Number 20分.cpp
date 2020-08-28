#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n[], int len) {
	for (int i = 0; i < len / 2 + 1; i++) {
		if (n[i] != n[len-i-1]) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, b, res[40], i = 0;
	scanf("%d %d", &n, &b);
	do {
		res[i++] = n % b;
		n /= b;
	} while (n > 0);
	bool f = isPalindrome(res, i--);
	if (f) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	for (int j = i; j >= 0; j--) {
		printf("%d", res[j]);
		if (j > 0) {
			printf(" ");
		}
	}
	return 0;
}
