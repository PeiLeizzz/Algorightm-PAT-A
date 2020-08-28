#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	char fname[20], fdept[20], mname[20], mdept[20];
	bool f = false, m = false;
	int fmax = 0, mmin = 100;
	while (n--) {
		char name[20], sex, dept[20];
		int grade;
		scanf("%s %c %s %d", name, &sex, dept, &grade);
		if (sex == 'F') {
			f = true;
			if (grade > fmax) {
				fmax = grade;
				strcpy(fname, name);
				strcpy(fdept, dept);
			}
		}
		else {
			m = true;
			if (grade < mmin) {
				mmin = grade;
				strcpy(mname, name);
				strcpy(mdept, dept);
			}
		}
	}
	if (f) {
		printf("%s %s\n", fname, fdept);
	}
	else {
		printf("Absent\n");
	}
	if (m) {
		printf("%s %s\n", mname, mdept);
	}
	else {
		printf("Absent\n");
	}
	if (!f || !m) {
		printf("NA");
	}
	else {
		printf("%d", fmax-mmin);
	}
	return 0;
}
