#include <bits/stdc++.h>
using namespace std;
vector<double> mooncake;
map<double, double> price;

int main() {
    int n;
    double d;
    scanf("%d %lf", &n, &d);
    for (int i = 0; i < n; i++) {
        double t;
        scanf("%lf", &t);
        mooncake.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        double t;
        scanf("%lf", &t);
        // 本题坑点：会出现单价相等的mooncake，因此这里不能赋值，而是需要 +=
        price[t / mooncake[i]] += mooncake[i];
    }
    double profit = 0.0;
    for (map<double, double>::reverse_iterator it = price.rbegin(); it != price.rend(); it++) {
        if (it->second <= d) {
            d -= it->second;
            profit += it->first * it->second;
        }
        else {
            profit += it->first * d;
            break;
        }
    }
    printf("%.2f", profit);
    return 0;
}
