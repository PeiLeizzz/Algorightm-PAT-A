#include <bits/stdc++.h>
using namespace std;
struct student {
	int id, grade[4], rank[4];
}stu[2005];

map<int, student*> mp;
int now;
char lesson[] = {'A', 'C', 'M', 'E'};

bool cmp(student s1, student s2) {
	// cmp必须写<或>,不能写成<=或>=。否则，可能出现段错误！！！
	return s1.grade[now] > s2.grade[now];
}

void doRank(student stu[], int n) {
	int r = 1;
	for (int i = 0; i < n; i++) {
		if (i > 0 && stu[i].grade[now] != stu[i-1].grade[now]) {
			r = i + 1;
		}
		stu[i].rank[now] = r;
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int id;
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
		// 不取平均，直接取整数
		stu[i].grade[0] = stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3];
	}

	for (now = 0; now < 4; now++) {
		sort(stu, stu + n, cmp);
		doRank(stu, n);
	}

	// 一定要在排序后再用map存储，map存的是地址，而sort可能会改变地址内的值！！！！
	for (int i = 0; i < n; i++) {
		mp[stu[i].id] = &(stu[i]);
	}
	
	while (m--) {
		int id;
		scanf("%d", &id);
		if (mp.count(id) == 0) {
			printf("N/A\n");
			continue;
		}
		student* s = mp[id];
		int r = 0;
		for (int i = 1; i < 4; i++) {
			if (s->rank[i] < s->rank[r]) {
				r = i;
			}
		}
		printf("%d %c\n", s->rank[r], lesson[r]);
	}
	return 0;
}
