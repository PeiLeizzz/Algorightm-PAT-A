#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> numble;
int main() {
	int n;
	ll p;
	scanf("%d %lld", &n, &p);
	for (int i = 0; i < n; i++) {
		ll a;
		scanf("%lld", &a);
		numble.push_back(a);
	}
	sort(numble.begin(), numble.end());
	int len = 1;
	for (int i = 0; i < n && i + len < n; i++) {
		int left = i + 1;
		int right = n;
		// �������� [left, right]
		// right ȡ n ��ԭ�򣺿����������ж�������������ôleft �����Ե� n
		// �� len = n ��������
		// ���ȡ right = n - 1 ��Ҫ�����ж� numble[n-1] > cmpNum
		ll cmpNum = numble[i] * p;
		// Ѱ�ҵ�һ�� mid ʹ numble[mid] > cmpNum
		while (left < right) {
			int mid = (left + right) / 2;
			if (numble[mid] > cmpNum) {
				// ���䣺[left, mid]
				right = mid;
			}
			else {
				// ���䣺[mid+1, right]
				left = mid + 1;
			}
		}
		len = max(len, left - i);
	}
	printf("%d", len);
	return 0;
}
