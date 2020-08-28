#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		string str = to_string(d);
		int sum = 0;
		for (char ch: str) {
			sum += ch - '0';
		}
		s.insert(sum);
	}
	cout << s.size() << endl;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		if (it != s.begin()) cout << " ";
		cout << *it;
	}
	return 0;
}
