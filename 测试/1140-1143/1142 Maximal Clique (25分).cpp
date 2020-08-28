#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int nv, ne, m, k;
int g[maxn][maxn];
int main() {
    scanf("%d %d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        g[v1][v2] = g[v2][v1] = 1;
    }
    scanf("%d", &m);
    while (m--) {
        int flag = 2;
        scanf("%d", &k);
        vector<int> tmp;
        set<int> s;
        for (int i = 0; i < k; i++) {
            int v;
            scanf("%d", &v);
            tmp.push_back(v);
            s.insert(v);
        }
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (g[tmp[i]][tmp[j]] == 0) {
                    flag = 0;
                    break;
                }
            }
        }
        if (!flag) {
            printf("Not a Clique\n");
            continue;
        }
        for (int i = 1; i <= nv; i++) {
			int cnt = 0;
            if (s.find(i) == s.end()) {
                for (int j = 0; j < k; j++) {
                    if (g[i][tmp[j]]) cnt++;
                }
            }
            if (cnt == k) { // 如果和 s 中每个顶点都有边相连，说明还可以扩充，则不满足 Maximal 定义
				flag = 1;
				break;
			}
        }
        if (flag == 1) printf("Not Maximal\n");
        else printf("Yes\n");
    }
    return 0;
}
