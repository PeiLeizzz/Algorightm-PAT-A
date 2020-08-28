#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
string str;
int maxl = 1;
vector<vector<int>> dp(maxn, vector<int>(maxn, 0));
/**
状态转移方程：设子串 [i: j]
    1. i == j (len == 1) -> dp[i][j] = 1 任何字符都是回文串
    2. i == j-1 (len == 2) -> dp[i][j] = (str[i] == str[j]) 长度为 2 的字符串，只要检查这两个字符相不相等即可
    3. i < j-1 (len > 2) -> dp[i][j] = (str[i] == str[j] && dp[i+1][j-1]) 长度大于 2 的字符串，需要检查头尾相不相等以及去除头尾是否为回文串
**/
int main() {
    getline(cin, str);
    int n = str.size();
    // 初始状态 dp[i][i] = 1 顺便计算一下 dp[i-1][i]
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i > 1 && str[i-1] == str[i]) {
            dp[i-1][i] = 1;
            maxl = 2;
        }
    }
    // 由于要得到 dp[i][j]（长度长） 必须要先得到 dp[i+1][j-1]（长度短）
    // 所以从小到大枚举子串长度，以及头的下标
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            dp[i][j] = (str[i] == str[j] && dp[i+1][j-1]);
            if (dp[i][j]) maxl = max(maxl, l);
        }
    }
    printf("%d", maxl);
    return 0;
}

