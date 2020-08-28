#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
map<int, int> mp;
int prime[maxn];
int n;

void init() {
	prime[0] = prime[1] = 1;
	for (int i = 2; i < maxn; i++) {
		if (prime[i]) continue;
		for (int j = i * i; j < maxn; j += i) {
			prime[j] = 1;
		}
	}
}

int main() {
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int id;
		scanf("%d", &id);
		if (i == 1) mp[id] = 1;
		else if (prime[i] == 0) mp[id] = 2;
		else mp[id] = 3;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d", &id);
		if (mp.find(id) != mp.end()) {
			int q = mp[id];
			switch (q) {
				case 0: {
					printf("%04d: Checked\n", id);
					break;
				}
				case 1: {
					printf("%04d: Mystery Award\n", id);
					mp[id] = 0;
					break;
				}
				case 2: {
					printf("%04d: Minion\n", id);
					mp[id] = 0;
					break;
				}
				case 3: {
					printf("%04d: Chocolate\n", id);
					mp[id] = 0;
					break;
				}
			}
		}
		else {
			printf("%04d: Are you kidding?\n", id);
		}
	}
	return 0;
}
