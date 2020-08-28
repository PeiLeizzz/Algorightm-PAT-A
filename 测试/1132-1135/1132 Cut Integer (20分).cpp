#include <bits/stdc++.h>
using namespace std;
int k;
int main() {
    scanf("%d", &k);
    while (k--) {
        int d;
        scanf("%d", &d);
        string str = to_string(d);
        int m = str.size() / 2;
        string a = str.substr(0, m), b = str.substr(m);
        long long aa = atoi(a.c_str()), bb = atoi(b.c_str());
        long long t = aa * bb;
        if (t != 0 && d % t == 0) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
