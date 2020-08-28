#include <bits/stdc++.h>
using namespace std;

struct testee {
	char id[15];
	int grade;
	int location;
	int finalRank;
	int localRank;
};

bool cmp(testee* t1, testee* t2) {
	return (t1->grade == t2->grade)? strcmp(t1->id, t2->id) <= 0: t1->grade > t2->grade;
}

vector<testee*> final;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k;
		vector<testee*> l;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			testee* t = new testee();
			scanf("%s %d", t->id, &(t->grade));
			t->location = i;
			l.push_back(t);
			final.push_back(t);
		}
		sort(l.begin(), l.end(), cmp);
		int r = 1;
		for (int j = 0; j < k; j++) {
			if (j > 0 && l[j]->grade != l[j-1]->grade) {
				r = j + 1;
			}
			l[j]->localRank = r;
		}
	}
	sort(final.begin(), final.end(), cmp);
	int size = final.size();
	printf("%d\n", size);
	int r = 1;
	for (int i = 0; i < size; i++) {
		if (i > 0 && final[i]->grade != final[i-1]->grade) {
			r = i + 1;
		}
		final[i]->finalRank = r;
		printf("%s %d %d %d\n", final[i]->id, final[i]->finalRank, final[i]->location, final[i]->localRank);
	}
	return 0;
}
