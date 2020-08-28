#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005; // 最大总人数
int N, K, num = 0;
int G[maxn][maxn] = {0}, visited[maxn] = {0}, times[maxn] = {0};
map<string, int> nameId, headCnt;
map<int, string> idName;

int getId(string name) {
	if (nameId.count(name)) return nameId[name];
	else {
		nameId[name] = num;
		idName[num] = name;
		return num++;
	}
}

void dfs(int v, int& head, int& totalTime, int& totalPerson) {
	visited[v] = 1;
	if (times[v] > times[head]) {
		head = v;
	}
	for (int i = 0; i < num; i++) {
		if (G[v][i] > 0) {
			totalTime += G[v][i];
			G[v][i] = G[i][v] = 0; // 删除这条路径
			if (!visited[i]) {
				totalPerson++;
				dfs(i, head, totalTime, totalPerson);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	getchar();
	for (int i = 0; i < N; i++) {
		string s1, s2;
		int t;
		cin >> s1 >> s2 >> t;
		int id1 = getId(s1), id2 = getId(s2);
		G[id1][id2] += t;
		G[id2][id1] += t;
		times[id1] += t;
		times[id2] += t;
	}
	for (int i = 0; i < num; i++) {
		if (!visited[i]) {
			int head = i, totalTime = 0, totalPerson = 1;
			dfs(i, head, totalTime, totalPerson);
			if (totalTime > K && totalPerson > 2) {
				headCnt[idName[head]] = totalPerson;
			}
		}
	}
	printf("%d\n", headCnt.size());
	for (map<string, int>::iterator it = headCnt.begin(); it != headCnt.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
	return 0;
}
