#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
struct node {
	int id, indegree;
	node(int _id, int _indegree): id(_id), indegree(_indegree) {}
	friend bool operator < (node n1, node n2) {
		return (n1.indegree == n2.indegree)? n1.id > n2.id: n1.indegree > n2.indegree;
	}
};

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m), n && m) {
		vector<int> g[maxn], res;
		int in[maxn];
		for (int i = 0; i < m; i++) {
			int c1, c2;
			scanf("%d %d", &c1, &c2);
			g[c1].push_back(c2);
			in[c2]++;
		}
		priority_queue<node> q;
		for (int i = 1; i <= n; i++) {
			if (in[i] == 0) {
				q.push(node(i, 0));
			}
		}
		while (!q.empty()) {
			int id = q.top().id;
			q.pop();
			res.push_back(id);
			for (int i = 0; i < g[id].size(); i++) {
				int v = g[id][i];
				in[v]--;
				if (in[v] == 0) {
					q.push(node(v, 0));
				}
			}
		}
		for (int i = 0; i < res.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", res[i]);
		}
		printf("\n");
	}
	return 0;
}
