#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m, k;
int g[maxn][maxn], in[maxn];
vector<int> res;
bool judge(vector<int>& tmp, int v) {
    if (tmp[v] > 0) return false;
    for (int i = 1; i <= n; i++) {
        if (g[v][i]) {
            tmp[i]--;
        }
    }
    return true;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int st, en;
        scanf("%d %d", &st, &en);
        g[st][en] = 1;
        in[en]++;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int flag = 0;
        vector<int> tmp(in, in + n + 1);
        for (int j = 1; j <= n; j++) {
            int v;
            scanf("%d", &v);
            if (!flag && !judge(tmp, v)) {
                res.push_back(i);
                flag = 1;
            }
        }
    }
    for (int i = 0; i < res.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", res[i]);
    }
    return 0;
}
