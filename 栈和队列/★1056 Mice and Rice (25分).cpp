#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int NP, NG;
vector<int> weight;
vector<int> mouseRank;
queue<int> q;
int main() {
	scanf("%d %d", &NP, &NG);
	for (int i = 0; i < NP; i++) {
		int w;
		scanf("%d", &w);
		weight.push_back(w);
		mouseRank.push_back(1);
	}
	for (int i = 0; i < NP; i++) {
		int id;
		scanf("%d", &id);
		q.push(id);
	}
	// num: 剩余老鼠数，group：组数
	int num = NP, group; // 每组选出一个 那每轮选出 group 个，则该轮被淘汰的名次为 group + 1
	while (q.size() > 1) {
		if (num % NG == 0) group = num / NG;
		else group = num / NG + 1;
		for (int i = 0; i < group; i++) {
			int maxId = q.front();
			// 例如 num = 14, NG = 3, group = 5
			// 则当 i = 4, j = 1 (j从0开始）时，已经有 NG * i + j + 1 = 14 个了 所以 j = 2 就要退出循环
			for (int j = 0; j < NG && NG * i + j < num; j++) {
				int tmp = q.front();
				if (weight[maxId] < weight[tmp]) {
					maxId = tmp;
				}
				mouseRank[tmp] = group + 1; // 该轮老鼠排名为 group + 1
				q.pop();
			}
			q.push(maxId); // 晋级
		}
		num = group;
	}
	mouseRank[q.front()] = 1;
	for (int i = 0; i < NP; i++) {
		if (i > 0) printf(" ");
		printf("%d", mouseRank[i]);
	}
	return 0;
}
