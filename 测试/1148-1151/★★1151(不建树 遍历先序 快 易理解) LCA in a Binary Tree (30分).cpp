#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int m, n, in[maxn], pre[maxn];
map<int, int> pos;

// 不建树做法
int LCA(int v, int u) {
    int pv = pos[v], pu = pos[u];
    for (int i = 0; i < n; i++) {
        int pi = pos[pre[i]];
        if ((pi >= pv && pi <= pu) || (pi <= pv && pi >= pu)) return pre[i];
    }
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < m; i++) {
        int v, u, f1 = 0, f2 = 0;
        scanf("%d %d", &v, &u);
        for (int i = 0; i < n; i++) {
            if (pre[i] == v) f1 = 1;
            if (pre[i] == u) f2 = 1;
        }
        if (!f1 && !f2) printf("ERROR: %d and %d are not found.\n", v, u);
        else if (!f1) printf("ERROR: %d is not found.\n", v);
        else if (!f2) printf("ERROR: %d is not found.\n", u);
        else {
            int lca = LCA(v, u); // 不建树做法
            if (lca == v) printf("%d is an ancestor of %d.\n", v, u);
            else if (lca == u) printf("%d is an ancestor of %d.\n", u, v);
            else printf("LCA of %d and %d is %d.\n", v, u, lca);
        }
    }
    return 0;
}
