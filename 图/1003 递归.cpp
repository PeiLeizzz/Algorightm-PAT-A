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
int paths[MAXSIZE];
int nums = 0, maxHands, temp;
// ���ڽӱ�洢��ռ�ÿռ�С
vector<edge> G[MAXSIZE];
vector<int> pre[MAXSIZE];

void init();
void dijkstra();
void dfs(int v);

int main() {
	freopen("in.txt", "r", stdin);
    init();
    dijkstra();
	dfs(en);
    cout << nums << " " << maxHands;
    fclose(stdin);
    return 0;
}

void init() {
    cin >> n >> m >> st >> en;
    fill(paths, paths + n, INF);
    for (int i = 0; i < n; i++) {
        cin >> hands[i];
    }
//    for (int i = 0; i < n; i++) {
//        pre[i].push_back(i);
//    }
// ����Ĵ�����Բ��ܼӣ��ᵼ��dfs�޷��˳�ѭ������Ϊdfs�ݹ�ʱ��pre[v][i] = i �� i != st ʱ��������ѭ����
	pre[st].push_back(st);
    for (int i = 0; i < m; i++) {
        edge c1, c2;
        cin >> c2.to >> c1.to >> c1.len;
        c2.len = c1.len;
        G[c2.to].push_back(c1);
        G[c1.to].push_back(c2);
        if (c2.to == st) {
            paths[c1.to] = c1.len;
            pre[c1.to].push_back(c2.to);
        }
    }
    visited[st] = true;
    paths[st] = 0;
    temp = maxHands = hands[en];
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
            if (visited[v] == false && l < INF) {
                if (l + paths[u] < paths[v]) {
                    paths[v] = l + paths[u];
                    // ע��Ҫ��clear()
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (l + paths[u] == paths[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void dfs(int v) {
    if (v == st) {
    	nums++;
		maxHands = max(maxHands, temp);
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
    	// ����
    	temp += hands[pre[v][i]];
        dfs(pre[v][i]);
        temp -= hands[pre[v][i]];
    }
    return;
}
