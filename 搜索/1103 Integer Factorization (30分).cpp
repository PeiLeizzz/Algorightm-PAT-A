#include <bits/stdc++.h>
using namespace std;
int N, K, P;
vector<int> res, tmp, power;
int maxv = 0;

void dfs(int n, int k, int t, int sum) {
	if (n < k || k < 0) return;
	// 由于枚举是从大到小，所以再次遇到 sum == maxv 时序列的字典序一定没有之前大
	else if (n == 0 && k == 0 && sum > maxv) {
		maxv = sum;
		res = tmp;
		return;
	}
	for (int i = t; i > 0; i--) {
		int p = power[i];
		if (p > n) continue;
		else if (p < n / k) break; // 之后都是往小的元素遍历 所以 p 不断变小或者不变 最大得到p*k<n 也无法满足
		tmp.push_back(i);
		dfs(n - p, k - 1, i, sum + i);
		tmp.pop_back();
	}
}

int main() {
	scanf("%d %d %d", &N, &K, &P);
	int t = 0;
	// 打表
	while (1) {
		int p = pow(t, P);
		if (p > N) break;
		power.push_back(p);
		t++;
	}
	dfs(N, K, t-1, 0);
	if (res.size() == 0) printf("Impossible");
	else {
		printf("%d = %d^%d", N, res[0], P);
		for (int i = 1; i < res.size(); i++) {
			printf(" + %d^%d", res[i], P);
		}
	}
	return 0;
}
