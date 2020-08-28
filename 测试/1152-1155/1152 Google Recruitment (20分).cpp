#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int l, k;

bool isPrime(string str) {
    int t = atoi(str.c_str());
    if (t == 0 || t == 1) return false;
    for (int i = 2; i <= sqrt(t); i++) {
        if (t % i == 0) return false;
    }
    return true;
}

int main() {
    cin >> l >> k >> s;
    for (int i = 0; i <= l - k; i++) {
        string str = s.substr(i, k);
        if (isPrime(str)) {
            cout << str;
            return 0;
        }
    }
    cout << "404";
    return 0;
}
