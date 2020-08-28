#include <stdio.h>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
map<string, int> mp;
string str;

bool check(char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int main() {
	getline(cin, str);
	string tmp = "", res = "";
	int cnt = 0;
	// 注意不能 i >= size 就退出循环，因为可能tmp中还存着最后一个单词 需要进行判断
	for (int i = 0; i < str.size() || tmp.size() > 0; i++) {
		if (i < str.size() && check(str[i])) {
			tmp.push_back(str[i]);
		}
		else if (tmp.size() > 0) {
			transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
			mp[tmp]++;
			if (mp[tmp] > cnt || (mp[tmp] == cnt && tmp < res)) {
				cnt = mp[tmp];
				res = tmp;
			}
			tmp = "";
		}
	}
	cout << res << " " << mp[res];
	return 0;
}
