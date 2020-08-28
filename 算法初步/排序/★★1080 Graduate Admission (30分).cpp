#include <bits/stdc++.h>
using namespace std;
// student 里的id是输入时的i值
struct student {
	int ge, gi, id, rank, choose[5];
}stu[40005];

// school里stuIndex里的是按成绩排完序后在数组中的下标
struct school {
	// lastAdmit 初始设为 -1 代表还没有招收学生
	int quota, lastAdmit = -1, stuNum = 0, stuIndex[40005];
}sch[105];

bool cmp1(student s1, student s2) {
	if (s1.ge + s1.gi != s2.ge + s2.gi) return s1.ge + s1.gi > s2.ge + s2.gi;
	else return s1.ge > s2.ge;
}

// 按学生的id递增排序
bool cmp2(int a, int b) {
	return stu[a].id < stu[b].id;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d", &sch[i].quota);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &stu[i].ge, &stu[i].gi);
		for (int j = 0; j < k; j++) {
			scanf("%d", &stu[i].choose[j]);
		}
		stu[i].id = i;
	}
	sort(stu, stu + n, cmp1);
	int r = 1;
	for (int i = 0; i < n; i++) {
		if (i == 0 || !(stu[i].ge == stu[i-1].ge && stu[i].gi == stu[i-1].gi)) {
			r = i + 1;
		}
		stu[i].rank = r;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int choice = stu[i].choose[j];
			int last = sch[choice].lastAdmit;
			int num = sch[choice].stuNum;
			if (num < sch[choice].quota || (last != -1 && stu[i].rank == stu[last].rank)) {
				sch[choice].lastAdmit = i;
				sch[choice].stuIndex[num] = i;
				sch[choice].stuNum++;
				break;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		int num = sch[i].stuNum;
		if (num > 0) {
			// sch[i].stuIndex[j] 存储的是：学校i招收的第j个学生在stu数组中的位置
			// 要按【当时输入时的学生顺序】进行输出，而只有stu[sch[i].stuIndex[j]].id存了原始的顺序
			sort(sch[i].stuIndex, sch[i].stuIndex + num, cmp2);
			for (int j = 0; j < num; j++) {
				printf("%d", stu[sch[i].stuIndex[j]].id);
				if (j < num - 1) {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
