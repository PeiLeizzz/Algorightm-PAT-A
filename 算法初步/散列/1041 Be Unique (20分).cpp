#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
vector<int> v;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        mp[t]++;
        v.push_back(t);
    }
    for (auto it = v.begin(); it != v.end(); it++) {
        if (mp[*it] == 1) {
            printf("%d", *it);
            return 0;
        }
    }
    printf("None");
    return 0;
}
