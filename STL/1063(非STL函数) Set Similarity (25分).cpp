#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
const int smaxn = 52;
set<int> s[smaxn];

void compare(int s1, int s2) {
	int n1 = s[s1].size(), n2 = 0;
	for (set<int>::iterator it = s[s2].begin(); it != s[s2].end(); it++) {
		if (s[s1].find(*it) != s[s1].end()) n2++;
		else n1++;
	}
	printf("%.1f%%\n", double(n2) / n1 * 100);
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			s[i].insert(t);
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int s1, s2;
		scanf("%d %d", &s1, &s2);
		compare(s1, s2);
	}
	return 0;
}
