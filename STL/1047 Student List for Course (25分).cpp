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

// µ¹Ðò´æ´¢
string getName(int id) {
	string name = "";
	int i = 3;
	name.push_back('0' + id % 10);
	id /= 10;
	while (i-- >= 0) {
		name.push_back('A' + id % 26);
		id /= 26;
	}
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
			string s = getName(course[i][j]);
			for (int t = 3; t >= 0; t--) {
				printf("%c", s[t]);
			}
			printf("\n");
		}
	}
	return 0;
}
