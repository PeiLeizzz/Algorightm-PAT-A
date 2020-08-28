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
	else if (preL > preR) return; // ��ĳһ��û��������ʱ ����ݹ������������ preL + num + 1 ����� preR ��ʱ�ᷢ������
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
	cout << res << endl; // ��Ҳ��֪��Ϊʲôһ��Ҫ���� �����о��Ǵ���
	return 0;
}
