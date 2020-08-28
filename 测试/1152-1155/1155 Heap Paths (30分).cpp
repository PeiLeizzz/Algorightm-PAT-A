#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int heap[maxn];
int n, ma = 0, mi = 0;

void dfs(int node, string str) {
    int left = node << 1, right = left + 1;
    if (left > n) {
        str += to_string(heap[node]);
        cout << str << '\n';
        return;
    }
    str += to_string(heap[node]);
    str.push_back(' ');
    if (right <= n) {
        if (heap[node] < heap[right]) mi = 1;
        else if (heap[node] > heap[right]) ma = 1;
        dfs(right, str);
    }
    if (left <= n) {
        if (heap[node] < heap[left]) mi = 1;
        else if (heap[node] > heap[left]) ma = 1;
        dfs(left, str);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &heap[i]);
    }
    string str = "";
    dfs(1, str);
    if (mi == 1 && ma == 1) printf("Not Heap\n");
    else if (mi == 0) printf("Max Heap\n");
    else printf("Min Heap\n");
    return 0;
}
