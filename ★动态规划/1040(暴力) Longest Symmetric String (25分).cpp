#include <bits/stdc++.h>
using namespace std;
string str;
int maxl = 1;
int main() {
    getline(cin, str);
    int n = str.size();
    for (int i = 0; i < n; i++) {
        for (int j = maxl; j <= n - i; j++) {
            string s1 = str.substr(i, j);
            string s2 = s1;
            reverse(s2.begin(), s2.end());
            if (s1 == s2) {
                maxl = max(maxl, j);
            }
        }
    }
    printf("%d", maxl);
    return 0;
}
