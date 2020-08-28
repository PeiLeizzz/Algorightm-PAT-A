#include <bits/stdc++.h>

using namespace std;
vector<string> vs;

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		vs.push_back(str);
	}
	sort(vs.begin(), vs.end(), cmp);
	string res = "";
	for (int i = 0; i < n; i++) {
		res += vs[i];
	}
	while (res.size() > 0 && res[0] == '0') {
		res.erase(0, 1);
	}
	if (res.size() == 0) {
		printf("0");
	}
	else {
		cout << res;
	}
	return 0;
}
