#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
int n, flag = 1;
string res = "";
int pre[maxn], post[maxn];

void create(int preL, int preR, int postL, int postR) {
	if (preL == preR) {
		res += to_string(pre[preL]) + " ";
		return;
	}
	else if (preL + 1 == preR) flag = 0;
	else if (preL > preR) return; // 当某一轮没有右子树时 下面递归进入右子树的 preL + num + 1 会大于 preR 此时会发生错误
	int root = pre[preL], l = pre[preL + 1], index = postL;
	while (post[index] != l) index++;
	int num = index - postL + 1;
	create(preL + 1, preL + num, index - num + 1, index);
	res += to_string(root) + " ";
	create(preL + num + 1, preR, index + 1, postR - 1);
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	create(0, n-1, 0, n-1);
	flag? printf("Yes\n"): printf("No\n");
	res.pop_back();
	cout << res << endl; // 我也不知道为什么一点要换行 不换行就是错误
	return 0;
}
