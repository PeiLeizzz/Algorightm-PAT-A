#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	string s;
	// ���ջ��з�
	getchar();
	// sĬ��ֵ��Ϊ��һ���ַ���
	getline(cin, s);
	n--;
	while (n--) {
		string str;
		getline(cin, str);
		int l1 = s.size();
		int l2 = str.size();
		int i = l1-1, j = l2-1;
		// �Ӻ���ǰ����ͬ��׺������ѭ��ʱi��λ�þ�����ͬ��׺�ĵ�һ���ַ���λ��
		while (i >= 0 && j >= 0) {
			if (s[i] != str[j]) {
				i++;
				break;
			}
			i--;
			j--;
		}
		if (i < 0) {
			i = 0;
		}
		s = s.substr(i, l1-i);
	}
	if (s.size() == 0) {
		printf("nai");
	}
	else {
		// ��ֹ����ͬ�Ŀո�Ҳһ�������s
		if (s[0] == ' ') {
			cout << s.substr(1, s.size()-1);
		}
		else {
			cout << s;
		}
	}
	return 0;
}
