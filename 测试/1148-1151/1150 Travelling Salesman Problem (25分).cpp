#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, m, k, nv, minDis = INT_MAX, minId = -1;
int g[maxn][maxn];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v1, v2, d;
        scanf("%d %d %d", &v1, &v2, &d);
        g[v1][v2] = g[v2][v1] = d;
    }
	scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &nv);
        int path[maxn], vis[maxn];
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < nv; j++) {
            scanf("%d", &path[j]);
        }
        int flag = 0; // TS simple cycle
        if (path[0] != path[nv - 1]) flag = 1; // 头尾不同 Not a TS cycle
        else {
            int cnt = 0;
            for (int j = 0; j < nv; j++) {
                if (j != nv - 1 && vis[path[j]]) flag = 2; // 重复访问 TS cycle
                else if (!vis[path[j]]) cnt++; // 还是要写个条件，因为头尾允许相同
				vis[path[j]] = 1;
            }
            if (cnt != n) flag = 1; // 没有全部访问 Not a TS cycle
        }
        int dis = 0, past = path[0];
        for (int j = 1; j < nv; j++) {
            int now = path[j];
            if (g[past][now] == 0) {
                dis = -1;
				flag = 1; // 没有此路径 Not a TS cycle
                break;
            }
            else dis += g[past][now];
            past = now;
        }
        if (dis == -1) printf("Path %d: NA ", i);
        else {
            if (flag != 1 && dis < minDis) minDis = dis, minId = i;
            printf("Path %d: %d ", i, dis);
        }
        if (flag == 0) printf("(TS simple cycle)\n");
        else if (flag == 1) printf("(Not a TS cycle)\n");
        else printf("(TS cycle)\n");
    }
    printf("Shortest Dist(%d) = %d", minId, minDis);
    return 0;
}
