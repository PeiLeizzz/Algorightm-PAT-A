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
	// num: ʣ����������group������
	int num = NP, group; // ÿ��ѡ��һ�� ��ÿ��ѡ�� group ��������ֱ���̭������Ϊ group + 1
	while (q.size() > 1) {
		if (num % NG == 0) group = num / NG;
		else group = num / NG + 1;
		for (int i = 0; i < group; i++) {
			int maxId = q.front();
			// ���� num = 14, NG = 3, group = 5
			// �� i = 4, j = 1 (j��0��ʼ��ʱ���Ѿ��� NG * i + j + 1 = 14 ���� ���� j = 2 ��Ҫ�˳�ѭ��
			for (int j = 0; j < NG && NG * i + j < num; j++) {
				int tmp = q.front();
				if (weight[maxId] < weight[tmp]) {
					maxId = tmp;
				}
				mouseRank[tmp] = group + 1; // ������������Ϊ group + 1
				q.pop();
			}
			q.push(maxId); // ����
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
