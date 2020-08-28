#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int m = 316, q = 317; // sqrt(maxn) = 316 分成 317 块，前 316 块有 316 个元素，最后一块有 100005 - 316 * 316 个元素
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
			block[v / m]++; // 值为 v 的元素属于第 v / m 块
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
				sum -= block[--j]; // 回退上一步 + 操作
				// 第 j 块第一个元素的下标为 j * m
				while (sum < k) {
					sum += table[j * m + t];
					t++;
				}
				int tmp = j * m + t - 1; // 元素为 j * m + t - 1   j * m 是块的编号  t - 1 是该块中元素的编号
				printf("%d\n", tmp);
			}
		}
	}
	return 0;
}
