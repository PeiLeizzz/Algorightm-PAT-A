#include <vector>
#include <iostream>
#include <math.h>
#include <limits.h>
// INT_MAX �ȳ�����ͷ�ļ� <limits.h> �� ������ N ���Ϊ 10^10 ��ʵ����� inf = 1e12
using namespace std;
const int maxn = 100005;
int N, D = INT_MAX, num = 0;
double P, r;
struct TreeNode {
	int father = -1;
	vector<int> child;
} node[maxn];

void dfs(int root, int depth) {
	if (depth > D) return;
	if (node[root].child.size() == 0) {
		if (D == depth) num++;
		else if (D > depth) {
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
	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		for (int j = 0; j < t; j++) {
			int m;
			scanf("%d", &m);
			node[i].child.push_back(m);
			node[m].father = i;
		}
	}
	// ��ʵ���治��Ҫ ��Ϊ��Ŀ����˵�� 0 Ϊ��
	int root;
	for (int i = 0; i < N; i++) {
		if (node[i].father == -1) {
			root = i;
			break;
		}
	}
	dfs(root, 0);
	printf("%.4f %d", P*pow((100+r)/100, D), num);
	return 0;
}
