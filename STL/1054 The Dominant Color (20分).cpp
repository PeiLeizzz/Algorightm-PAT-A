#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
map<int, int> mp;
int main() {
	int M, N;
	int cnt = 0, res;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int key;
			scanf("%d", &key);
			mp[key]++;
			if (mp[key] > cnt) {
				cnt = mp[key];
				res = key;
			}
		}
	}
	printf("%d", res);
	return 0;
}
