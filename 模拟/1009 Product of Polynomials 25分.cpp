#include <bits/stdc++.h>
using namespace std;
map<int, double> a, b, res;

void init() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int e;
		double c;
		scanf("%d %lf", &e, &c);
		a[e] = c;
	}
	scanf("%d", &n);
	while (n--) {
		int e;
		double c;
		scanf("%d %lf", &e, &c);
		b[e] = c;
	}
}

void add() {
	for (map<int, double>::iterator it = a.begin(); it != a.end(); it++) {
		for (map<int, double>::iterator it2 = b.begin(); it2 != b.end(); it2++) {
			int e = it->first + it2->first;
			double c = it->second * it2->second;
			res[e] += c;
			if (res[e] == 0.0) {
				res.erase(e);
			}
		}
	}
}

void print() {
	int cnt = res.size();
	printf("%d ", cnt);
	int i = 0;
	for (map<int, double>::reverse_iterator it = res.rbegin(); it != res.rend(); it++, i++) {
		printf("%d %.1f", it->first, it->second);
		if (i < cnt - 1) {
			printf(" ");
		}
	}
}

int main() {
	init();
	add();
	print();
	return 0;
}
