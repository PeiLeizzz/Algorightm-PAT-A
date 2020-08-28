#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, m;
int level[maxn];
int first = 0;
void postOrder(int node) {
    if (node * 2 > m) { // ��Ҷ�ӽ��
        if (first == 0) first = 1;
        else printf(" ");
        printf("%d", level[node]);
		return;
    }
    if (node * 2 <= m) postOrder(node * 2);
    if (node * 2 + 1 <= m) postOrder(node * 2 + 1);
    if (first) printf(" "); // �жϿ��п��� ��Ϊ�ߵ��ⲽ�϶�����Ҷ�ӽ�㣬���Կ϶�Ҳ���ǵ�һ�������
    printf("%d", level[node]);
}

int main() {
    scanf("%d %d", &n, &m);
    while (n--) {
		int flag = 0, h = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &level[i]);
            if (h) continue;
            if (!flag && i > 1) {
                if (level[i] > level[i/2]) flag = 1; // С����
                else if (level[i] < level[i/2]) flag = 2; // �󶥶�
            }
            else if ((flag == 1 && level[i] < level[i/2]) || (flag == 2 && level[i] > level[i/2])) h = 1;
        }
        if (h) printf("Not Heap\n");
        else if (flag == 1) printf("Min Heap\n");
        else printf("Max Heap\n");
        first = 0;
        postOrder(1);
		printf("\n");
    }
    return 0;
}
