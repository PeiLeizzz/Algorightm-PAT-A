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
        int now, past = 0; // past = 0 使得 b = arr[i] 也进行比较，因为可能最大字串和正好为某个元素值
        for (int j = i; j < n; j++) { // j 从 i 开始
            int a = arr[j], b = past + a;
            now = max(a, b);
			if (a >= b) ti = j, tj = j; // 单元素值最大，更新目前最大字串的头和尾都为此元素下标
			else if (a < b) tj = j; // 向右拓展了一个元素，所以更新 j 也可以写成 tj++ 因为拓展一定是连续的
            if (now > maxSum) { // 不能是 >=，因为优先要 i, j 最小，而后遇到的相同值 i, j 一定比之前大
                maxSum = now;
                resi = ti, resj = tj;
            }
            past = now;
        }
    }
    printf("%d %d %d", maxSum, arr[resi], arr[resj]);
    return 0;
}
