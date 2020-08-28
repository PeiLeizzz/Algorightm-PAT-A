#include <bits/stdc++.h>
using namespace std;
int n, m;
struct person {
    string id;
    int score;
    person() {}
    person(string _id, int _s): id(_id), score(_s) {}
};
struct site {
    int id, score = 0, nt = 0;
    map<int, int> d; // 用于记录在 date 那天这个考场有多少人
    site() {}
    site(int _id, int _nt): id(_id), nt(_nt) {}
};
bool cmp1(person& p1, person& p2) {
    return p1.score == p2.score? p1.id < p2.id: p1.score > p2.score;
}
bool cmp2(site& s1, site& s2) {
    return s1.nt == s2.nt? s1.id < s2.id: s1.nt > s2.nt;
}
vector<person> v1[30];
site v2[1005];
map<int, set<int>> mp;
int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
    //ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string id;
        int score;
        cin >> id >> score;
        int test = id[0] - 'A', sid = atoi(id.substr(1, 3).c_str()), date = atoi(id.substr(4, 6).c_str());
        v1[test].push_back(person(id, score));
        v2[sid].nt++, v2[sid].score += score, v2[sid].id = sid, v2[sid].d[date]++;
        mp[date].insert(sid);
    }
    sort(v1[0].begin(), v1[0].end(), cmp1);
    sort(v1[1].begin(), v1[1].end(), cmp1);
    sort(v1[19].begin(), v1[19].end(), cmp1);
    for (int i = 1; i <= m; i++) {
        int t;
		string q;
        cin >> t >> q;
        cout << "Case " << i << ": " << t << " " << q << '\n';
        if (t == 1) {
            int test = q[0] - 'A';
            if (v1[test].size() == 0) cout << "NA\n";
            else for (auto p: v1[test]) cout << p.id << " " << p.score << '\n';
        }
        else if (t == 2) {
            int sid = atoi(q.c_str());
            if (v2[sid].nt == 0) {
                cout << "NA\n";
            }
            else cout << v2[sid].nt << " " << v2[sid].score << '\n';
        }
        else {
            int date = atoi(q.c_str());
            if (mp.find(date) == mp.end()) cout << "NA\n";
            else {
				vector<site> res;
				// 特别要注意，这里输出的不是考场所有日期的总人数，而是在当天有多少人！！！！！！！
                for (auto si: mp[date]) res.push_back(site(si, v2[si].d[date]));
				sort(res.begin(), res.end(), cmp2);
				for (auto si: res) cout << setw(3) << setfill('0') << si.id << " " << si.nt << '\n';
            }
        }
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
