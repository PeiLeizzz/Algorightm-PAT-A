#include <bits/stdc++.h>
using namespace std;
int m, n, S;
string str;
vector<string> res;
set<string> s;
int main() {
	scanf("%d %d %d", &m, &n, &S);
	for (int i = 1; i < S && i <= m; i++) {
		cin >> str;
	}
	int cnt = n;
	for (int i = 1; i <= m - S + 1; i++) {
		cin >> str;
		if (cnt == n) {
			if (s.find(str) != s.end()) continue;
			res.push_back(str);
			s.insert(str);
			cnt = 1;
		}
		else cnt++;
	}
	if (res.size() == 0) printf("Keep going...");
	else {
		for (string name: res) cout << name << endl;
	}
	return 0;
}
