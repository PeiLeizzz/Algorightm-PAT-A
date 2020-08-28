#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<string, vector<int> > mp;
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int id, n;
		scanf("%d %d", &id, &n);
		for (int j = 0; j < n; j++) {
			char name[5];
			scanf("%s", name);
			string s = name;
			mp[s].push_back(id);
		}
	}
	for (int i = 0; i < N; i++) {
		char name[5];
		scanf("%s", name);
		string s = name;
		sort(mp[s].begin(), mp[s].end());
		printf("%s %d", name, mp[s].size());
		for (int j = 0; j < mp[s].size(); j++) {
			printf(" %d", mp[s][j]);
		}
		printf("\n");
	}
	return 0;
}

//// ×Ö·û´® hash
// vector<int> stu[26*26*26*10];
//int getId(char name[]) {
//	int res = 0;
//	for (int i = 0; i < 3; i++) {
//		res = res * 26 + name[i] - 'A';
//	}
//	res = res * 10 + name[3] - '0';
//	return res;
//}
