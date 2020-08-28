#include <bits/stdc++.h>
using namespace std;

struct student {
	int id, grade[6] = {-1, -1, -1, -1, -1, -1}, correct = 0, flag = 0;
	// grade[1~5]�����Ŀ�ķ��� û���ύ��Ϊ-1 δͨ��������Ϊ0
	// grade[0]����ܷ�
	// correct Ϊ��Ե���Ŀ����
	// flag Ϊ�Ƿ����ύͨ������
	// �������������� correct >= 0 && flag > 0 ��Ϊ���ܻ���ĳ���˵������ύ��ͨ���˱��뵫�Ƕ���0�ֵ�����������ܷ�0��ҲҪ����
}stu[10005], valid[10005];

bool cmp(student s1, student s2) {
	if (s1.grade[0] != s2.grade[0]) return s1.grade[0] > s2.grade[0];
	else if (s1.correct != s2.correct) return s1.correct > s2.correct;
	else return s1.id < s2.id;
}

int main() {
	int n, k, m;
	scanf("%d %d %d", &n, &k, &m);
	int pro[k+1];
	for (int i = 1; i <= k; i++) {
		scanf("%d", &pro[i]);
	}
	while (m--) {
		int id, que, score;
		scanf("%d %d %d", &id, &que, &score);
		stu[id].id = id;
		// ֻ�з������ڵ������з����Ÿ���
		if (score >= stu[id].grade[que]) {
			if (score == -1) {
				stu[id].grade[que] = 0;
			}
			else {
				// ����Ҫ����ע�⣡����
				// �������ύ�����֣�����stu[id].grade[que] != score��������Ļ�
				// �ᵼ��correct����ۼӣ�����
				if (score == pro[que] && stu[id].grade[que] != score) {
					stu[id].correct++;
				}
				stu[id].grade[que] = score;
				stu[id].flag = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= k; j++) {
			if (stu[i].grade[j] > 0) {
				sum += stu[i].grade[j];
			}
		}
		stu[i].grade[0] = sum;
	}
	sort(stu + 1, stu + n + 1, cmp);
	int r = 1;
	for (int i = 1; i <= n; i++) {
		if (i > 1 && stu[i].grade[0] != stu[i-1].grade[0]) {
			r = i;
		}
		// ��������жϲ��ܷ������棬��Ϊ���ܻ������������
		// ��һ����������з��������һ������������Ϊ 10����һ���������ǲ�����Ҫ��ģ���������Ӧ����11
		// Ȼ�����������continue����û�и��� r���ᵼ���´���������Ҫ��ģ�r��Ϊ�����±�(>11)����ʵӦ����11
		if (stu[i].flag <= 0) {
			continue;
		}
		printf("%d %05d %d ", r, stu[i].id, stu[i].grade[0]);
		for (int j = 1; j <= k; j++) {
			if (stu[i].grade[j] == -1) {
				printf("-");
			}
			else {
				printf("%d", stu[i].grade[j]);
			}
			if (j < k) {
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
