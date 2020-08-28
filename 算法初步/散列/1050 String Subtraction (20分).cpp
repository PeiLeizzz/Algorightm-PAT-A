#include <bits/stdc++.h>
using namespace std;
int m[500];
string s1, s2;

int main() {
    getline(cin, s1);
    getline(cin, s2);
    memset(m, 0, sizeof(m));
    for (char ch: s2) {
        m[ch] = 1;
    }
    for (char ch: s1) {
        if (!m[ch]) printf("%c", ch);
    }
    return 0;
}
