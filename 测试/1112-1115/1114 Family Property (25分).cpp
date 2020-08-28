#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
struct person {
	int estate = 0, area = 0;
	person() {}
	person(int _estate, int _area): estate(_estate), area(_area) {}
} people[maxn];

struct family {
	int id, m;
	double es, ar;
	family(int _id, int _m, double _e, double _a): id(_id), m(_m), es(_e), ar(_a) {}
};

map<int, vector<int>> mp;
set<int> s;
vector<family> res;
int father[maxn];

bool cmp(family f1, family f2) {
	return (f1.ar == f2.ar)? f1.id < f2.id: f1.ar > f2.ar;
}

int find(int x) {
	if (x != father[x]) {
		return father[x] = find(father[x]);
	}
	return x;
}

void Union(int x, int y) {
	int r1 = find(x), r2 = find(y);
	if (r1 != r2) father[r1] = r2;
}

int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < maxn; i++) {
		father[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int id, p1, p2, k, c, es, ar;
		scanf("%d %d %d %d", &id, &p1, &p2, &k);
		if (p1 != -1) {
			Union(id, p1);
			s.insert(p1);
		}
		if (p2 != -1) {
			Union(id, p2);
			s.insert(p2);
		}
		s.insert(id);
		while (k--) {
			scanf("%d", &c);
			Union(id, c);
			s.insert(c);
		}
		scanf("%d %d", &es, &ar);
		people[id] = person(es, ar);
	}
	int cnt = 0;
	for (int id: s) {
		int r = find(id);
		mp[r].push_back(id);
		// 也可以不用 map 直接 res.insert(r)
		// 然后将 id 中的 es ar 加到 r 中即可，r中再加一个属性记录最小的 id
	}
	for (map<int, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++) {
		vector<int> tmp = it->second;
		sort(tmp.begin(), tmp.end());
		int cnt = tmp.size();
		double es = 0.0, area = 0.0;
		for (int id: tmp) {
			es += people[id].estate;
			area += people[id].area;
		}
		es /= cnt;
		area /= cnt;
		res.push_back(family(tmp[0], cnt, es, area));
	}
	sort(res.begin(), res.end(), cmp);
	printf("%d\n", mp.size());
	for (int i = 0; i < res.size(); i++) {
		printf("%04d %d %.3f %.3f\n", res[i].id, res[i].m, res[i].es, res[i].ar);
	}
	return 0;
}
