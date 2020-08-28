#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int N, m, n;
int arr[maxn];
bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N, cmp);
    // 注意 不是 sqrt(N) 或 sqrt(N) + 1
    // 例如： N = 16 sqrt(N) = 4 正确为 m = n == 4，如果选择 i = sqrt(N) + 1 就会导致 m = 8, n = 2 错误
    // 例如： N = 15 sqrt(N) = 3 正确为 m = 5, n = 3, 如果选择 i = sqrt(N) 就会导致 m = 3, n = 5 错误
    for (int i = (int)ceil(sqrt(N)); i <= N; i++) {
        if (N % i == 0) {
            m = i;
            n = N / i;
            break;
        }
    }
    int g[m][n] = {0}, x = 0, y = 0, cnt = 0;
    int l = 0, r = n - 1, u = 0, d = m - 1; // 左右上下边界
    while (cnt < N) {
        // 需要放在最上面，因为如果 N == 1，n = 1, m = 1, x = 0, y = 0, l = 0, r = 0, u = 0, m = 0
        // 下面的循环一个也进不去，而如果这段放在四个循环之后，x++, y++ 后这唯一的元素的位置就不对了
        if (cnt == N - 1) {
            // 如果不处理，只剩一个元素的时候，会发生 x == u == d, y == l == r
            // 下面的循环一个也进不去，只能单独处理
            g[x][y] = arr[cnt]; // 最后一个数单独处理（N为平方数时会出现这种情况）
			break;
        }
        // 向右走
        while (cnt < N && y < r) g[x][y++] = arr[cnt++];
        // 向下走
        while (cnt < N && x < d) g[x++][y] = arr[cnt++];
        // 向左走
        while (cnt < N && y > l) g[x][y--] = arr[cnt++];
		// 向上走
        while (cnt < N && x > u) g[x--][y] = arr[cnt++];
        l++, r--, u++, d--;
        x++, y++; // 本来 (x, y) 位于上一次循环的左上角，移到下一次的左上角
	}
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
