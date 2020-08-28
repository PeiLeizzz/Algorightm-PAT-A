#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m, k;
map<int, vector<int>> mp;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        mp[v1].push_back(v2);
        mp[v2].push_back(v1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &k);
        int vis[maxn] = {0}, g[1005]; // vis 一定要初始化！
        for (int j = 0; j < k; j++) {
            scanf("%d", &g[j]);
            vis[g[j]] = 1;
        }
        int flag = 0;
        for (int j = 0; j < k; j++) {
            int t = g[j];
            for (auto x: mp[t]) {
                if (vis[x] == 1) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        printf("%s\n", flag? "No": "Yes");
    }
    return 0;
}
