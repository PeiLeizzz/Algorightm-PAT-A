#include <bits/stdc++.h>
using namespace std;
int m[150];
char s1[1005], s2[1005];

int main() {
    scanf("%s %s", s1, s2);
    memset(m, 0, sizeof(m));
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i < l1; i++) {
        m[s1[i]]++;
    }
    int cnt = 0, flag = 1;
    for (int i = 0; i < l2; i++) {
        m[s2[i]]--;
        if (m[s2[i]] < 0) {
            flag = 0;
            cnt++;
        }
    }
    if (flag) {
        printf("Yes %d", l1-l2);
    }
    else {
        printf("No %d", cnt);
    }
    return 0;
}
