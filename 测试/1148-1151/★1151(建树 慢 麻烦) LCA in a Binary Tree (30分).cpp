#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int m, n, in[maxn], pre[maxn];
map<int, int> pos;
// 建树做法
struct TreeNode {
    int val;
    TreeNode *left = NULL, *right = NULL;
    TreeNode() {}
    TreeNode(int v): val(v) {}
};

// 建树做法
void create(TreeNode* &node, int il, int ir, int pl, int pr) {
    if (il > ir || pl > pr) return;
    int root = pre[pl], k = il;
    node = new TreeNode(root);
    while (k <= ir && in[k] != root) k++;
    int num = k - il;
    create(node->left, il, k-1, pl+1, pl+num);
    create(node->right, k+1, ir, pl+num+1, pr);
}

// 建树做法
int LCA(TreeNode* node, int v, int u) {
    int pn = pos[node->val], pv = pos[v], pu = pos[u];
    if (pn >= pv && pn <= pu) return node->val;
    else if (pn <= pv && pn >= pu) return node->val;
    else if (pn <= pv && pn <= pu) return LCA(node->right, v, u);
    else return LCA(node->left, v, u);
    /** 下面的做法速度更快
    if (node == NULL) return -1;
    else if (node->val == v || node->val == u) return node->val;
    int l = LCA(node->left, v, u);
    int r = LCA(node->right, v, u);
    if (l == -1) return r; // 左子树里找不到 则一定在右子树中
    if (r == -1) return l; // 右子树中找不到 则一定在左子树中
    return node->val; // 既不在左子树中又不在右子树中，则一定是当前结点
    **/
}

int main() {
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }
    TreeNode* root = NULL; // 建树做法
    create(root, 0, n-1, 0, n-1);
    for (int i = 0; i < m; i++) {
        int v, u, f1 = 0, f2 = 0;
        scanf("%d %d", &v, &u);
        for (int i = 0; i < n; i++) {
            if (pre[i] == v) f1 = 1;
            if (pre[i] == u) f2 = 1;
        }
        if (!f1 && !f2) printf("ERROR: %d and %d are not found.\n", v, u);
        else if (!f1) printf("ERROR: %d is not found.\n", v);
        else if (!f2) printf("ERROR: %d is not found.\n", u);
        else {
            int lca = LCA(root, v, u); // 建树做法
            if (lca == v) printf("%d is an ancestor of %d.\n", v, u);
            else if (lca == u) printf("%d is an ancestor of %d.\n", u, v);
            else printf("LCA of %d and %d is %d.\n", v, u, lca);
        }
    }
    return 0;
}
