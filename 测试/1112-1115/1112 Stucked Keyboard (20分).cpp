#include <bits/stdc++.h>
using namespace std;
int k;
string str;
set<char> s;
int main() {
	cin >> k >> str;
	int cnt = 1;
	char p = str[0];
	s.insert(p);
	for (int i = 1; i < str.size(); i++) {
		s.insert(str[i]);
		if (str[i] == p) {
			cnt++;
		}
		else {
			if (cnt % k != 0) s.erase(p);
			cnt = 1;
		}
		p = str[i];
	}
	if (cnt % k != 0) s.erase(p);
	string res = "";
	for (int i = 0; i < str.size(); i++) {
		res.push_back(str[i]);
		if (s.find(str[i]) != s.end()) i += k - 1;
	}
	for (char ch: str) {
		if (s.find(ch) != s.end()) {
			cout << ch;
			s.erase(ch);
		}
	}
	cout << '\n' << res;
	return 0;
}
