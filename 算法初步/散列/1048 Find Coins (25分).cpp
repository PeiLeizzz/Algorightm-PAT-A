#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;  // map�Զ���С��������

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
        // �����Ψһ��Ҫע��ĵط���������Ҫ����������������
        // ��������������жϵĻ����������if�У���ʹmp[a] == 1Ҳ��������
        else if (a == m - a && mp[a] >= 2) {
            printf("%d %d", a, a);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}
