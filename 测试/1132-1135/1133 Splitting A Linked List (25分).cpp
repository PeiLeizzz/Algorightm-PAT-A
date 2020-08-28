 #include <bits/stdc++.h>
using namespace std;
int head, n, k;
const int maxn = 100005;
struct node {
    int add, val, nxt;
} nodes[maxn];
vector<node> res;
int main() {
    scanf("%05d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        int add, val, nxt;
        scanf("%05d %d %05d", &add, &val, &nxt);
        nodes[add].add = add, nodes[add].val = val, nodes[add].nxt = nxt;
    }
    int p = head;
    while (p != -1) {
        if (nodes[p].val < 0) res.push_back(nodes[p]);
        p = nodes[p].nxt;
    }
    p = head;
    while (p != -1) {
        if (nodes[p].val >= 0 && nodes[p].val <= k) res.push_back(nodes[p]);
        p = nodes[p].nxt;
    }
    p = head;
    while (p != -1) {
        if (nodes[p].val > k) res.push_back(nodes[p]);
        p = nodes[p].nxt;
    }
    for (int i = 0; i < res.size() - 1; i++) {
        printf("%05d %d %05d\n", res[i].add, res[i].val, res[i+1].add);
    }
    printf("%05d %d %d\n", res[res.size()-1].add, res[res.size()-1].val, -1);
    return 0;
}
