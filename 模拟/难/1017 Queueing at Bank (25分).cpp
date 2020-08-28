#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005, maxw = 105;
int n, m;
struct person {
    int h, m, s, p, t;
    friend bool operator < (person p1, person p2) {
        return p1.t > p2.t;
    }
};
priority_queue<person> q;
priority_queue<int, vector<int>, greater<int>> window;

void print(priority_queue<person> q, priority_queue<int, vector<int>, greater<int>> window) {
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        printf("%02d:%02d:%02d %d\n", p.h, p.m, p.s, p.p);
    }
    while (!window.empty()) {
        auto w = window.top();
        window.pop();
        printf("%d\n", w);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        person p1;
        scanf("%02d:%02d:%02d %d", &p1.h, &p1.m, &p1.s, &p1.p);
        p1.t = p1.h * 3600 + p1.m * 60 + p1.s;
        if (p1.p > 60) p1.p = 60;
        q.push(p1);
    }
    int cnt = 0, st = 8 * 3600, en = 17 * 3600, wait = 0;
    for (int i = 0; i < m; i++) {
        window.push(st);
    }
    // while 循环不能加条件 window.top() <= en
    // 因为所有在 17:00:00 及之前来的人都要被服务
    // 即使他们等到了 17:00:00 之后，还是会服务
    // 如果加了条件意味着 只要窗口结束时间过了 17:00:00 一律不服务
    while (!q.empty() && q.top().t <= en) {
        //print(q, window);
        person p = q.top();
        int t = window.top();
        q.pop();
        window.pop();
        if (p.t < t) {
            wait += t - p.t;
            t += p.p * 60;
            window.push(t);
        }
        else {
            t = p.t + p.p * 60;
            window.push(t);
        }
        cnt++;
    }
    if (cnt == 0) printf("0.0\n");
    else printf("%.1f\n", wait / 60.0 / cnt);
    return 0;
}
