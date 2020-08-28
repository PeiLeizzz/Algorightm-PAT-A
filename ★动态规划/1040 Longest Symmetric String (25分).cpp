#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
string str;
int maxl = 1;
vector<vector<int>> dp(maxn, vector<int>(maxn, 0));
/**
״̬ת�Ʒ��̣����Ӵ� [i: j]
    1. i == j (len == 1) -> dp[i][j] = 1 �κ��ַ����ǻ��Ĵ�
    2. i == j-1 (len == 2) -> dp[i][j] = (str[i] == str[j]) ����Ϊ 2 ���ַ�����ֻҪ����������ַ��಻��ȼ���
    3. i < j-1 (len > 2) -> dp[i][j] = (str[i] == str[j] && dp[i+1][j-1]) ���ȴ��� 2 ���ַ�������Ҫ���ͷβ�಻����Լ�ȥ��ͷβ�Ƿ�Ϊ���Ĵ�
**/
int main() {
    getline(cin, str);
    int n = str.size();
    // ��ʼ״̬ dp[i][i] = 1 ˳�����һ�� dp[i-1][i]
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i > 1 && str[i-1] == str[i]) {
            dp[i-1][i] = 1;
            maxl = 2;
        }
    }
    // ����Ҫ�õ� dp[i][j]�����ȳ��� ����Ҫ�ȵõ� dp[i+1][j-1]�����ȶ̣�
    // ���Դ�С����ö���Ӵ����ȣ��Լ�ͷ���±�
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

