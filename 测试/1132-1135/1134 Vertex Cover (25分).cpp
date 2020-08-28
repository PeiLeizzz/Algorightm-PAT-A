#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;
const int maxn = 10005;
int n, m, k;
vector<pii> g;
int ver[maxn];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        g.pb(mp(v1, v2));
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int nv;
        scanf("%d", &nv);
        memset(ver, 0, sizeof(ver));
        for (int j = 0; j < nv; j++) {
            int v;
            scanf("%d", &v);
            ver[v] = 1;
        }
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (ver[g[j].first] == 0 && ver[g[j].second] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
