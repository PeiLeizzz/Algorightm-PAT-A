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
	int t = len = strlen(n); // ԭ���ַ���n�ĳ���
	len -= f; // ȥ�����ź��λ��
	for (int i = f; i < t; i++) {
		if (n[i] == '0') {
			// �����һλ����0������i������λ�����һλ������ȥ�����ź�ֻ��һλ������0�������"ling"
			if ((n[i+1] != '0' && i != t - 5 && i != t - 1) || len == 1) {
				// ���i���ǵ�һλ�����һ���ո�
				if (i != f) {
					printf(" ");
				}
				cout << d[0];
			}
			// ���i����λ
			else if (i == t - 5) {
				// �����λ����λ֮��ȫ��0�����Һ�һλ��ǧλ������0�������"ling"
				if (n[i-1] == '0' && n[i-2] == '0' && n[i-3] == '0' && n[i+1] != '0') {
					cout << " ling";
				}
				// �����λ����λ����ڷ�0λ�������"Wan"
				else if (!(n[i-1] == '0' && n[i-2] == '0' && n[i-3] == '0')) {
					cout << " Wan";
				}
			}
		}
		else {
			if (i != f) {
				printf(" ");
			}
			// ������w[9-t+i]������w[9-len+i]
			// ����������һλ����������ո���Ϊ���һλ�Ļ�w[9-t+i]�ǿմ�������ĩβ���һ���ո�
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
