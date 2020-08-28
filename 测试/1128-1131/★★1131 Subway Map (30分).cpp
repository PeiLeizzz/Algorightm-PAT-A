#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005, inf = 0x3fffffff;
int station[maxn], vis[maxn], dis[maxn], minSta = inf, minTra = inf; // station检查是否已经加入 allSta
vector<int> allSta, tmp; // allSta 保存所有站的 id；tmp 保存路径
vector<vector<int>> pre(maxn, vector<int>());
vector<int> g[maxn];
map<pair<int, int>, int> mp; // mp 保存 a->b 是哪条线路的
string res = "";
int n, m, k;

// 必须使用堆优化 否则超时
void dijkstra(int st, int en) {
	fill(vis, vis + maxn, 0);
	fill(dis, dis + maxn, inf);
	dis[st] = 0;
	int N = allSta.size();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(dis[st], st));
	while (!q.empty()) {
		int u = q.top().second, d = q.top().first;
		q.pop();
		if (u == en) break; // 剪枝
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (!vis[v] && dis[v] > d + 1) {
				dis[v] = d + 1;
				pre[v].clear();
				pre[v].push_back(u);
				q.push(make_pair(dis[v], v));
			}
			else if (!vis[v] && dis[v] == d + 1) {
				pre[v].push_back(u);
				// q.push(make_pair(dis[v], v)); 可有可无
			}
		}
	}
}

string to_str(int p) {
	string res = to_string(p);
	while (res.size() < 4) {
		res = "0" + res;
	}
	return res;
}

void dfs(int st, int v) {
	if (v == st) {
		tmp.push_back(v);
		int nSta = tmp.size() - 1;
		if (nSta > minSta) return;
		int cnt = 0;
		string str = "";
		int ps = tmp[tmp.size() - 1], ns, pl = 0, nl, start = ps; // start 记录上一条线路的起点
		for (int i = tmp.size() - 2; i >= 0; i--) {
			ns = tmp[i];
			nl = mp[make_pair(ps, ns)];
			if (pl != 0 && nl != pl) { // 说明换线路了
				cnt++;
				str += "Take Line#" + to_string(pl) + " from " + to_str(start) + " to " + to_str(ps) + ".\n";
				start = ps;
			}
			ps = ns;
			pl = nl;
		}
		str += "Take Line#" + to_string(pl) + " from " + to_str(start) + " to " + to_str(ps) + ".\n";
		if (nSta < minSta || (nSta == minSta && cnt < minTra))  {
			minTra = cnt;
			minSta = nSta;
			res = str;
		}
		tmp.pop_back();
		return;
	}
	tmp.push_back(v);
	for (int i = 0; i < pre[v].size(); i++) {
		dfs(st, pre[v][i]);
	}
	tmp.pop_back();
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		int p;
		for (int j = 1; j <= m; j++) {
			int sta;
			scanf("%d", &sta);
			if (station[sta] == 0) {
				allSta.push_back(sta);
				station[sta] = i;
			}
			if (j > 1) {
				g[p].push_back(sta);
				g[sta].push_back(p);
				mp[make_pair(p, sta)] = mp[make_pair(sta, p)] = i;
			}
			p = sta;
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int st, en;
		scanf("%d %d", &st, &en);
		pre.clear();
		tmp.clear();
		res = "";
		minSta = inf, minTra = inf;
		dijkstra(st, en);
		dfs(st, en);
		printf("%d\n", minSta);
		cout << res;
	}
	fclose(stdin);
	return 0;
}
