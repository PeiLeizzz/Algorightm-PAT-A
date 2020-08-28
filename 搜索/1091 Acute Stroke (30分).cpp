#include <bits/stdc++.h>
using namespace std;
int arr[1290][130][65], visited[1290][130][65] = {0};
int M, N, L, T, res = 0;
int dirx[6] = {0, 0, 0, 0, 1, -1};
int diry[6] = {0, 0, 1, -1, 0, 0};
int dirz[6] = {1, -1, 0, 0, 0, 0};

struct node {
	int x, y, z;
};

bool check(int x, int y, int z) {
	if (!(x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L || arr[x][y][z] == 0 || visited[x][y][z] == 1)) {
		return true;
	}
	return false;
}

int bfs(int x, int y, int z) {
	queue<node> q;
	node t;
	t.x = x, t.y = y, t.z = z;
	q.push(t);
	visited[x][y][z] = 1;
	int size = 0;
	while (!q.empty()) {
		node tmp = q.front();
		size++;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int newx = tmp.x + dirx[i];
			int newy = tmp.y + diry[i];
			int newz = tmp.z + dirz[i];
			if (check(newx, newy, newz)) {
				node nt;
				nt.x = newx, nt.y = newy, nt.z = newz;
				q.push(nt);
				visited[newx][newy][newz] = 1;
			}
		}
	}
	if (size >= T) return size;
	else return 0;
}

int main() {
	scanf("%d %d %d %d", &M, &N, &L, &T);
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &arr[j][k][i]);
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < L; k++) {
				// 遇到新的一块 则在此块上进行搜索
				if (arr[i][j][k] == 1 && visited[i][j][k] == 0)
					res += bfs(i, j, k);
			}
		}
	}
	printf("%d", res);
	return 0;
}
