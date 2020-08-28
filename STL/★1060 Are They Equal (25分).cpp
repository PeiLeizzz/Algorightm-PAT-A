#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int n;
string handle(string s, int& e) {
	int k = 0; // s的下标移动
	// 去除前置 0 如 0040 00.003
	while (s.length() > 0 && s[0] == '0') s.erase(s.begin());
	// 说明是 <1 的小数 如 .333
	if (s[0] == '.') {
		s.erase(s.begin()); // 去除小数点
		// 去除小数点后的前置 0 如 .0053
		while (s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());
			e--; // 小数点后 0的个数 = 指数的相反数
		}
	}
	// 说明 >1 如 40 44.44
	else {
		while (k < s.length() && s[k] != '.') {
			k++;
			e++; // 小数点前非 0的个数 = 指数
		}
		// 说明存在小数点 去除小数点
		if (k < s.length()) {
			s.erase(s.begin() + k);
		}
	}
	// 去除前置 0 和小数点后为 0，说明原数字就是 0 如 0000 0.000 000.000
	if (s.length() == 0) {
		e = 0;
	}
	k = 0;
	string res = "";
	// 提取前处理后的 s 的 n 位，位数不够在末尾补 0
	while (k < n && k < s.length()) res += s[k++];
	while (k++ < n) res += '0';
	return res;
}

int main() {
	string s1, s2, s3, s4;
	int e1 = 0, e2 = 0;
	cin >> n >> s1 >> s2;
	s3 = handle(s1, e1);
	s4 = handle(s2, e2);
	if (s3 == s4 && e1 == e2) {
		cout << "YES 0." << s3 << "*10^" << e1;
	}
	else {
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2;
	}
	return 0;
}
