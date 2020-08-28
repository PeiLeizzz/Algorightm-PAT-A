#include <bits/stdc++.h>
using namespace std;

struct student {
	char name[12], id[12], grade;
}stu[100005];

bool cmp(student s1, student s2) {
	return s1.grade > s2.grade;
}

vector<student> valid;

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	int gmin, gmax;
	scanf("%d %d", &gmin, &gmax);
	if (gmin > gmax) {
		int temp = gmin;
		gmin = gmax;
		gmax = temp;
	}
	for (int i = 0; i < n; i++) {
		if (stu[i].grade >= gmin && stu[i].grade <= gmax) {
			valid.push_back(stu[i]);
		}
	}
	if (valid.size() == 0) {
		printf("NONE");
		return 0;
	}
	sort(valid.begin(), valid.end(), cmp);
	for (int i = 0; i < valid.size(); i++) {
		printf("%s %s\n", valid[i].name, valid[i].id);
	}
	return 0;
}
