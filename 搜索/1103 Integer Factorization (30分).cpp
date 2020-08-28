#include <bits/stdc++.h>
using namespace std;
int N, K, P;
vector<int> res, tmp, power;
int maxv = 0;

void dfs(int n, int k, int t, int sum) {
	if (n < k || k < 0) return;
	// ����ö���ǴӴ�С�������ٴ����� sum == maxv ʱ���е��ֵ���һ��û��֮ǰ��
	else if (n == 0 && k == 0 && sum > maxv) {
		maxv = sum;
		res = tmp;
		return;
	}
	for (int i = t; i > 0; i--) {
		int p = power[i];
		if (p > n) continue;
		else if (p < n / k) break; // ֮������С��Ԫ�ر��� ���� p ���ϱ�С���߲��� ���õ�p*k<n Ҳ�޷�����
		tmp.push_back(i);
		dfs(n - p, k - 1, i, sum + i);
		tmp.pop_back();
	}
}

int main() {
	scanf("%d %d %d", &N, &K, &P);
	int t = 0;
	// ���
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
