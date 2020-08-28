#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int m = 316, q = 317; // sqrt(maxn) = 316 �ֳ� 317 �飬ǰ 316 ���� 316 ��Ԫ�أ����һ���� 100005 - 316 * 316 ��Ԫ��
int n;
int block[q], table[maxn];
stack<int> st;
string s;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Pop") {
			if (st.empty()) printf("Invalid\n");
			else {
				int tmp = st.top();
				printf("%d\n", tmp);
				st.pop();
				block[tmp / m]--;
				table[tmp]--;
			}
		}
		else if (s == "Push") {
			int v;
			scanf("%d", &v);
			st.push(v);
			block[v / m]++; // ֵΪ v ��Ԫ�����ڵ� v / m ��
			table[v]++;
		}
		else {
			if (st.empty()) printf("Invalid\n");
			else {
				int sum = 0, sz = st.size(), j = 0, t = 0;
				int k = (sz % 2 == 0)? sz / 2: (sz + 1) / 2;
				while (sum < k) {
					sum += block[j++];
				}
				sum -= block[--j]; // ������һ�� + ����
				// �� j ���һ��Ԫ�ص��±�Ϊ j * m
				while (sum < k) {
					sum += table[j * m + t];
					t++;
				}
				int tmp = j * m + t - 1; // Ԫ��Ϊ j * m + t - 1   j * m �ǿ�ı��  t - 1 �Ǹÿ���Ԫ�صı��
				printf("%d\n", tmp);
			}
		}
	}
	return 0;
}
