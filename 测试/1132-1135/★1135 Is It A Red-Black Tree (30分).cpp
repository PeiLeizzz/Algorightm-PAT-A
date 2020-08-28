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

// �������������������� ������Ϊ���Ĳ���˳�򣡣���
TreeNode* insert(TreeNode* node, int v) {
    if (node == NULL) return new TreeNode(v);
    if (abs(v) > abs(node->val)) node->right = insert(node->right, v);
    else node->left = insert(node->left, v);
    return node;
}

bool dfs(TreeNode* root, int isRed, int tmp) {
    if (root == NULL) {
        num.push_back(tmp); // ����Ҷ�ӽ�㣬������·���еĺ�ɫ��������¼
        // Ҳ�����ü��ϣ�������ռ��ϵ� size != 1 ˵��������Ψһ
        return true;
    }
    // �������Ϊ��ɫ������ root ҲΪ��ɫ������������ 4
    if (isRed && root->val < 0) return false;
    isRed = root->val < 0, tmp += !isRed;
    return dfs(root->left, isRed, tmp) && dfs(root->right, isRed, tmp);
}

bool check(TreeNode* root) {
    if (root == NULL) return true;
    num.clear();
    // ������ isRed(��ʾ������Ƿ�Ϊ��ɫ) Ĭ����Ϊ 0����� dfs �����еڶ��� if �ж�ֱ�ӷ��� false
    // tmp ����·���к�ɫ���ĸ���
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
