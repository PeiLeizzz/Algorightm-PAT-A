#include <stdio.h>
#include <iostream>
#include <set>
#include <algorithm>
// 使用 STL 函数会超时
using namespace std;
const int smaxn = 52;
set<int> s[smaxn];
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
		set<int> s3;
		// 交集
		set_intersection(s[s1].begin(), s[s1].end(), s[s2].begin(), s[s2].end(), inserter(s3, s3.begin()));
		int n1 = s3.size();
		// 并集
		set_union(s[s1].begin(), s[s1].end(), s[s2].begin(), s[s2].end(), inserter(s3, s3.begin()));
		int n2 = s3.size();
		printf("%.1f%%\n", double(n1) / n2 * 100);
	}
	return 0;
}
