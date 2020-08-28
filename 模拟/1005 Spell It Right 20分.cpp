#include <bits/stdc++.h>
using namespace std;
char a[105];
vector<string> digit = {"zero ", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
int main() {
	scanf("%s", a);
	int sum = 0;
	int len = strlen(a);
	for (int i = 0; i < len; i++) {
		sum += a[i] - '0';
	}
	
	vector<string> res;
	do {
		res.push_back(digit[sum % 10]);
		sum /= 10;
	} while (sum > 0);
	
	res[0].pop_back();
	for (vector<string>::reverse_iterator it = res.rbegin(); it != res.rend(); it++) {
		cout << *it;
	}
	return 0;
}
