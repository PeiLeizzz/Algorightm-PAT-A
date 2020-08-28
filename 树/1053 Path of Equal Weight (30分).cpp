#include <bits/stdc++.h>
using namespace std;
int N, M, S;
vector<int> path;

struct TreeNode {
	int val;
	vector<int> child;
} node[105];

bool cmp(int p, int q) {
	return node[q].val < node[p].val;
}

void dfs(int root, int s) {
	if (s == S && node[root].child.size() == 0) {
		for (int i = 0; i < path.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", path[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < node[root].child.size(); i++) {
		int ch = node[root].child[i];
		int v = node[ch].val;
		path.push_back(v);
		dfs(ch, s+v);
		path.pop_back();
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &node[i].val);
	}
	for (int i = 0; i < M; i++) {
		int parent, num;
		scanf("%02d %d", &parent, &num);
		for (int j = 0; j < num; j++) {
			int ch;
			scanf("%02d", &ch);
			node[parent].child.push_back(ch);
		}
	}
	for (int i = 0; i < N; i++) {
		sort(node[i].child.begin(), node[i].child.end(), cmp);
	}
	path.push_back(node[0].val);
	dfs(0, node[0].val);
	return 0;
}
