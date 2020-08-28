#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 40010;
const int cmaxn = 2510;
char names[maxn][5];
vector<int> course[cmaxn];

bool cmp(int a, int b) {
	return strcmp(names[a], names[b]) < 0;
}
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%s %d", names[i], &n);
		for (int j = 0; j < n; j++) {
			int c;
			scanf("%d", &c);
			course[c].push_back(i);
		}
	}
	for (int i = 1; i <= K; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int s: course[i]) {
			printf("%s\n", names[s]);
		}
	}
	return 0;
}
