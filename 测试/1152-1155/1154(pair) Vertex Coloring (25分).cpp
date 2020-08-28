#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
using namespace std;
const int maxn = 10005;
int N, M, K;
vector<pii> g;
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        g.pb(mp(v1, v2));
    }
    scanf("%d", &K);
    while (K--) {
        int col[maxn] = {0};
        set<int> s;
        for (int i = 0; i < N; i++) {
            scanf("%d", &col[i]);
            s.insert(col[i]);
        }
        int flag = 1;
        for (auto p: g) {
            if (col[p.first] == col[p.second]) {
                flag = 0;
                break;
            }
        }
        if (flag) printf("%d-coloring\n", s.size());
        else printf("No\n");
    }
}
