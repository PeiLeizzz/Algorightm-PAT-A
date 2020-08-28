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
	if (k == 1) {
		print(head);
		return 0;
	}
	int p = head, end = p, flag = 1;
 	while (true) {
 		int t = p; // 下一组的开始
 		int i;
 		for (i = 0; i < k; i++) {
 			// 如果正好处在最后一个结点（正好够最后一轮反转），此时t位于最后一个结点处，则将t置为空，为了使下面的nodes[p1]->next为空，避免形成环
			if (t == -1 || nodes[t].next == -1) break;
			t = nodes[t].next;
		}
		if (i < k - 1) break;
		else if (i == k - 1) t = -1; // 剩下的结点数正好够最后一轮反转
		int p1 = p, p2 = nodes[p1].next, p3 = nodes[p2].next;
		// 将本轮反转前的头结点，即反转后的尾结点，连接到下一轮的头结点
		int start = p1;
		nodes[p1].next = t; // 先将该轮反转后的尾结点连接到后面，防止由于这是最后一轮，后面不会再次连接（下一轮break），而形成环
		while (p3 != t) {
			nodes[p2].next = p1;
			p1 = p2;
			p2 = p3;
			p3 = nodes[p3].next;
		}
		nodes[p2].next = p1;
		p = t;
		if (flag) {
			head = p2; // 反转后整个链表的头结点
			flag = 0;
		}
		else {
			nodes[end].next = p2;
		}
		end = start;
	}
	print(head);
	//fclose(stdin);
	return 0;
}
