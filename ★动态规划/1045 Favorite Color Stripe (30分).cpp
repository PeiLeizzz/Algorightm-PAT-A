#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int color[202], stripe[maxn], dp[maxn];
// color: 每种颜色的相对位置
int n, m, l;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int t;
        scanf("%d", &t);
        color[t] = i; // i 必须 > 0，所以循环要从 1 开始
    }
    int cnt = 0;
    scanf("%d", &l);
    for (int i = 0; i < l; i++) {
        int t;
        scanf("%d", &t);
        if (color[t]) {
            // 如果这个颜色是被喜爱的颜色之一，那么将其的位置放入 stripe
            // 这个颜色不是被喜爱的颜色，直接忽视（因为题目允许跳过来选择颜色）
            // 所以 stripe 就是原 stripe 中所有被喜爱的颜色在 color 中的位置
            // 因为子序列的相对位置要符合 color 中每个颜色的位置
            // 所以题目转化为：求 stripe 中最长不下降子序列的长度
            stripe[cnt++] = color[t];
        }
    }
    // 枚举子序列终点下标
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
