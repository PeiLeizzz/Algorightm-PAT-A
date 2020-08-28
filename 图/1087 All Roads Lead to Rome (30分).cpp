#include <bits/stdc++.h>
using namespace std;
const int maxn = 205, inf = 0x3fffffff;
map<string, int> nameId;
map<int, string> idName;
struct node {
	int id, dis;
	node(int _id, int _dis): id(_id), dis(_dis) {};
};
vector<node> g[maxn];
vector<int> pre[maxn], tmp, path;
int vis[maxn], dis[maxn], happy[maxn], maxhappy = 0, num = 0;
double maxavghappy = 0;
int n, k, st = 0;

void init() {
	fill(vis, vis + maxn, 0);
	fill(dis, dis + maxn, inf);
	string s1;
	scanf("%d %d ", &n, &k);
	cin >> s1;
	nameId[s1] = 0;
	idName[0] = s1;
	happy[0] = 0;
	for (int i = 1; i < n; i++) {
		string s;
		int h;
		cin >> s >> h;
		nameId[s] = i;
		idName[i] = s;
		happy[i] = h;
	}
	for (int i = 0; i < k; i++) {
		string s2;
		int d;
		cin >> s1 >> s2 >> d;
		g[nameId[s1]].push_back(node(nameId[s2], d));
		g[nameId[s2]].push_back(node(nameId[s1], d));
	}
}

void dijkstra() {
	dis[0] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1, minl = inf;
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] < minl) {
				minl = dis[j];
				u = j;
			}
		}
		if (u == -1) break;
		vis[u] = 1;
		for (int j = 0; j < g[u].size(); j++) {
			int v = g[u][j].id, d = g[u][j].dis;
			if (!vis[v] && dis[v] > dis[u] + d) {
				dis[v] = dis[u] + d;
				pre[v].clear();
				pre[v].push_back(u);
			}
			else if (!vis[v] && dis[v] == dis[u] + d) {
				pre[v].push_back(u);
			}
		}
	}
}

void dfs(int v) {
	if (v == 0) {
		num++;
		tmp.push_back(v);
		int sumhappy = 0, l = tmp.size();
		for (int i = 0; i < l; i++) {
			sumhappy += happy[tmp[i]];
		}
		double avg = sumhappy * 1.0 / (l - 1); // ×¢ÒâÊÇ³ýÒÔ l - 1
		if (sumhappy > maxhappy) {
			maxhappy = sumhappy;
			maxavghappy = avg;
			path = tmp;
		}
		else if (sumhappy == maxhappy && maxavghappy < avg) {
			maxavghappy = avg;
			path = tmp;
		}
		tmp.pop_back();
		return;
	}
	else {
		tmp.push_back(v);
		for (int i = 0; i < pre[v].size(); i++) {
			dfs(pre[v][i]);
		}
		tmp.pop_back();
	}
}

int main() {
	init();
	dijkstra();
	dfs(nameId["ROM"]);
	printf("%d %d %d %d\n", num, dis[nameId["ROM"]], maxhappy, (int)maxavghappy);
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << idName[path[i]];
		if (i > 0) printf("->");
	}
	return 0;
}
