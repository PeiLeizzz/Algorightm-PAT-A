#include <bits/stdc++.h>
using namespace std;

struct student {
	char id[20];
	int in[3];
	int out[3];
}s[1001];

bool cmp1 (student s1, student s2) {
	if (s1.in[0] != s2.in[0]) {
		return s1.in[0] < s2.in[0];
	}
	else if (s1.in[1] != s2.in[1]) {
		return s1.in[1] < s2.in[1];
	}
	else {
		return s1.in[2] < s2.in[2];
	}
}

bool cmp2 (student s1, student s2) {
	if (s1.out[0] != s2.out[0]) {
		return s1.out[0] > s2.out[0];
	}
	else if (s1.out[1] != s2.out[1]) {
		return s1.out[1] > s2.out[1];
	}
	else {
		return s1.out[2] > s2.out[2];
	}
}

int main() {
	int m;
	scanf("%d", &m);
	getchar();
	for (int i = 0; i < m; i++) {
		scanf("%s %d:%d:%d %d:%d:%d", s[i].id, &s[i].in[0], &s[i].in[1], &s[i].in[2], &s[i].out[0], &s[i].out[1], &s[i].out[2]);
	}
	sort(s, s+m, cmp1);
	printf("%s ", s[0].id);
	sort(s, s+m, cmp2);
	printf("%s", s[0].id);
	return 0;
}
