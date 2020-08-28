#include <bits/stdc++.h>
using namespace std;
char str[1001];
int main() {
	cin >> str;
	int len = strlen(str);
	int l1 = (len + 2) / 3;
	int l3 = len + 2 - 2 * l1;
	for (int i = 0; i < l1-1; i++) {
		printf("%c", str[i]);
		for (int j = 0; j < l3-2; j++) {
			printf(" ");
		}
		printf("%c\n", str[len-1-i]);
	}
	for (int i = l1-1; i < l1+l3-1; i++) {
		printf("%c", str[i]);
	}
	return 0;
}
