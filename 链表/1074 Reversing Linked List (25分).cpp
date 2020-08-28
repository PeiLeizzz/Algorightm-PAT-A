#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
	int data, next;
} nodes[maxn];

void print(int head) {
	while (head != -1) {
		printf("%05d %d ", head, nodes[head].data);
		head = nodes[head].next;
		if (head == -1) {
			printf("-1\n");
		}
		else {
			printf("%05d\n", head);
		}
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	int head, n, k;
	scanf("%05d %d %d", &head, &n, &k);
	for (int i = 0; i < n; i++) {
		int add, data, nxt;
		scanf("%05d %d %d", &add, &data, &nxt);
		nodes[add].data = data;
		nodes[add].next = nxt;
	}
	int p = head, cnt = 0;
	// 可能会有多余的结点（不在以 head 为头结点的链表上） 所以要重新检查一遍 n
	while (p != -1) {
		p = nodes[p].next;
		cnt++;
	}
	n = cnt;
 	if (k == 1 || n < 2) {
		print(head);
	}
	else {
		int p1, p2, p3 = head;
		int group = n / k;
		int t = head, h = -1;
		for (int i = 0; i < group; i++) {
			p1 = p3;
			p2 = nodes[p1].next;
			p3 = nodes[p2].next;
			// t: 上一轮的尾结点
			int tmp = p1;
			for (int j = 0; j < k - 2; j++) {
				nodes[p2].next = p1;
				p1 = p2;
				p2 = p3;
				p3 = nodes[p3].next;
			}
			nodes[p2].next = p1;
			// 退出时 p3 是下一轮的 p1
			if (i > 0) {
				h = p2;
				nodes[t].next = h;
				t = tmp;
			}
			else head = p2;
		}
		nodes[t].next = p3;
		print(head);
	}
	//fclose(stdin);
	return 0;
}
