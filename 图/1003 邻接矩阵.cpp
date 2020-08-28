/** Dijkstra 最短路径算法[邻接矩阵版]
 * @param: n 城市的个数
 * @param: m 路径的个数
 * @param: st 起点城市的编号
 * @param: en 终点城市的编号
 * @param: hands[i] i城市拥有的救援人员的数量
 * @param: minDis[i] st城市到i城市的最短距离
 * @param: minPaths[i] st城市到i城市最短路径的个数
 * @param: paths[i][j] i城市到j城市的路径长度
 * @param: maxNums[i] st城市到i城市的最多救援人员个数
 * @param: visited[i] i城市是否已经被访问过
 * @method: init() 初始化各数组、邻接矩阵
 * @method: dijkstra() 求最短路径个数及最短路径情况下的最多救援人员数量
**/ 

#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 502
#define INF 0x3f3f3f3f

int n, m, st, en;
int hands[MAXSIZE];
int minDis[MAXSIZE];
int minPaths[MAXSIZE] = {0};
int paths[MAXSIZE][MAXSIZE];
int maxNums[MAXSIZE] = {0};
bool visited[MAXSIZE] = {false};

void init();
void dijkstra();

int main() {
    init();
    dijkstra();
    cout << minPaths[en] << " " << maxNums[en];
    return 0;
}

void init() {
    cin >> n >> m >> st >> en;
    fill(minDis, minDis + n, INF);
    fill(paths[0], paths[0] + MAXSIZE * MAXSIZE, INF);
    // memset(paths, 0x3f, sizeof(paths));
    for (int i = 0; i < n; i++) {
        cin >> hands[i];
    }
    for (int i = 0; i < m; i++) {
        int c1, c2, length;
        cin >> c1 >> c2 >> length;
        paths[c1][c2] = length;
        paths[c2][c1] = length;
        if (c1 == st) {
            minPaths[c2] = 1;
            minDis[c2] = length;
            maxNums[c2] = hands[c1] + hands[c2];
        }
    }
    // st->st的救援情况
    minDis[st] = 0;
    minPaths[st] = 1;
    visited[st] = true;
    maxNums[st] = hands[st];
}

void dijkstra() {
    for (int i = 0; i < n; i++) {
        int u = -1;
        int minLen = INF;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && minDis[j] < minLen) {
                u = j;
                minLen = minDis[j];
            }
        }
        if (u == -1) {
            return;
        }
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && paths[u][v] < INF) {
                if (minDis[v] > minDis[u] + paths[u][v]) {
                    minDis[v] = minDis[u] + paths[u][v];
                    maxNums[v] = maxNums[u] + hands[v];
                    minPaths[v] = minPaths[u];
                }
                else if (minDis[v] == minDis[u] + paths[u][v]) {
                    minPaths[v] += minPaths[u];
                    maxNums[v] = max(maxNums[v], maxNums[u] + hands[v]);
                }
            }
        }
    }
}