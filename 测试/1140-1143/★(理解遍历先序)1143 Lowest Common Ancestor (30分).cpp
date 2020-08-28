#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int m, n, pre[maxn];
set<int> s;

// LCA 是最上层的满足 a <= LCA <= b 的那个结点
// 因此采用遍历【先序序列】的方式，自上而下依次访问（层序遍历应该也行吧？）
int LCA(int v1, int v2) {
	if (v1 > v2) {
		int tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
    int i = 0;
    for (; i < n; i++) {
        if (v1 <= pre[i] && v2 >= pre[i]) break;
    }
    return pre[i];
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        s.insert(pre[i]);
    }
    for (int i = 0; i < m; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        auto it1 = s.find(v1), it2 = s.find(v2);
        if (it1 == s.end() && it2 == s.end()) printf("ERROR: %d and %d are not found.\n", v1, v2);
        else if (it1 == s.end()) printf("ERROR: %d is not found.\n", v1);
        else if (it2 == s.end()) printf("ERROR: %d is not found.\n", v2);
		if (it1 == s.end() || it2 == s.end()) continue;
        int ans = LCA(v1, v2);
        if (ans == v1) printf("%d is an ancestor of %d.\n", v1, v2);
        else if (ans == v2) printf("%d is an ancestor of %d.\n", v2, v1);
        else printf("LCA of %d and %d is %d.\n", v1, v2, ans);
    }
    return 0;
}
