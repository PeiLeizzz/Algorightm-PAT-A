#include <bits/stdc++.h>
using namespace std;
map<int, int> a;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		if (k != i) {
			a[k] = i;
		}
	}
	
	int cnt = 0, t = a.size();
	// ����ѭ������ t > 0Ŀ����Ϊ�˵�a���������������²�����ѭ��
	while (t > 0) {
		if (a[0] != 0) {
			int b = a[0];
			a[0] = a[b];
			a.erase(b);
			// ɾ��ֻʣ�� 0 �ˣ��������
			if (a.size() == 1) {
				cnt++;
				break;
			}
		}
		else if (a[0] == 0) {
			// ���0��0λ�������ѡһ�����ڱ�λ�ĺ�������
			// ����ֱ��ѡ��0�����Ǹ�����Ϊmap����
			a[0] = (++a.begin())->second;
			a[(++a.begin())->first] = 0;
		}
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}


