#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int n, flag = 0;
int pre[maxn], in[maxn];
map<int, int> ind;

void postOrder(int pl, int pr, int il, int ir) {
    if (pl > pr || flag) return;
    int root = pre[pl], k = ind[root];
    // while (k <= ir && in[k] != root) k++; ����¼ root �������е�λ�ã�������ÿ�ζ�ȥ���������׳�ʱ
    int num = k - il;
    postOrder(pl + 1, pl + num, il, num + il - 1);
    postOrder(pl + num + 1, pr, num + il + 1, ir);
    if (!flag) {
        printf("%d", pre[pl]);
        flag = 1;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        ind[in[i]] = i;
    }
    postOrder(0, n-1, 0, n-1);
    return 0;
}
