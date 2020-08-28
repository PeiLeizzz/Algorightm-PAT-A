#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int father[maxn], bird[maxn];
int n, cnt = 0, t = 0;
void init() {
	for (int i = 1; i <= maxn; i++) {
		father[i] = i;
	}
}

int find(int x) {
	return (x == father[x])? x: father[x] = find(father[x]);
}

void Union(int a, int b) {
	int r1 = find(a), r2 = find(b);
	if (r1 != r2) {
		father[r1] = r2;
		t--;
	}
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int k, r, b;
		scanf("%d", &k);
		if (k > 0) {
			scanf("%d", &r);
			if (bird[r] == 0) {
				bird[r] = 1;
				cnt++;
			}
		}
		for (int j = 1; j < k; j++) {
			scanf("%d", &b);
			if (bird[b] == 0) {
				bird[b] = 1;
				cnt++;
			}
			Union(b, r);
		}
	}
	printf("%d %d\n", t + cnt, cnt);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (find(a) == find(b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
