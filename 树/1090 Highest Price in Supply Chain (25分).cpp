#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
const int maxn = 100005;
int N, D = 0, num = 1;
double P, r;
struct TreeNode {
	int father;
	vector<int> child;
} node[maxn];

void dfs(int root, int depth) {
	if (node[root].child.size() == 0) {
		if (D == depth) num++;
		else if (D < depth) {
			D = depth;
			num = 1;
		}
		return;
	}
	for (int i: node[root].child) {
		dfs(i, depth+1);
	}
}

int main() {
	scanf("%d %lf %lf", &N, &P, &r);
	int f;
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		if (t == -1) {
			f = i;
			node[i].father = -1;
		}
		else {
			node[i].father = t;
			node[t].child.push_back(i);
		}
	}
	dfs(f, 0);
	printf("%.2f %d", P*pow((100+r)/100, D), num);
	return 0;
}
