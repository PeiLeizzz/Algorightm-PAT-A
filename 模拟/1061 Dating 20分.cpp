#include <bits/stdc++.h>
using namespace std;
vector<string> week = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main() {
	string a, b;
	char c1, c2;
	cin >> a >> b;
	int len = min(a.size(), b.size());
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] == b[i]) {
			// 注意这里a[i]的上界不是'Z'，一周最多只有七天
			if (cnt == 0 && a[i] >= 'A' && a[i] <= 'G') {
				c1 = a[i];
				cnt++;
				continue;
			}
			if (cnt == 1 && ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'N'))) {
				c2 = a[i];
				break;
			}
		}
	}
	cout << week[c1-'A'];
	if (c2 >= '0' && c2 <= '9') {
		printf(" %02d:", c2-'0');
	}
	else {
		printf(" %02d:", c2-'A'+10);
	}
	cin >> a >> b;
	len = min(a.size(), b.size());
	int n1;
	for (int i = 0; i < len; i++) {
		if (((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z')) && a[i] == b[i]) {
			n1 = i;
			break;
		}
	}
	printf("%02d", n1);
	return 0;
}
