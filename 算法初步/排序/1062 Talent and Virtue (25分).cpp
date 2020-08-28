#include <bits/stdc++.h>
using namespace std;

struct person {
	int id;
	int vitGrade;
	int talGrade;
}sage[100005], noble[100005], fool[100005], small[100005];
// 不一定要开四个数组，也可以设置一个flag值，1~4，按照此权值排序。

bool cmp(person p1, person p2) {
	int sum1 = p1.vitGrade + p1.talGrade;
	int sum2 = p2.vitGrade + p2.talGrade;
	if (sum1 == sum2) {
		if (p1.vitGrade == p2.vitGrade) {
			return p1.id < p2.id;
		}
		else {
			return p1.vitGrade >= p2.vitGrade;
		}
	}
	else {
		return sum1 >= sum2;
	}
}

void addPerson(person p[], int &n, int id, int v, int t) {
	p[n].id = id;
	p[n].vitGrade = v;
	p[n].talGrade = t;
	n++;
}

void sortAndPrint(person p[], int n) {
	sort(p, p+n, cmp);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", p[i].id, p[i].vitGrade, p[i].talGrade);
	}
}

int main() {
	int n, line1, line2, m = 0;
	scanf("%d %d %d", &n, &line1, &line2);
	int sa = 0, no = 0, fo = 0, sm = 0;
	while (n--) {
		int id, v, t;
		scanf("%d %d %d", &id, &v, &t);
		if (v < line1 || t < line1) {
			continue;
		}
		// sages
		else if (v >= line2 && t >= line2) {
			addPerson(sage, sa, id, v, t);
		}
		// nobleman
		else if (v >= line2 && t < line2) {
			addPerson(noble, no, id, v, t);
		}
		// foolman
		else if (v < line2 && t < line2 && v >= t){
			addPerson(fool, fo, id, v, t);
		}
		// smallman
		else {
			addPerson(small, sm, id, v, t);
		}
		m++;
	}
	printf("%d\n", m);
	sortAndPrint(sage, sa);
	sortAndPrint(noble, no);
	sortAndPrint(fool, fo);
	sortAndPrint(small, sm);
	return 0;
}
