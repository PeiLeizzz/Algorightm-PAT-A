#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
	cin >> n;
	int n1 = n / 2, n2 = n - n1;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int s1 = 0, s2 = 0;
	for (int i = 0; i < n1; i++) {
		s1 += v[i];
	}
	for (int i = n1; i < n; i++) {
		s2 += v[i];
	}
	cout << abs(n1-n2) << " " << abs(s1-s2);
	return 0;
}
