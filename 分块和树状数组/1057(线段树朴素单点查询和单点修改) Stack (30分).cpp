#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
stack<int> s;
struct node {
	int sum, left, right, lazy;
} tree[maxn << 2];

// ����
void build(int k, int l, int r) {
	tree[k].left = l;
	tree[k].right = r;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid);
	build(k << 1 | 1, mid + 1, r);
}

// �����޸�
void add(int k, int x, int w) {
    if (tree[k].left == tree[k].right) {
        tree[k].sum += w;
        return;
    }
    int mid = (tree[k].left + tree[k].right) >> 1;
    if (x <= mid) add(k << 1, x, w); // ����������
    else add(k << 1 | 1, x, w); // ����������
    tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum; // ״̬�ϲ�
}

// ���ֵݹ�ʵ�ֵĵ����ѯ
int search(int k, int x) {
	if (tree[k].left == tree[k].right) return tree[k].left;
	if (tree[k << 1].sum >= x) return search(k << 1, x); // �����������²�ѯ
	else return search(k << 1 | 1, x - tree[k << 1].sum);
    // ����� p - tree[k << 1].sum �ǽ������������ѿ������������� sum �Ѿ�ȫ������
    // ���� p - tree[k << 1].sum����Ҫ����������Ѱ�����ʣ��ֵ�����㣩
}

int main() {
	build(1, 1, maxn);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char str[15];
		scanf("%s", str);
		if (str[1] == 'o') {
			if (s.empty()) printf("Invalid\n");
			else {
				int t = s.top();
				s.pop();
				add(1, t, -1);
				printf("%d\n", t);
			}
		}
		else if (str[1] == 'e') {
			if (s.empty()) printf("Invalid\n");
			else {
				int l = 1, r = maxn, p = (s.size() + 1) / 2;
				int res = search(1, p);
				printf("%d\n", res);
			}
		}
		else {
			int t;
			scanf("%d", &t);
			s.push(t);
			add(1, t, 1);
		}
	}
	return 0;
}
