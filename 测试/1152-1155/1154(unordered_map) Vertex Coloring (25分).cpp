#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int N, M, K;
int g[maxn][maxn];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        g[v1][v2] = g[v2][v1] = 1;
    }
    scanf("%d", &K);
    while (K--) {
		unordered_map<int, vector<int>> mp;
        for (int i = 0; i < N; i++) {
            int col;
            scanf("%d", &col);
            mp[col].push_back(i);
        }
        int flag = 1;
        for (auto m: mp) {
			if (!flag) break;
			auto v = m.second;
			int n = v.size();
            for (int j = 0; j < n; j++) {
				if (!flag) break;
                for (int k = j + 1; k < n; k++) {
                    if (g[v[j]][v[k]] == 1) {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (flag) printf("%d-coloring\n", mp.size());
        else printf("No\n");
    }
    return 0;
}
