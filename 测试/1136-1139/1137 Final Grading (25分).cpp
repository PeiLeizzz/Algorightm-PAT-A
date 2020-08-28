#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int p, m, n, g;
string str;
struct student {
    string name;
    int pgrade, mgrade = -1, fgrade = -1, g;
    student(string n, int pg, int mg, int fg, int _g) {
        name = n, pgrade = pg, mgrade = mg, fgrade = fg, g = _g;
    }
    student() {}
};
map<string, student> mp;
vector<student> res;

bool cmp(student s1, student s2) {
    return s1.g == s2.g? s1.name < s2.name: s1.g > s2.g;
}

int main() {
    scanf("%d %d %d", &p, &m, &n);
    for (int i = 0; i < p; i++) {
        cin >> str >> g;
        mp[str].name = str;
        mp[str].pgrade = g;
    }
    for (int i = 0; i < m; i++) {
        cin >> str >> g;
        mp[str].name = str;
        mp[str].mgrade = g;
    }
    for (int i = 0; i < n; i++) {
        cin >> str >> g;
        mp[str].name = str;
        mp[str].fgrade = g;
    }
    for (auto stu: mp) {
        if (stu.second.pgrade < 200) continue;
        int mg = stu.second.mgrade, fg = stu.second.fgrade;
        mg = mg == -1? 0: mg, fg = fg == -1? 0: fg;
        double gsum = mg > fg? mg * 0.4 + fg * 0.6: fg;
		int sum = round(gsum);
        if (sum < 60) continue;
        res.push_back(student(stu.second.name, stu.second.pgrade, stu.second.mgrade, stu.second.fgrade, sum));
    }
    sort(res.begin(), res.end(), cmp);
    for (auto stu: res) {
        cout << stu.name << " " << stu.pgrade << " " << stu.mgrade << " " << stu.fgrade << " " << stu.g << endl;
    }
    return 0;
}
