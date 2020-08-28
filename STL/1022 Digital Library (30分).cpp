#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// bookTitle author keyWord publisher year
map<string, vector<string>> mp[5];
int N, M;
string id, ti, au, kws, pb, y;

void readInfo() {
	getline(cin, id);
	getline(cin, ti);
	getline(cin, au);
	getline(cin, kws);
	getline(cin, pb);
	getline(cin, y);
}

void addMap() {
	mp[0][ti].push_back(id);
	mp[1][au].push_back(id);
	string s = "";
	for (char ch: kws) {
		if (ch == ' ') {
			mp[2][s].push_back(id);
			s = "";
		}
		else s.push_back(ch);
	}
	if (s.size() > 0) mp[2][s].push_back(id);
	mp[3][pb].push_back(id);
	mp[4][y].push_back(id);
}

void doQuery(int qid, string q) {
	if (mp[qid].count(q)) {
		sort(mp[qid][q].begin(), mp[qid][q].end());
		for (string s: mp[qid][q]) {
			cout << s << endl;
		}
	}
	else printf("Not Found\n");
}

int main() {
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++) {
		readInfo();
		addMap();
	}
	scanf("%d", &M);
	getchar();
	for (int i = 0; i < M; i++) {
		string query;
		getline(cin, query);
		int qid = query[0] - '1';
		string q = query.substr(3);
		cout << query << endl;
		doQuery(qid, q);
	}
	return 0;
}
