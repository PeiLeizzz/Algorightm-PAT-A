#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> v1 = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> v2 = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> mp1, mp2;
int getNum(string s) {
	int n = 0;
	if (s.size() > 3) {
		n = mp2[s.substr(0, 3)] * 13;
		n += mp1[s.substr(4, 3)];
	}
	else {
		// 如果是 13 的倍数 长度也是 3 但是在 mp2 中
		if (mp2.count(s) != 0) {
			n = mp2[s] * 13;
		}
		else {
			n = mp1[s];
		}
	}
	return n;
}

string getStr(string s) {
	int n = atoi(s.c_str());
	if (n <= 12) {
		return v1[n];
	}
	else {
		// 13 的倍数不应输出个位的 tret
		string res = v2[n/13];
		if (n%13 != 0) res += " " + v1[n%13];
		return res;
	}
}

void init() {
	for (int i = 0; i < 13; i++) {
		mp1[v1[i]] = i;
		mp2[v2[i]] = i;
	}
}

int main() {
	init();
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		string s;
		// 整行读入 忽视空格
		getline(cin, s);
		if (s[0] >= 'a' && s[0] <= 'z') {
			printf("%d\n", getNum(s));
		}
		else {
			cout << getStr(s) << endl;
		}
	}
	return 0;
}
