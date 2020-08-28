#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005, inf = 0x3fffffff;
int n, m, k, q;
int cost[maxn], fin[maxn]; // ÿ���˵ĺķ�ʱ�䣬ÿ���˵Ľ���ʱ�䣬��ÿ���˵Ŀ�ʼʱ��Ϊ fin - cost
struct window {
    int first = 8 * 60; // �����е�һ���˵����ʱ��
    int last = first; // ���������һ���˵����ʱ�䣬���ڸ��� finish[]
    queue<int> q;
} w[25];

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &cost[i]);
    }
    int id = 1;
    // ��һ�����
    for (int i = 1; i <= min(n * m, k); i++) {
        int wid = (id - 1) % n + 1;
        if (id <= n) w[wid].first += cost[id];
        w[wid].last += cost[id];
        w[wid].q.push(id);
        fin[id] = w[wid].last;
        id++;
    }
    while (id <= k) {
        // �ҳ����д����н���һ�����˵��Ǹ�����
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
