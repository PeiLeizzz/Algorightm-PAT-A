#include <bits/stdc++.h>
using namespace std;
// ������һ�ֽⷨ������ÿ��A��������P��T�ĸ�������˾��Ƕ������A���������
const int MOD = 1000000007;

int main () {
	char ch;
	int lastP = 0, lastAP = 0;
	long long res = 0;
	while (scanf("%c", &ch) != EOF) {
		switch(ch) {
			case 'P': {
				lastP++;
				break;
			}
			case 'A': {
				lastAP += lastP;
				break;
			}
			case 'T': {
				res += lastAP;
				break;
			}
		}
	}
	printf("%d", res % MOD);
	return 0;
}
