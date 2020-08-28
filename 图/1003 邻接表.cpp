#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXSIZE 502

struct edge {
    int to;
    int len;
};

int n, m, st, en;
bool visited[MAXSIZE] = {false};
int hands[MAXSIZE];
int weight[MAXSIZE] = {0};
int nums[MAXSIZE] = {0};
int paths[MAXSIZE];
vector<edge> G[MAXSIZE];

void init();
void dijkstra();

int main() {
    init();
    dijkstra();
    cout << nums[en] << " " << weight[en];
    return 0;
}

void init() {
    cin >> n >> m >> st >> en;
    fill(paths, paths + n, INF);
    for (int i = 0; i < n; i++) {
        cin >> hands[i];
    }
    for (int i = 0; i < m; i++) {
        edge c1, c2;
        cin >> c2.to >> c1.to >> c1.len;
        c2.len = c1.len;
        G[c2.to].push_back(c1);
        G[c1.to].push_back(c2);
        if (c2.to == st) {
            weight[c1.to] = hands[c2.to] + hands[c1.to];
            nums[c1.to] = 1;
            paths[c1.to] = c1.len;
        }
    }
    visited[st] = true;
    nums[st] = 1;
    paths[st] = 0;
    weight[st] = hands[st];
}

void dijkstra() {
    for (int i = 0; i < n; i++) {
        int u = -1;
        int minlen = INF;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && paths[j] < minlen) {
                u = j;
                minlen = paths[j];
            }
        }
        if (u == -1) {
            return;
        }
        visited[u] = true;
        for (int j = 0; j < G[u].size(); j++) {
            int v = G[u][j].to;
            int l = G[u][j].len;
            if (visited[v] == false) {
                if (l + paths[u] < paths[v]) {
                    paths[v] = l + paths[u];
                    nums[v] = nums[u];
                    weight[v] = weight[u] + hands[v];
                }
                else if (l + paths[u] == paths[v]) {
                    nums[v] += nums[u];
                    weight[v] = max(weight[v], weight[u] + hands[v]);
                }
            }
        }
    }
}
