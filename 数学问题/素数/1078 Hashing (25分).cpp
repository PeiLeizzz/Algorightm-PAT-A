#include <bits/stdc++.h>
using namespace std;
// 10007是素数
const int maxn = 10010;
vector<int> prime(maxn, 1);
vector<int> hasNum(maxn, 0);

void initPrime() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i < maxn; i++) {
		if (!prime[i]) continue;
		for (int j = i * i; j < maxn; j += i) {
			prime[j] = 0;
		}
	}
}

int main() {
	int size, n;
	initPrime();
	scanf("%d %d", &size, &n);
	if (prime[size] == 0) {
		for (int i = size + 1; i < maxn; i++) {
			if (prime[i]) {
				size = i;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		int index = t % size;
		int j = 1, now = index;
		while (j < size && hasNum[now]) {
			// 平方探测法
			// 正向：now = (index + j * j) % size
			// 负向：now = (((index - j * j) % size) + size) % size
			now = (index + j * j) % size;
			j++;
		}
		if (j == size) printf("-");
		else {
			hasNum[now] = 1;
			printf("%d", now);
		}
		if (i < n - 1) printf(" ");
	}
	return 0;
}
