#include <bits/stdc++.h>
using namespace std;
vector<string> w = {"Yi", "Qian", "Bai", "Shi", "Wan", "Qian", "Bai", "Shi", ""};
vector<string> d = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main() {
	char n[12];
	scanf("%s", n);
	int len, f = 0;
	if (n[0] == '-') {
		printf("Fu ");
		f = 1;
	}
	int t = len = strlen(n); // 原本字符串n的长度
	len -= f; // 去除负号后的位数
	for (int i = f; i < t; i++) {
		if (n[i] == '0') {
			// 如果后一位不是0，并且i不是万位和最后一位，或者去掉负号后只有一位并且是0，则输出"ling"
			if ((n[i+1] != '0' && i != t - 5 && i != t - 1) || len == 1) {
				// 如果i不是第一位，输出一个空格
				if (i != f) {
					printf(" ");
				}
				cout << d[0];
			}
			// 如果i是万位
			else if (i == t - 5) {
				// 如果亿位到万位之间全是0，并且后一位（千位）不是0，则输出"ling"
				if (n[i-1] == '0' && n[i-2] == '0' && n[i-3] == '0' && n[i+1] != '0') {
					cout << " ling";
				}
				// 如果亿位到万位间存在非0位，则输出"Wan"
				else if (!(n[i-1] == '0' && n[i-2] == '0' && n[i-3] == '0')) {
					cout << " Wan";
				}
			}
		}
		else {
			if (i != f) {
				printf(" ");
			}
			// 这里是w[9-t+i]而不是w[9-len+i]
			// 如果不是最后一位，后面输出空格（因为最后一位的话w[9-t+i]是空串，导致末尾多出一个空格
			if (i != t - 1) {
				cout << d[n[i] - '0'] << " " << w[9 - t + i];
			}
			else {
				cout << d[n[i] - '0'];
			}
		}
	}
	return 0;
}
