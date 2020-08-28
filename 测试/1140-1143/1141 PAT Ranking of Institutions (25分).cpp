#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n;
struct ins {
    string name;
    int rank, ns = 0;
    double tws;
} sch[maxn];
map<string, int> mp;

bool cmp(ins s1, ins s2) {
    if ((int)s1.tws != (int)s2.tws) return (int)s1.tws > (int)s2.tws; // 不要忘记 int 不然错误
    else if (s1.ns != s2.ns) return s1.ns < s2.ns;
    else return s1.name < s2.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int ind = 0;
    while (n--) {
        string id, school;
        double score;
        cin >> id >> score >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if (mp.find(school) == mp.end()) {
            mp[school] = ind++;
            sch[mp[school]].name = school;
        }
        int sid = mp[school];
        sch[sid].ns++;
        if (id[0] == 'A') sch[sid].tws += score;
        else if (id[0] == 'T') sch[sid].tws += score * 1.5;
        else sch[sid].tws += score / 1.5;
    }
    sort(sch, sch + ind, cmp);
    cout << ind << endl;
    for (int i = 0; i < ind; i++) {
        if (i == 0 || (int)sch[i].tws != (int)sch[i-1].tws) sch[i].rank = i + 1;
        else sch[i].rank = sch[i-1].rank;
        cout << sch[i].rank << " " << sch[i].name << " " << (int)sch[i].tws << " " << sch[i].ns << endl;
    }
}
