#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
	int data, next;
} nodes[maxn];
vector<int> v;
int main() {
	//freopen("in.txt", "r", stdin);
	int head, n, k;
	scanf("%05d %d %d", &head, &n, &k);
	for (int i = 0; i < n; i++) {
		int add, data, nxt;
		scanf("%d %d %d", &add, &data, &nxt);
		nodes[add].data = data;
		nodes[add].next = nxt;
	}
	int p = head;
	while (p != -1) {
		v.push_back(p);
		p = nodes[p].next;
	}
	n = v.size();
	int group = n / k;
	for (int i = 0; i < group; i++) {
		// [start, end)
		reverse(v.begin() + i * k, v.begin() + i * k + k);
	}
	for (int i = 0; i < n - 1; i++) {
		// ע������� v[i+1] ������ nodes[v[i]].next
		// ��Ϊ�����������������ģ��������ķ�ת
		// ֻ�ǽ���������˳��ͨ��reverse��ת
		printf("%05d %d %05d\n", v[i], nodes[v[i]].data, v[i+1]);
	}
	printf("%05d %d -1", v[n-1], nodes[v[n-1]].data);
	//fclose(stdin);
	return 0;
}
