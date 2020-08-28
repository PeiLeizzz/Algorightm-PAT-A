#include <bits/stdc++.h>
using namespace std;
int order;
struct student {
	char id[8];
	char name[10];
	int grade;
}stu[100005];

bool cmp(student s1, student s2) {
	switch(order) {
		case 1: {
			return strcmp(s1.id, s2.id) < 0;
			break;
		}
		case 2: {
			int res = strcmp(s1.name, s2.name);
			return (res != 0)? res < 0: strcmp(s1.id, s2.id) < 0;
			break;
		}
		case 3: {
			return (s1.grade != s2.grade)? s1.grade < s2.grade: strcmp(s1.id, s2.id) < 0;
			break;
		}
	}
}

int main() {
	int n;
	scanf("%d %d", &n, &order);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++) {
		printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
