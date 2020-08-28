#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;
string s1, s2;
int main() {
	cin >> s1 >> s2;
	for (char c: s1) {
		if (c >= 'a' && c <= 'z') {
			c -= 32;
		}
		mp[c] = 1;
	}
	for (char c: s2) {
		if (c >= 'a' && c <= 'z') {
			c -= 32;
		}
		mp[c] = 2;
	}
	for (char c: s1) {
		if (c >= 'a' && c <= 'z') {
			c -= 32;
		}
		if (mp[c] == 1) {
			printf("%c", c);
			mp[c] = 2;
		}
	}
	return 0;
}
