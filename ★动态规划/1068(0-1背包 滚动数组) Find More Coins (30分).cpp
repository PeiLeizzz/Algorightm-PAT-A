#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int choice[maxn][205]; // choice[i][j]: 背包内硬币总价值为 j 时，是否选取硬币 i
int coin[maxn];
int dp[205]; // dp[i]: 限制总价值为 i 时背包内硬币的总价值
int n, m;

bool cmp(int a, int b) {
    return a > b;
}

// 0-1 背包 动态规划做法
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    sort(coin, coin + n, cmp); // 必须从大到小排序，这样可以保证价值小的硬币后碰到，可以更新 dp[j]
    for (int i = 0; i < n; i++) {
        // 滚动数组优化 一维 0-1 背包必须从右向左滚动
        for (int j = m; j >= coin[i]; j--) {
            // 当遇见小的 coin[i] 并且满足 dp[j] == dp[j - coin[i]] + coin[i] 会将之前大的 coin[i] 覆盖
            if (dp[j] <= dp[j - coin[i]] + coin[i]) {
                dp[j] = dp[j - coin[i]] + coin[i];
                choice[i][j] = 1; // 标记该硬币在该价值被选择 最终的 i 一定是所有符合情况的最大的 i（因为 i 从小到大枚举）
                // 即 coin[i] 一定是符合情况下的最小值
            }
        }
    }
    // 如果背包中总价值不为 m，说明无解
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
