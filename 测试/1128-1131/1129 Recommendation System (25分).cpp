#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
int n, k;
struct node {
	int id, fre;
	node(int _id, int _fre): id(_id), fre(_fre) {}
	bool operator < (const node no) const {
		return (fre == no.fre)? id < no.id: fre > no.fre;
	}
};
int fre[maxn];
set<node> s;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d", &id);
		if (i > 0) {
			printf("%d:", id);
			int cnt = 0;
			for (const node& no: s) {
				if (cnt++ == k) break;
				printf(" %d", no.id);
			}
			printf("\n");
		}
		auto it = s.find(node(id, fre[id]));
		if (it != s.end()) {
			s.erase(it);
		}
		fre[id]++;
		s.insert(node(id, fre[id]));
	}
	return 0;
}
