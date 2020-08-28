#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int choice[maxn][205]; // choice[i][j]: ������Ӳ���ܼ�ֵΪ j ʱ���Ƿ�ѡȡӲ�� i
int coin[maxn];
int dp[205]; // dp[i]: �����ܼ�ֵΪ i ʱ������Ӳ�ҵ��ܼ�ֵ
int n, m;

bool cmp(int a, int b) {
    return a > b;
}

// 0-1 ���� ��̬�滮����
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    sort(coin, coin + n, cmp); // ����Ӵ�С�����������Ա�֤��ֵС��Ӳ�Һ����������Ը��� dp[j]
    for (int i = 0; i < n; i++) {
        // ���������Ż� һά 0-1 ������������������
        for (int j = m; j >= coin[i]; j--) {
            // ������С�� coin[i] �������� dp[j] == dp[j - coin[i]] + coin[i] �Ὣ֮ǰ��� coin[i] ����
            if (dp[j] <= dp[j - coin[i]] + coin[i]) {
                dp[j] = dp[j - coin[i]] + coin[i];
                choice[i][j] = 1; // ��Ǹ�Ӳ���ڸü�ֵ��ѡ�� ���յ� i һ�������з������������ i����Ϊ i ��С����ö�٣�
                // �� coin[i] һ���Ƿ�������µ���Сֵ
            }
        }
    }
    // ����������ܼ�ֵ��Ϊ m��˵���޽�
    if (dp[m] != m) {
        printf("No Solution");
        return 0;
    }
    vector<int> res;
    int i = n - 1;
    while (m > 0) {
        if (choice[i][m]) {
            res.push_back(coin[i]);
            m -= coin[i];
        }
        i--;
    }
    for (int i = 0; i < res.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}
