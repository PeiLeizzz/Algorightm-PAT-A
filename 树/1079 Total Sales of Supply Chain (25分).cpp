#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 100005;
int N;
double P, r;
vector<int> details; // 存储叶子节点的编号
struct TreeNode {
	int val, depth;
	vector<int> child;
} chain[maxn];

// 层序遍历来计算每个结点的深度 也可以用DFS,这样不用存储details 只要当child.size()==0说明是叶子节点
void setDepth(int root) {
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i: chain[tmp].child) {
			q.push(i);
			chain[i].depth = chain[tmp].depth + 1;
		}
	}
}

int main() {
	scanf("%d %lf %lf", &N, &P, &r);
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		if (n == 0) {
			scanf("%d", &chain[i].val);
			details.push_back(i);
		}
		else {
			while (n--) {
				int ch;
				scanf("%d", &ch);
				chain[i].child.push_back(ch);
			}
		}
	}
	chain[0].depth = 0;
	setDepth(0);
	double res = 0.0;
	for (int i: details) {
		res += P*chain[i].val*pow((100+r)/100, chain[i].depth);
	}
	printf("%.1f", res);
	return 0;
}
