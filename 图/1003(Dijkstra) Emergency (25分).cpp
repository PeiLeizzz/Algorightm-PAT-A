#include <bits/stdc++.h>
using namespace std;
#define MAX 0x3f3f3f3f
int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;  // n������ m��·
	int roads[n][n];  // roads[i][j]: i��j��ֱ�Ӿ���
	int dis[n];  // dis[i]: c1��i����̾���
	bool visited[n] = {false};  // visited[i]: i�����Ƿ񱻷��ʹ�
	int hands[n];  // ÿ�����о�Ԯ����
	int weight[n] = {0};  // weight[i]: c1��i�ľ�Ԯ�����ܺ�
	int minpath[n] = {0}; // minpath[i]: c1��i�����·��������
	
	// ��ʼ��������
	memset(roads, 0x3f, sizeof(roads));
	fill(dis, dis + n, MAX);
	for (int i = 0; i < n; i++) {
		cin >> hands[i];
	}
	for (int i = 0; i < m; i++) {
		int city1, city2, length;
		cin >> city1 >> city2 >> length;
		roads[city1][city2] = length;
		roads[city2][city1] = length;
		if (city1 == c1) {
			dis[city2] = length;
			minpath[city2] = 1;
			weight[city2] = hands[city1] + hands[city2];
		}
	}
	dis[c1] = 0;
	visited[c1] = true;
	weight[c1] = hands[c1];
	minpath[c1] = 1;
	
	// dijkstra�����·��
	for (int i = 0; i < n; i++) {
		int u = -1;
		int minlen = MAX;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false && dis[j] < minlen) {   // �ҵ�һ������j��ʹ��i��j��ֱ�Ӿ������
				u = j;
                minlen = dis[j];
			}
		}
		if (u == -1) {  // ���û������ͨ�ĳ��У���˵��������ɣ��˳�ѭ��
			break;
		}
		visited[u] = true;
		// ��uΪ���ĵ���б�����ˢ��c1���������е���̾���
		for (int v = 0; v < n; v++) {
			if (visited[v] == false && roads[u][v] != MAX) {
				if (roads[u][v] + dis[u] < dis[v]) {
					dis[v] = roads[u][v] + dis[u];
					weight[v] = weight[u] + hands[v];
					minpath[v] = minpath[u];
				}
				else if (roads[u][v] + dis[u] == dis[v]) {
					minpath[v] += minpath[u];
					if (weight[u] + hands[v] > weight[v]) {
						weight[v] = weight[u] + hands[v];
					}
				}
			}
		}
	}
	
	cout << minpath[c2] << " " << weight[c2];
	//fclose(stdin);
	return 0;
}
