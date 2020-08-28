#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int color[202], stripe[maxn], dp[maxn];
// color: ÿ����ɫ�����λ��
int n, m, l;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int t;
        scanf("%d", &t);
        color[t] = i; // i ���� > 0������ѭ��Ҫ�� 1 ��ʼ
    }
    int cnt = 0;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int t;
        scanf("%d", &t);
        if (color[t]) {
            // ��������ɫ�Ǳ�ϲ������ɫ֮һ����ô�����λ�÷��� stripe
            // �����ɫ���Ǳ�ϲ������ɫ��ֱ�Ӻ��ӣ���Ϊ��Ŀ����������ѡ����ɫ��
            // ���� stripe ����ԭ stripe �����б�ϲ������ɫ�� color �е�λ��
            // ��Ϊ�����е����λ��Ҫ���� color ��ÿ����ɫ��λ��
            // ������Ŀת��Ϊ���� stripe ������½������еĳ���
            stripe[cnt++] = color[t];
        }
    }
    // ö���������յ��±�
    for (int i = 0; i < cnt; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (stripe[i] >= stripe[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    printf("%d\n", dp[cnt-1]);
    return 0;
}
