#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005, inf = 0x3fffffff;
int n, m, k, q;
int cost[maxn], fin[maxn]; // 每个人的耗费时间，每个人的结束时间，则每个人的开始时间为 fin - cost
struct window {
    int first = 8 * 60; // 队列中第一个人的完成时间
    int last = first; // 队列中最后一个人的完成时间，用于更新 finish[]
    queue<int> q;
} w[25];

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &cost[i]);
    }
    int id = 1;
    // 第一批入队
    for (int i = 1; i <= min(n * m, k); i++) {
        int wid = (id - 1) % n + 1;
        if (id <= n) w[wid].first += cost[id];
        w[wid].last += cost[id];
        w[wid].q.push(id);
        fin[id] = w[wid].last;
        id++;
    }
    while (id <= k) {
        // 找出所有窗口中将第一个少人的那个窗口
        int earlist = inf, eid = -1;
        for (int i = 1; i <= n; i++) {
            if (w[i].first < earlist) {
                earlist = w[i].first;
                eid = i;
            }
        }
        w[eid].q.pop();
        w[eid].q.push(id);
        w[eid].first += cost[w[eid].q.front()];
        w[eid].last += cost[id];
        fin[id] = w[eid].last;
        id++;
    }
    for (int i = 1; i <= q; i++) {
		int id;
		scanf("%d", &id);
        if (fin[id] - cost[id] >= 17 * 60) printf("Sorry\n");
        else printf("%02d:%02d\n", fin[id] / 60, fin[id] % 60);
    }
    return 0;
}
