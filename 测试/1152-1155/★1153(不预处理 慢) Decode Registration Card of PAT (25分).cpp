#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int n, m;
struct person {
    string id;
    int score;
} stu[maxn];

struct site {
    string sid;
    int nt;
    site() {}
    site(string _sid, int _nt): sid(_sid), nt(_nt) {}
};

bool cmp1(person p1, person p2) {
    return p1.score == p2.score? p1.id <= p2.id: p1.score > p2.score;
}

bool cmp2(site s1, site s2) {
    return s1.nt == s2.nt? s1.sid < s2.sid: s1.nt > s2.nt;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> stu[i].id >> stu[i].score;
    }
    for (int i = 1; i <= m; i++) {
        int t;
        string q;
        cin >> t >> q;
        printf("Case %d: %d %s\n", i, t, q.c_str());
        if (t == 1) {
            vector<person> res;
            for (int j = 0; j < n; j++) {
                if (stu[j].id[0] == q[0]) res.push_back(stu[j]);
            }
            if (res.size() == 0) printf("NA\n");
            else {
                sort(res.begin(), res.end(), cmp1);
                for (auto p: res) {
                    printf("%s %d\n", p.id.c_str(), p.score);
                }
            }
        }
        else if (t == 2) {
            int cnt = 0, total = 0;
            for (int j = 0; j < n; j++) {
                if (stu[j].id.substr(1, 3) == q) cnt++, total += stu[j].score;
            }
            if (cnt == 0) printf("NA\n");
            else printf("%d %d\n", cnt, total);
        }
        else {
            vector<site> res;
            unordered_map<string, int> mp;
            for (int j = 0; j < n; j++) {
                if (stu[j].id.substr(4, 6) == q) mp[stu[j].id.substr(1, 3)]++;
            }
            for (auto it: mp) {
                res.push_back(site(it.first, it.second));
            }
            if (res.size() == 0) printf("NA\n");
            else {
                sort(res.begin(), res.end(), cmp2);
                for (auto si: res) {
                    printf("%s %d\n", si.sid.c_str(), si.nt);
                }
            }
        }
    }
    return 0;
}
