#include <bits/stdc++.h>
using namespace std;

int diamonds[100005];
vector<pair<int, int>> res;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	memset(diamonds, 0, sizeof(diamonds));
	for (int i = 1; i <= n; i++) {
		scanf("%d", &diamonds[i]);
		diamonds[i] += diamonds[i-1];
	}
	int minPrice = 1e9;
	// O(N^2) ³¬Ê±
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int t = diamonds[j] - diamonds[i];
			if (t < minPrice && t >= m) {
				minPrice = t;
				res.clear();
				res.push_back(make_pair(i+1, j));
			}
			else if (t == minPrice) {
				res.push_back(make_pair(i+1, j));
			}
			
			if (t >= minPrice) {
				break;
			}
		}
	}
	for (vector<pair<int, int>>::iterator it = res.begin(); it != res.end(); it++) {
		printf("%d-%d\n", it->first, it->second);
	}
	return 0;
}
