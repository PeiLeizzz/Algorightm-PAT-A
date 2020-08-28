#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
int arr[maxn];
int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        if (d > 0) arr[cnt++] = d;
    }
    sort(arr, arr + cnt);
    int p = arr[0];
    if (p > 1) {
        printf("1");
        return 0;
    }
    int flag = 1;
    for (int i = 1; i < cnt; i++) {
        if (arr[i] > p + 1) {
            printf("%d", p + 1);
            flag = 0;
            break;
        }
		p = arr[i];
    }
    if (flag) printf("%d", arr[cnt-1] + 1);
    return 0;
}
