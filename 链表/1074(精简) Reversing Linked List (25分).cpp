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
 		int t = p; // ��һ��Ŀ�ʼ
 		int i;
 		for (i = 0; i < k; i++) {
 			// ������ô������һ����㣨���ù����һ�ַ�ת������ʱtλ�����һ����㴦����t��Ϊ�գ�Ϊ��ʹ�����nodes[p1]->nextΪ�գ������γɻ�
			if (t == -1 || nodes[t].next == -1) break;
			t = nodes[t].next;
		}
		if (i < k - 1) break;
		else if (i == k - 1) t = -1; // ʣ�µĽ�������ù����һ�ַ�ת
		int p1 = p, p2 = nodes[p1].next, p3 = nodes[p2].next;
		// �����ַ�תǰ��ͷ��㣬����ת���β��㣬���ӵ���һ�ֵ�ͷ���
		int start = p1;
		nodes[p1].next = t; // �Ƚ����ַ�ת���β������ӵ����棬��ֹ�����������һ�֣����治���ٴ����ӣ���һ��break�������γɻ�
		while (p3 != t) {
			nodes[p2].next = p1;
			p1 = p2;
			p2 = p3;
			p3 = nodes[p3].next;
		}
		nodes[p2].next = p1;
		p = t;
		if (flag) {
			head = p2; // ��ת�����������ͷ���
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
