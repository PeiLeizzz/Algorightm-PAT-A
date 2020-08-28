#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, m;
int coin[maxn];

// ���� ��ʱ
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    sort(coin, coin + n);
	// 1 2 3 4 5 7 8 9
    int now = 0, vi = 0;
    vector<int> s;
    // ��� vi �ߵ�����󣬲��ұ����գ���ʱ���˳�
    while (!(vi == n && s.empty())) {
		while (now < m && vi < n) {
			if (now + coin[vi] <= m) {
				s.push_back(vi);
				now += coin[vi];
			}
			vi++;
		}
		if (now == m) {
			for (int i = 0; i < s.size(); i++) {
				if (i > 0) printf(" ");
				printf("%d", coin[s[i]]);
			}
			return 0;
		}
        // ���� ��ĩβȡ�� vi ��ĩβ��һ����ʼ��
        int t = s.back();
        vi = t + 1;
        now -= coin[t];
        s.pop_back();
    }
    printf("No Solution");
    return 0;
}
