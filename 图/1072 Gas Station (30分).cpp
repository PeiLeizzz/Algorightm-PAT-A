#include <bits/stdc++.h>
using namespace std;
int n, m, k, d;
const int maxn = 1050, inf = 0x3fffffff;
struct node {
	int id, dis;
	node(int _id, int _dis): id(_id), dis(_dis) {}
};
vector<node> g[maxn];
int dis[maxn], vis[maxn], resid = -1;
double maxlen = 0, minavglen = inf;

int getId(string s) {
	if (s[0] == 'G') return atoi(s.substr(1).c_str());
	else return atoi(s.c_str()) + m;
}

void init() {
	scanf("%d %d %d %d", &n, &m, &k, &d);
	// [1, m], [m+1, m+n]
	for (int i = 0; i < k; i++) {
		string s1, s2;
		int c1 = 0, c2 = 0, d;
		cin >> s1 >> s2 >> d;
		c1 = getId(s1), c2 = getId(s2);
		g[c1].push_back(node(c2, d));
		g[c2].push_back(node(c1, d));
	}
}

void dijkstra(int st) {
	fill(dis, dis + maxn, inf);
	fill(vis, vis + maxn, 0);
	dis[st] = 0;
	for (int i = 0; i < n + m; i++) {
		int u = -1, minl = inf;
		for (int j = 1; j <= n + m; j++) {
			if (!vis[j] && minl > dis[j]) {
				u = j;
				minl = dis[j];
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j].id, d = g[u][j].dis;
			if (!vis[v] && dis[v] > d + dis[u]) {
				dis[v] = d + dis[u];
			}
		}
	}
	
	double len = inf, avglen = 0;
	for (int i = m + 1; i <= n + m; i++) {
		if (dis[i] > d) return;
		else {
			len = min((int)len, dis[i]);
			avglen += dis[i];
		}
	}
	avglen = avglen / n;
	if (len > maxlen) {
		maxlen = len;
		minavglen = avglen;
		resid = st;
	}
	else if (len == maxlen && avglen < minavglen) {
		minavglen = avglen;
		resid = st;
	}
}

int main() {
	init();
	for (int i = 1; i <= m; i++) {
		dijkstra(i);
	}
	if (resid == -1) printf("No Solution");
	else printf("G%d\n%.1lf %.1lf", resid, maxlen, minavglen);
	return 0;
}
