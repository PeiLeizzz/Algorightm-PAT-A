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
    // ע�� ���� sqrt(N) �� sqrt(N) + 1
    // ���磺 N = 16 sqrt(N) = 4 ��ȷΪ m = n == 4�����ѡ�� i = sqrt(N) + 1 �ͻᵼ�� m = 8, n = 2 ����
    // ���磺 N = 15 sqrt(N) = 3 ��ȷΪ m = 5, n = 3, ���ѡ�� i = sqrt(N) �ͻᵼ�� m = 3, n = 5 ����
    for (int i = (int)ceil(sqrt(N)); i <= N; i++) {
        if (N % i == 0) {
            m = i;
            n = N / i;
            break;
        }
    }
    int g[m][n] = {0}, x = 0, y = 0, cnt = 0;
    int l = 0, r = n - 1, u = 0, d = m - 1; // �������±߽�
    while (cnt < N) {
        // ��Ҫ���������棬��Ϊ��� N == 1��n = 1, m = 1, x = 0, y = 0, l = 0, r = 0, u = 0, m = 0
        // �����ѭ��һ��Ҳ����ȥ���������η����ĸ�ѭ��֮��x++, y++ ����Ψһ��Ԫ�ص�λ�þͲ�����
        if (cnt == N - 1) {
            // ���������ֻʣһ��Ԫ�ص�ʱ�򣬻ᷢ�� x == u == d, y == l == r
            // �����ѭ��һ��Ҳ����ȥ��ֻ�ܵ�������
            g[x][y] = arr[cnt]; // ���һ������������NΪƽ����ʱ��������������
			break;
        }
        // ������
        while (cnt < N && y < r) g[x][y++] = arr[cnt++];
        // ������
        while (cnt < N && x < d) g[x++][y] = arr[cnt++];
        // ������
        while (cnt < N && y > l) g[x][y--] = arr[cnt++];
		// ������
        while (cnt < N && x > u) g[x--][y] = arr[cnt++];
        l++, r--, u++, d--;
        x++, y++; // ���� (x, y) λ����һ��ѭ�������Ͻǣ��Ƶ���һ�ε����Ͻ�
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
