#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ���в��䣬����Խ�ߣ�����ʮ����ֵ��Խ�󣨵���������

ll switchRadix(char s[], ll radix) {
	ll n = 0;
	int l = strlen(s);
	for (int i = 0; i < l; i++) {
		char ch = s[i];
		if (ch >= 'a' && ch <= 'z') {
			n = n * radix + ch - 'a' + 10;
		}
		else {
			n = n * radix + ch - '0';
		}
	}
	return n;
}

// ���ֲ��� �ҵ������˳�ѭ���汾��
ll binarySearch(ll left, ll right, ll n1, char s2[]) {
	// �������� [left, right]
	// ������С�� mid ���ƣ�ʹ�� n2 == n1
	// �����ҵ�һ�� mid��ʹ�� n2 >= n1
	while (left < right) {
		ll mid = (left + right) / 2;
		ll n2 = switchRadix(s2, mid);
		// ��������ĵ�һ���ط� һ��Ҫ�ж� n2 �Ƿ�С�� 0����Ϊ������ƺܴ�Ļ���ll Ҳ�����
		// ��Ŀ������֤�� n1 ��ʮ������һ��С�� ll�ķ�Χ��������� n2 С�� 0�Ļ����϶��� n1 ���ˣ���
		if (n2 < 0 || n2 >= n1) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	// �����Ҫ�ж�һ�� ��ʱ��leftλ����������
	ll n2 = switchRadix(s2, left);
	if (n2 != n1) return -1;
	return left;
}

// ����n2����radix�ǵ����������������Բ�����ͬʱ����radix����ʹ��n2 == n1
// ��� ���ֲ��ҵĺ��� ���Ը�дΪ��һ���ҵ����˳�ѭ����
ll binarySearch2(ll left, ll right, ll n1, char s2[]) {
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll n2 = switchRadix(s2, mid);
		if (n2 < 0 || n2 > n1) {
			// n2 > n1 �����Ϊ [left, mid-1]
			right = mid - 1;
		}
		else if (n2 < n1) {
			// n2 < n1 �����Ϊ [mid+1, right]
			left = mid + 1;
		}
		else {
			// �ҵ� ֱ�ӷ���
			return mid;
		}
	}
	// �Ҳ��� ���� -1
	return -1;
}

int main() {
	char s1[15], s2[15];
	int tag, radix;
	scanf("%s %s %d %d", s1, s2, &tag, &radix);
	// ���� s1 �� s2 ��֤ radix ʼ���� s1 �Ľ���
	if (tag == 2) {
		char tmp[15];
		strcpy(tmp, s1);
		strcpy(s1, s2);
		strcpy(s2, tmp);
	}
	int l1 = strlen(s1), l2 = strlen(s2);
	// �� s1 תΪ 10 ����
	ll n1 = switchRadix(s1, radix);
	char mc = '0';
	for (int i = 0; i < l2; i++) {
		if (s2[i] > mc) {
			mc = s2[i];
		}
	}
	// left ��ʾ�� s2 ��������� 1 �Ľ�����
	ll left = (mc >= 'a' && mc <= 'z')? mc - 'a' + 11: mc - '0' + 1;
	// ע������ right ��ѡֵ����
	ll right = max(left, n1) + 1;
	ll res = binarySearch(left, right, n1, s2);
	if (res == -1) printf("Impossible");
	else printf("%lld", res);
	return 0;
}
