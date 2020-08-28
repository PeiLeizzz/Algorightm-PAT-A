#include <bits/stdc++.h>
using namespace std;
const int maxv = 26 * 26 * 26;
struct node {
	int v, t;
	node(int _v, int _t) {
		v = _v;
		t = _t;
	}
};

int N, K;
int times[maxv] = {0}, visited[maxv] = {0};
vector<node> g[maxv];
map<int, int> mp;

int getId(char name[]) {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		res = res * 26 + name[i] - 'A';
	}
	return res;
}

char* getName(int id) {
	char* res = new char[4];
	for (int i = 2; i >= 0; i--) {
		res[i] = 'A' + id % 26;
		id /= 26;
	}
	res[3] = '\0';
	return res;
}

void dfs(int v, int& head, int& totalTime, int& totalPerson) {
	visited[v] = 1;
	if (times[v] > times[head]) {
		head = v;
	}
	for (int i = 0; i < g[v].size(); i++) {
		node target = g[v][i];
		totalTime += target.t;
		// 允许一个结点被多次访问，但是第二次访问时不再递归访问它
		if (!visited[target.v]) {
			totalPerson++;
			dfs(target.v, head, totalTime, totalPerson);
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	getchar();
	for (int i = 0; i < N; i++) {
		char n1[4], n2[4];
		int t;
		scanf("%s %s %d", n1, n2, &t);
		getchar();
		int id1 = getId(n1), id2 = getId(n2);
		// 构造有向图（有点问题，可能会漏边）
		g[id1].push_back(node(id2, t));
		times[id1] += t;
		times[id2] += t;
	}
	for (int i = 0; i < maxv; i++) {
		if (g[i].size() > 0 && !visited[i]) {
			int head = i, totalTime = 0, totalPerson = 1;
			dfs(i, head, totalTime, totalPerson);
			if (totalTime > K && totalPerson > 2) {
				mp[head] = totalPerson;
			}
		}
	}
	printf("%d\n", mp.size());
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		char* name = new char[4];
		name = getName(it->first);
		printf("%s %d\n", name, it->second);
		delete[] name;
	}
	return 0;
}
