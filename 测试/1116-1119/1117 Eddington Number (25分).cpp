#include <bits/stdc++.h>
// �ҳ�һ����e����������ִ��д���e�������ڵ���e��
using namespace std;
const int maxn = 10000005;
int dis[maxn], more[maxn]; // more[i]: �� i ����������
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int d;
		scanf("%d", &d);
		dis[d]++;
	}
	int e = 0;
	for (int i = maxn - 2; i >= 0; i--) {
		more[i] = more[i + 1] + dis[i + 1];
		if (more[i] >= i) { // ע���� >= ���� >
			e = i;
			break;
		}
	}
	printf("%d", e);
	/**
	��һ��˼·��
	bool cmp(int a, int b) {
		return a > b;
	}
	int d[100005];
	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}
	sort(d, d + n, cmp);
	int e = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] > e + 1) e++; // e ����� e ������ĸ���
		// ֮������ d[i] > e + 1 ��Ҫ��֤ e �� 1 ������������
		// �� d[i] ��Ȼ�Ǳ� e�����Ӻ� ���������Ȼ d[i] �����㶨�� e Ҳ�Ͳ�������
		// Ҳ�ʹ��� �� e ������� e ������ e + 1 �����Ҳֻ�� e �����������ս���� e
		else break;
	}
	**/
	return 0;
}
