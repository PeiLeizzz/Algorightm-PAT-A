#include <bits/stdc++.h>
using namespace std;

void readPoly(int n, vector<pair<int, float>>& p) {
	int e;
	float c;
	while (n--) {
		cin >> e >> c;
		p.push_back(make_pair(e, c));
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	vector<pair<int, float>> a, b, res;
	int na, nb;
	cin >> na;
	readPoly(na, a);
	cin >> nb;
	readPoly(nb, b);

	int pa = 0;
	int pb = 0;
	while (pa < na && pb < nb) {
		int ea = a[pa].first;
		float ca = a[pa].second;
		int eb = b[pb].first;
		float cb = b[pb].second;
		if (ea > eb) {
			res.push_back(make_pair(ea, ca));
			pa++;
		}
		else if (ea < eb) {
			res.push_back(make_pair(eb, cb));
			pb++;
		}
		else {
			float c = ca + cb;
			if (c) {
				res.push_back(make_pair(ea, c));
			}
			pa++;
			pb++;
		}
	}

	while (pa < na) {
		res.push_back(make_pair(a[pa].first, a[pa].second));
		pa++;
	}

	while (pb < nb) {
		res.push_back(make_pair(b[pb].first, b[pb].second));
		pb++;
	}

	cout << res.size();
	for (vector<pair<int, float>>::iterator it = res.begin(); it < res.end(); it++) {
		cout << " " << (*it).first << " " << fixed << setprecision(1) << (*it).second;
	}

	fclose(stdin);
	return 0;
}
