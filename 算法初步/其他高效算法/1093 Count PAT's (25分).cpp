#include <bits/stdc++.h>
using namespace std;
// 本题另一种解法：计算每个A左右两边P和T的个数，相乘就是对于这个A的所有情况
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
