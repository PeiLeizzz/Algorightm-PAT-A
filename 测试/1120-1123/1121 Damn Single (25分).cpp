#include <bits/stdc++.h>
using namespace std;
int n, m;
map<int, int> couples;
set<int> single;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int id1, id2;
		scanf("%d %d", &id1, &id2);
		couples[id1] = id2;
		couples[id2] = id1;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int id;
		scanf("%d", &id);
		single.insert(id);
	}
	for (auto id: single) {
		if (couples.find(id) != couples.end() && single.find(couples[id]) != single.end()) {
			single.erase(id);
			single.erase(couples[id]);
		}
	}
	cout << single.size() << endl;
	for (set<int>::iterator it = single.begin(); it != single.end(); it++) {
		if (it != single.begin()) cout << " ";
		printf("%05d", *it);
	}
	return 0;
}
