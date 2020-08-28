#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;  // map自动从小到大排序

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (n--) {
        int t;
        scanf("%d", &t);
        mp[t]++;
    }
    int maxN = m / 2 + 1;
    for (auto t: mp) {
        int a = t.first;
        if (a > maxN) break;
        if (a != m - a && mp[m - a]) {
            printf("%d %d", a, m - a);
            return 0;
        }
        // 这道题唯一需要注意的地方，可能需要输出的两个数字相等
        // 如果不进行特殊判断的话，在上面的if中，即使mp[a] == 1也会进行输出
        else if (a == m - a && mp[a] >= 2) {
            printf("%d %d", a, a);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
