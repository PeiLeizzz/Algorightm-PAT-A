#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
struct node {
	int id, dis;
	node(int _id, int _dis): id(_id), dis(_dis) {}
};

bool topologicalSort(vector<vector<node>>& g, int ve[], stack<int>& s, int in[], int& start, int& x) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		s.push(u);
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].id, d = g[u][i].dis;
			in[v]--;
			if (in[v] == 0) {
				q.push(v);
			}
			if (ve[v] < ve[u] + d) {
				ve[v] = ve[u] + d;
			}
		}
	}
	if (s.size() == x) return true;
	return false;
}

void criticalPath(vector<vector<node>>& g, vector<vector<int>>& pre, int in[], int& l, int& start, int& end, int& x) {
	int ve[maxn], vl[maxn];
	memset(ve, 0, sizeof(ve));
	stack<int> s;
	if (topologicalSort(g, ve, s, in, start, x) == false) return;
	l = ve[end];
	fill(vl, vl + maxn, l);
	while (!s.empty()) {
		int u = s.top();
		s.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].id, d = g[u][i].dis;
			if (vl[u] > vl[v] - d) {
				vl[u] = vl[v] - d;
			}
		}
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int v = g[i][j].id, d = g[i][j].dis;
			if (vl[v] - ve[i] - d == 0) {
				pre[v].push_back(i);
			}
		}
	}
}

void dfs(int& start, int& end, vector<vector<int>>& pre, vector<int> tmp, map<int, char>& idName) {
	if (end == start) {
		tmp.push_back(end);
		for (int i = tmp.size() - 1; i >= 1; i--) {
			int v = tmp[i], u = tmp[i-1];
			printf("(%c,%c) ", idName[v], idName[u]);
		}
		tmp.pop_back();
		return;
	}
	else {
		tmp.push_back(end);
		for (int i = 0; i < pre[end].size(); i++) {
			dfs(start, pre[end][i], pre, tmp, idName);
		}
		tmp.pop_back();
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		vector<vector<node>> g(maxn, vector<node>());
		vector<vector<int>> pre(maxn, vector<int>());
		vector<int> tmp;
		map<char, int> nameId;
		map<int, char> idName;
		int in[maxn], out[maxn];
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		int x, y;
		scanf("%d %d", &x, &y);
		getchar();
		for (int i = 0; i < x; i++) {
			char c;
			scanf("%c", &c);
			nameId[c] = i;
			idName[i] = c;
		}
		for (int i = 0; i < y; i++) {
			char c1, c2;
			int l;
			getchar();
			scanf("%c %c %d", &c1, &c2, &l);
			g[nameId[c1]].push_back(node(nameId[c2], l));
			in[nameId[c2]]++;
			out[nameId[c1]]++;
		}
		int start, end;
		for (int i = 0; i < x; i++) {
			if (in[i] == 0) {
				start = i;
			}
			else if(out[i] == 0) {
				end = i;
			}
		}
		int l = 0;
		criticalPath(g, pre, in, l, start, end, x);
		dfs(start, end, pre, tmp, idName);
		printf("%d\n", l);
	}
	return 0;
}
