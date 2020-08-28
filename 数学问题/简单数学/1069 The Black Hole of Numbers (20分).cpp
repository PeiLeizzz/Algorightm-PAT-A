#include <bits/stdc++.h>
using namespace std;

bool cmp(char c1, char c2) {
	return c1 > c2;
}

void fillArr(char s[], int n) {
	for (int i = 3; i >= 0; i--) {
		s[i] = n % 10 + '0';
		n /= 10;
	}
	s[4] = '\0';
}

int main() {
	int n;
	scanf("%d", &n);
	char s1[5], s2[5];
	fillArr(s1, n);
	strcpy(s2, s1);
	while (true) {
		sort(s1, s1 + 4, cmp);
		sort(s2, s2 + 4);
		int dif = atoi(s1) - atoi(s2);
		printf("%s - %s = %04d\n", s1, s2, dif);
		if (dif == 0 || dif == 6174) break;
		fillArr(s1, dif);
		strcpy(s2, s1);
	}
	return 0;
}
