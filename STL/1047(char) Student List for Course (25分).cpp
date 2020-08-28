#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
const int cmaxn = 2510;
vector<int> course[cmaxn];

int getId(char name[]) {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		res = res * 26 + name[i] - 'A';
	}
	res = res * 10 + name[3] - '0';
	return res;
}

// 倒序存储
char* getName(int id) {
	// 注意 new
	char* name = new char[5];
	int i = 3;
	name[i--] = '0' + id % 10;
	id /= 10;
	while (i >= 0) {
		name[i--] = 'A' + id % 26;
		id /= 26;
	}
	name[4] = '\0';
	return name;
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		char name[5];
		int n;
		scanf("%s %d", name, &n);
		for (int j = 0; j < n; j++) {
			int c;
			scanf("%d", &c);
			course[c].push_back(getId(name));
		}
	}
	for (int i = 1; i <= K; i++) {
		sort(course[i].begin(), course[i].end());
		printf("%d %d\n", i, course[i].size());
		for (int j = 0; j < course[i].size(); j++) {
			char* s = getName(course[i][j]);
			for (int t = 0; t < 4; t++) {
				printf("%c", s[t]);
			}
			// 注意 delete 数组的语法
			delete[] s;
			printf("\n");
		}
	}
	return 0;
}
