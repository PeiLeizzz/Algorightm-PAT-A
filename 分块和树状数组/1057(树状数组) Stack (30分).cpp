#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, c[maxn];
stack<int> st;
string s;
#define lowbit(i) ((i)&(-i))

void update(int x, int v) {
	for (int i = x; i < maxn; i += lowbit(i)) {
		c[i] += v;
	}
}

int getSum(int x) {
	int res = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		res += c[i];
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "Pop") {
			if (st.empty()) printf("Invalid\n");
			else {
				int tmp = st.top();
				st.pop();
				update(tmp, -1);
				printf("%d\n", tmp);
			}
		}
		else if (s == "Push") {
			int m;
			scanf("%d", &m);
			st.push(m);
			update(m, 1);
		}
		else {
			if (st.empty()) printf("Invalid\n");
			else {
				int k = (st.size() + 1) / 2;
				int l = 1, r = maxn;
				while (l < r) {
					int mid = (l + r) / 2;
					if (getSum(mid) < k) l = mid + 1;
					else r = mid;
				}
				printf("%d\n", l);
			}
		}
	}
	return 0;
}
