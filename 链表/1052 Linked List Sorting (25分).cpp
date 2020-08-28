#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
	int data, next;
} nodes[maxn];
vector<int> v;

bool cmp(int a, int b) {
	return nodes[a].data < nodes[b].data;
}

int main() {
	int n, head;
	scanf("%d %d", &n, &head);
	for (int i = 0; i < n; i++) {
		int add, data, nxt;
		scanf("%d %d %d", &add, &data, &nxt);
		nodes[add].data = data;
		nodes[add].next = nxt;
	}
	while (head != -1) {
		v.push_back(head);
		head = nodes[head].next;
	}
	// 坑：可能一个结点也没给
	if (v.size() == 0) {
		printf("0 -1\n");
		return 0;
	}
	sort(v.begin(), v.end(), cmp);
	n = v.size();
	printf("%d %05d\n", n, v[0]);
	for (int i = 0; i < n - 1; i++) {
		printf("%05d %d %05d\n", v[i], nodes[v[i]].data, v[i+1]);
	}
	printf("%05d %d -1", v[n-1], nodes[v[n-1]].data);
	return 0;
}
