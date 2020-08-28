#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n;
int arr[maxn], isWolf[maxn];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    fill(isWolf, isWolf + n + 1, 1); // 1 代表不是狼人 -1 代表是狼人
    // 枚举 i, j 是狼人，需要证明：其中一个撒谎，剩余人中仅有一人撒谎
    for (int i = 1; i <= n; i++) {
        isWolf[i] = -1;
        for (int j = i + 1; j <= n; j++) {
            isWolf[j] = -1;
            int cnt = 0;
            if (arr[i] * isWolf[abs(arr[i])] < 0) cnt++;
            if (arr[j] * isWolf[abs(arr[j])] < 0) cnt++;
            if (cnt == 1) {
                cnt = 0;
                for (int k = 1; k <= n; k++) {
                    if (k == i || k == j) continue;
                    if (arr[k] * isWolf[abs(arr[k])] < 0) cnt++;
                    if (cnt > 1) break;
                }
                if (cnt == 1) {
                    printf("%d %d", i, j);
                    return 0;
                }
            }
            isWolf[j] = 1;
        }
        isWolf[i] = 1;
    }
    printf("No Solution");
    return 0;
}
