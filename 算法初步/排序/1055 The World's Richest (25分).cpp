#include <bits/stdc++.h>
using namespace std;

struct person {
	char name[10];
	int age, worth;
}people[100005], valid[100005];

int Age[100005];

bool cmp(person p1, person p2) {
	if (p1.worth != p2.worth) return p1.worth > p2.worth;
	else if (p1.age != p2.age) return p1.age < p2.age;
	else return strcmp(p1.name, p2.name) < 0;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].worth);
	}
	sort(people, people + n, cmp);
	// 预处理，由于M<100，所以将某个年龄中排名100以外的剔除，形成一个新的查找数组，提高下面的查找效率
	// 这一步没有也是正确的
	int validNum = 0;
	for (int i = 0; i < n; i++) {
		if (Age[people[i].age] < 100) {
			Age[people[i].age]++;
			valid[validNum++] = people[i];
		}
	}
	int num, amin, amax;
	for (int i = 1; i <= m; i++) {
		int flag = 0;
		scanf("%d %d %d", &num, &amin, &amax);
		printf("Case #%d:\n", i);
		for (int j = 0; j < n && flag < num; j++) {
			if (people[j].age >= amin && people[j].age <= amax) {
				printf("%s %d %d\n", people[j].name, people[j].age, people[j].worth);
				flag++;
			}
		}
		if (flag == 0) {
			printf("None\n");
		}
	}
	return 0;
}
