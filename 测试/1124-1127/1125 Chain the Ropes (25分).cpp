#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n;
double res = 0.0;
priority_queue<double, vector<double>, greater<double>> rope;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double d;
		scanf("%lf", &d);
		rope.push(d);
	}
	while (!rope.empty()) {
		if (rope.size() == 1) {
			res = rope.top();
			break;
		}
		double d1 = rope.top();
		rope.pop();
		double d2 = rope.top();
		rope.pop();
		rope.push((d1 + d2) / 2);
	}
	/** 更简便的方法
	sort(v.begin(), v.end());
	double len = v[0];
	for (int i = 1; i < n; i++) {
		len = (len + v[i]) / 2; // 每次选出两个最小的数取平均值一定也还是这个序列中的最小值
	}
	**/
	printf("%d", (int)res);
	return 0;
}
