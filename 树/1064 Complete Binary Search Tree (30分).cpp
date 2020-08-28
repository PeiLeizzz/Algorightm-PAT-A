#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int level[maxn], nodes[maxn];
// level[1, N] �����ȫ�������Ĳ�������   nodes �����������
int N, index = 0;

// ������� level �д�ŵ���ȫ������ ����ֵ
void inOrder(int root) {
	if (root > N) return;
	// ���ڴ�ŵ��ǲ������� ���������� root * 2���Һ����� root * 2 + 1
	inOrder(root * 2);
	level[root] = nodes[index++];
	inOrder(root * 2 + 1);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &nodes[i]);
	}
	sort(nodes, nodes + N);
	inOrder(1);
	for (int i = 1; i <= N; i++) {
		if (i > 1) printf(" ");
		printf("%d", level[i]);
	}
	return 0;
}
