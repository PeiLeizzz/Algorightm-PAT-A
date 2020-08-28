#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int msize, n, m;
vector<int> hashtable;

bool isPrime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= sqrt(x) + 1; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    scanf("%d %d %d", &msize, &n, &m);
    while (!isPrime(msize)) msize++;
    hashtable.resize(msize);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        int t = key % msize, p = 0;
        while (hashtable[t] && p < msize) {  // 0 ~ msize - 1
			p++;
            t = (key + p * p) % msize;
        }
        if (p == msize) printf("%d cannot be inserted.\n", key);
        else hashtable[t] = key;
    }
    double res = 0.0;
    for (int i = 0; i < m; i++) {
        int key;
        scanf("%d", &key);
        for (int i = 0; i <= msize; i++) { // 0 ~ msize 不知道为什么
            int t = (key + i * i) % msize;
            res++;
            if (hashtable[t] == key || hashtable[t] == 0) break;
        }
    }
    printf("%.1f", res / m);
    return 0;
}
