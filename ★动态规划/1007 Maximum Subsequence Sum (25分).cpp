#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int maxSum = -1, resi, resj, ti, tj;
int n, arr[maxn];
int main() {
    scanf("%d", &n);
    int flag = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] >= 0) flag = 0;
    }
    if (flag) {
        printf("0 %d %d", arr[0], arr[n-1]);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int now, past = 0; // past = 0 ʹ�� b = arr[i] Ҳ���бȽϣ���Ϊ��������ִ�������Ϊĳ��Ԫ��ֵ
        for (int j = i; j < n; j++) { // j �� i ��ʼ
            int a = arr[j], b = past + a;
            now = max(a, b);
			if (a >= b) ti = j, tj = j; // ��Ԫ��ֵ��󣬸���Ŀǰ����ִ���ͷ��β��Ϊ��Ԫ���±�
			else if (a < b) tj = j; // ������չ��һ��Ԫ�أ����Ը��� j Ҳ����д�� tj++ ��Ϊ��չһ����������
            if (now > maxSum) { // ������ >=����Ϊ����Ҫ i, j ��С��������������ֵͬ i, j һ����֮ǰ��
                maxSum = now;
                resi = ti, resj = tj;
            }
            past = now;
        }
    }
    printf("%d %d %d", maxSum, arr[resi], arr[resj]);
    return 0;
}
