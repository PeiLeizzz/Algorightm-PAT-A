#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, k;
struct person {
	char name[10];
	int height;
	person(){}
	person(char na[10], int h) {
		strcpy(name, na);
		height = h;
	}
};

bool cmp(person p1, person p2) {
	return (p1.height == p2.height)? strcmp(p1.name, p2.name) > 0: p1.height < p2.height;
}

vector<person> v;
int main() {
	scanf("%d %d", &n, &k);
	getchar();
	for (int i = 0; i < n; i++) {
		char name[10];
		int height;
		scanf("%s %d", name, &height);
		getchar();
		v.push_back(person(name, height));
	}
	sort(v.begin(), v.end(), cmp);
	int tot = n;
	for (int i = 1; i <= k; i++) {
		int m;
		if (i == 1) m = tot / k + tot % k;
		else m = tot / k;
		int mid = m / 2; // 注意下标从 0 开始，所以是 m / 2
		vector<person> tmp(m + 1);
		int p = mid;
		for (int j = n - 1, t = 1; j >= n - m; j--, t = -t) {
			p = p + t * (n - 1 - j); // 左右摇摆
			tmp[p] = v[j];
		}
		for (int j = 0; j < m; j++) {
			printf("%s", tmp[j].name);
			if (j < m - 1) printf(" ");
		}
		printf("\n");
		n -= m; // 窗口左移 [n-1, n-m]
	}
	return 0;
}
