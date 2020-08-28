#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 26 * 26 * 26 * 10;
vector<int> stu[maxn];

// ×Ö·û´® hash
int getId(char name[]) {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		res = res * 26 + name[i] - 'A';
	}
	res = res * 10 + name[3] - '0';
	return res;
}

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int id, n;
		scanf("%d %d", &id, &n);
		for (int j = 0; j < n; j++) {
			char name[5];
			scanf("%s", name);
			int stId = getId(name);
			stu[stId].push_back(id);
		}
	}
	for (int i = 0; i < N; i++) {
		char name[5];
		scanf("%s", name);
		int stId = getId(name);
		sort(stu[stId].begin(), stu[stId].end());
		printf("%s %d", name, stu[stId].size());
		for (int j = 0; j < stu[stId].size(); j++) {
			printf(" %d", stu[stId][j]);
		}
		printf("\n");
	}
	return 0;
}


