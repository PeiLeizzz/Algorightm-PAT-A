#include <bits/stdc++.h>
using namespace std;

struct person {
	string name;
	int month, day, hour, minute, time;
	bool status;
};

int charge[25] = {0};
map<string, vector<person>> mp;

bool cmp(person p1, person p2) {
	return (p1.name != p2.name)? p1.name < p2.name: p1.time < p2.time;
}

double calculate(person p) {
	double res = p.day * 60 * charge[24] + p.minute * charge[p.hour];
	for (int i = 0; i < p.hour; i++) {
		res += 60 * charge[i];
	}
	return res / 100.0;
}

int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", &charge[i]);
		charge[24] += charge[i];
	}
	int n;
	scanf("%d", &n);
	vector<person> v(n);
	for (int i = 0; i < n; i++) {
		string line;
		person p;
		cin >> p.name;
		scanf("%d:%d:%d:%d", &(p.month), &(p.day), &(p.hour), &(p.minute));
		cin >> line;
		if (line == "on-line") {
			p.status = true;
		}
		else {
			p.status = false;
		}
		p.time = p.day * 24 * 60 + p.hour * 60 + p.minute;
		v[i] = p;
	}
	sort(v.begin(), v.end(), cmp);
	map<string, vector<person>> mp;
	for (int i = 1; i < n; i++) {
		if (v[i].name == v[i-1].name && v[i].status == false && v[i-1].status == true) {
			mp[v[i-1].name].push_back(v[i-1]);
			mp[v[i].name].push_back(v[i]);
		}
	}
	for (auto m: mp) {
		vector<person> tmp = m.second;
		cout << m.first;
		printf(" %02d\n", tmp[0].month);
		double allMoney = 0.0;
		for (int i = 0; i < tmp.size(); i += 2) {
			printf("%02d:%02d:%02d %02d:%02d:%02d ", tmp[i].day, tmp[i].hour, tmp[i].minute, tmp[i+1].day, tmp[i+1].hour, tmp[i+1].minute);
			double money = calculate(tmp[i+1]) - calculate(tmp[i]);
			allMoney += money;
			printf("%d $%.2f\n", tmp[i+1].time - tmp[i].time, money);
		}
		printf("Total amount: $%.2f\n", allMoney);
	}
	return 0;
}
