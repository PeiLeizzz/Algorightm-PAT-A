#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
struct node {
	int data, next;
} nodes[maxn];
vector<int> res, removed;
set<int> duplicated; // 也可以不用集合 直接用数组 0 1 判断

int main() {
	// freopen("in.txt", "r", stdin);
	int head, n;
	scanf("%d %d", &head, &n);
	for (int i = 0; i < n; i++) {
		int add, data, nxt;
		scanf("%d %d %d", &add, &data, &nxt);
		nodes[add].data = data;
		nodes[add].next = nxt;
	}
	while (head != -1) {
		// 重复
		if (duplicated.find(abs(nodes[head].data)) != duplicated.end()) {
			removed.push_back(head);
		}
		else {
			res.push_back(head);
			duplicated.insert(abs(nodes[head].data));
		}
		head = nodes[head].next;
		
		/**
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
		注意：上面是错误的！！！！！
		因为如果先遇到15后遇到-15，那么会判定为不重复！！！！
		**/
	}
	int i = 0, n1 = res.size(), n2 = removed.size();
	while (i < n1 - 1) {
		printf("%05d %d %05d\n", res[i], nodes[res[i]].data, res[i+1]);
		i++;
	}
	printf("%05d %d -1\n", res[n1-1], nodes[res[n1-1]].data);
	i = 0;
	while (i < n2 - 1) {
		printf("%05d %d %05d\n", removed[i], nodes[removed[i]].data, removed[i+1]);
		i++;
	}
	if (n2 > 0) printf("%05d %d -1", removed[n2-1], nodes[removed[n2-1]].data);
	// fclose(stdin);
	return 0;
}
