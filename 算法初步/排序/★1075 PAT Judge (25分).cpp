#include <bits/stdc++.h>
using namespace std;

struct student {
	int id, grade[6] = {-1, -1, -1, -1, -1, -1}, correct = 0, flag = 0;
	// grade[1~5]存放题目的分数 没有提交则为-1 未通过编译则为0
	// grade[0]存放总分
	// correct 为答对的题目数量
	// flag 为是否有提交通过编译
	// 最后被输出的条件： correct >= 0 && flag > 0 因为可能会有某个人的所有提交都通过了编译但是都是0分的情况，所以总分0分也要考虑
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
		// 只有分数大于等于已有分数才覆盖
		if (score >= stu[id].grade[que]) {
			if (score == -1) {
				stu[id].grade[que] = 0;
			}
			else {
				// 这里要极度注意！！！
				// 如果多次提交了满分，不加stu[id].grade[que] != score这个条件的话
				// 会导致correct多次累加！！！
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
		// 下面这个判断不能放在上面，因为可能会有这种情况：
		// 上一次输出的是有分数的最后一名，假设名次为 10，这一次遇到的是不符合要求的，他的名次应该是11
		// 然后如果上来就continue，并没有更新 r，会导致下次遇到符合要求的，r变为他的下标(>11)，其实应该是11
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
