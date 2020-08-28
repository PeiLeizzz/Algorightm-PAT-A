#include <bits/stdc++.h>
using namespace std;

int diamonds[100005], n, m;
vector<pair<int, int>> res;
//   3   2   1   5   4   6   8   7   16   10   15   11   9   12   14   13
// 0 3   5   6  11  15  21  29  36   52   62   77   88   97  109  123  136

int binarySearch(int left, int right) {
	int a = diamonds[left];
	// [left, right] �ҵ�һ��λ��ʹ�� diamonds[mid] - a >= m
	while (left < right) {
		int mid = (left + right) / 2;
		if (diamonds[mid] - a >= m) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	scanf("%d %d", &n, &m);
	memset(diamonds, 0, sizeof(diamonds));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &diamonds[i]);
		// �����Ļ���������ǵ������ˣ�����ʹ�ö��ֲ���
		diamonds[i] += diamonds[i-1];
	}
	// O(NlogN)
	int minPrice = 1e9;
	// ö����˵�i��Ѱ�ҷ����������Ҷ˵�j����[i+1, j]������������
	for (int i = 0; i <= n; i++) {
		int j = binarySearch(i, n);
		// �������ʹ�����ú��� lower_bound()�ҵ�һ������������λ��
		// lower_bound(val):���������е�һ��ֵ�����ڻ���ڡ�val��Ԫ�ص�iteratorλ�á�
        // upper_bound(val): ���������е�һ��ֵ�����ڡ�...��λ��
		// int j = lower_bound(diamonds + i, diamonds + n, diamonds[i] + m) - diamonds;
		int t = diamonds[j] - diamonds[i];
		if (t < minPrice && t >= m) {
			minPrice = t;
			res.clear();
			res.push_back(make_pair(i+1, j));
		}
		else if (t == minPrice) {
			res.push_back(make_pair(i+1, j));
		}
	}
	for (vector<pair<int, int>>::iterator it = res.begin(); it != res.end(); it++) {
		printf("%d-%d\n", it->first, it->second);
	}
	return 0;
}
