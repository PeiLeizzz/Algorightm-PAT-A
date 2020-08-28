#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
	int data, next;
} nodes[maxn];
vector<int> res, removed;
set<int> duplicated;

int main() {
	freopen("in.txt", "r", stdin);
	int head, n;
	scanf("%d %d", &head, &n);
	for (int i = 0; i < n; i++) {
		int add, data, nxt;
		scanf("%d %d %d", &add, &data, &nxt);
		nodes[add].data = data;
		nodes[add].next = nxt;
	}
	while (head != -1) {
		// ÖØ¸´
		if (duplicated.find(nodes[head].data) != duplicated.end()) {
			removed.push_back(head);
		}
		else {
			res.push_back(head);
			duplicated.insert(nodes[head].data);
			if (nodes[head].data < 0) {
                duplicated.insert(-nodes[head].data);
            }
		}
		head = nodes[head].next;
	}
	int n1 = res.size(), n2 = removed.size();
	for (int i = 0; i < n1 - 1; i++) {
		printf("%05d %d %05d\n", res[i], nodes[res[i]].data, res[i+1]);
	}
	printf("%05d %d -1\n", res[n1-1], nodes[res[n1-1]].data);
	for (int i = 0; i < n2 - 1; i++) {
		printf("%05d %d %05d\n", removed[i], nodes[removed[i]].data, removed[i+1]);
	}
	if (n2 > 0) printf("%05d %d -1", removed[n2-1], nodes[removed[n2-1]].data);
	fclose(stdin);
	return 0;
}
