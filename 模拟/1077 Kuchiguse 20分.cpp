#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string s;
	// 吸收换行符
	getchar();
	// s默认值设为第一个字符串
	getline(cin, s);
	n--;
	while (n--) {
		string str;
		getline(cin, str);
		int l1 = s.size();
		int l2 = str.size();
		int i = l1-1, j = l2-1;
		// 从后往前数相同后缀，跳出循环时i的位置就是相同后缀的第一个字符的位置
		while (i >= 0 && j >= 0) {
			if (s[i] != str[j]) {
				i++;
				break;
			}
			i--;
			j--;
		}
		if (i < 0) {
			i = 0;
		}
		s = s.substr(i, l1-i);
	}
	if (s.size() == 0) {
		printf("nai");
	}
	else {
		// 防止将相同的空格也一起加入了s
		if (s[0] == ' ') {
			cout << s.substr(1, s.size()-1);
		}
		else {
			cout << s;
		}
	}
	return 0;
}
