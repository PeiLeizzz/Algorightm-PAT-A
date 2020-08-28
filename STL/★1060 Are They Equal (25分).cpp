#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int n;
string handle(string s, int& e) {
	int k = 0; // s���±��ƶ�
	// ȥ��ǰ�� 0 �� 0040 00.003
	while (s.length() > 0 && s[0] == '0') s.erase(s.begin());
	// ˵���� <1 ��С�� �� .333
	if (s[0] == '.') {
		s.erase(s.begin()); // ȥ��С����
		// ȥ��С������ǰ�� 0 �� .0053
		while (s.length() > 0 && s[0] == '0') {
			s.erase(s.begin());
			e--; // С����� 0�ĸ��� = ָ�����෴��
		}
	}
	// ˵�� >1 �� 40 44.44
	else {
		while (k < s.length() && s[k] != '.') {
			k++;
			e++; // С����ǰ�� 0�ĸ��� = ָ��
		}
		// ˵������С���� ȥ��С����
		if (k < s.length()) {
			s.erase(s.begin() + k);
		}
	}
	// ȥ��ǰ�� 0 ��С�����Ϊ 0��˵��ԭ���־��� 0 �� 0000 0.000 000.000
	if (s.length() == 0) {
		e = 0;
	}
	k = 0;
	string res = "";
	// ��ȡǰ������ s �� n λ��λ��������ĩβ�� 0
	while (k < n && k < s.length()) res += s[k++];
	while (k++ < n) res += '0';
	return res;
}

int main() {
	string s1, s2, s3, s4;
	int e1 = 0, e2 = 0;
	cin >> n >> s1 >> s2;
	s3 = handle(s1, e1);
	s4 = handle(s2, e2);
	if (s3 == s4 && e1 == e2) {
		cout << "YES 0." << s3 << "*10^" << e1;
	}
	else {
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2;
	}
	return 0;
}
