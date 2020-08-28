#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
	char data;
	int next;
} nodes[maxn];

int main() {
	//freopen("in.txt", "r", stdin);
	int h1, h2, n;
	scanf("%d %d %d", &h1, &h2, &n);
	for (int i = 0; i < n; i++) {
		int add, nxt;
		char data;
		scanf("%d %c %d", &add, &data, &nxt);
		nodes[add].data = data;
		nodes[add].next = nxt;
	}
	int p1 = h1, p2 = h2;
	while (p1 != p2) {
		p1 = (p1 == -1)? h2: nodes[p1].next;
		p2 = (p2 == -1)? h1: nodes[p2].next;
	}
	if (p1 == -1) {
		printf("-1");
	}
	else {
		printf("%05d", p1);
	}
	//fclose(stdin);
	return 0;
}
