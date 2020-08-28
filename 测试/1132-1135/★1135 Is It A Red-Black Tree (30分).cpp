#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
int k, n;
struct TreeNode {
    int val;
    TreeNode *left = NULL, *right = NULL;
    TreeNode() {}
    TreeNode(int v): val(v) {}
};
vector<int> num;

// 二叉搜索树的先序序列 可以作为它的插入顺序！！！
TreeNode* insert(TreeNode* node, int v) {
    if (node == NULL) return new TreeNode(v);
    if (abs(v) > abs(node->val)) node->right = insert(node->right, v);
    else node->left = insert(node->left, v);
    return node;
}

bool dfs(TreeNode* root, int isRed, int tmp) {
    if (root == NULL) {
        num.push_back(tmp); // 到达叶子结点，将该条路径中的黑色结点个数记录
        // 也可以用集合，如果最终集合的 size != 1 说明个数不唯一
        return true;
    }
    // 若父结点为红色，并且 root 也为红色，不满足条件 4
    if (isRed && root->val < 0) return false;
    isRed = root->val < 0, tmp += !isRed;
    return dfs(root->left, isRed, tmp) && dfs(root->right, isRed, tmp);
}

bool check(TreeNode* root) {
    if (root == NULL) return true;
    num.clear();
    // 根结点的 isRed(表示父结点是否为红色) 默认设为 0，免得 dfs 函数中第二个 if 判断直接返回 false
    // tmp 代表路径中黑色结点的个数
    if (!dfs(root, 0, 0)) return false;
    for (int i = 0; i < num.size() - 1; i++) {
        if (num[i] != num[i + 1]) return false;
    }
    return check(root->left) && check(root->right);
}

int main() {
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        TreeNode* root = NULL;
        for (int i = 0; i < n; i++) {
            int v;
            scanf("%d", &v);
            root = insert(root, v);
        }
		if (root->val > 0 && check(root)) printf("Yes\n");
		else printf("No\n");
    }
    return 0;
}
