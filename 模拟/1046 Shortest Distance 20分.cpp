#include <bits/stdc++.h>
using namespace std;
int dis[100005]; // dis[i]: 1~iµÄ¾àÀë dis[n+1]: n~1µÄ¾àÀë
int main() {
	int n;
	scanf("%d", &n);
	memset(dis, 0, sizeof(dis));
	for (int i = 2; i <= n; i++) {
		int d;
		scanf("%d", &d);
		dis[i] = dis[i-1] + d;
	}
	scanf("%d", &dis[n+1]);
	int m;
	scanf("%d", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;
		}
		int l1 = dis[b] - dis[a];
		int l2 = dis[n] - dis[b] + dis[n+1] + dis[a];
		l1 = min(l1, l2);
		printf("%d\n", l1);
	}
	return 0;
}
