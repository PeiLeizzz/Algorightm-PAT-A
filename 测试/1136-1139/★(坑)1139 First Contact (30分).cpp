#include <bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 10005;
vector<pii> res;
set<int> s[maxn]; // ���ÿ������ھӣ����ڵ�Ƚ϶࣬���Բ������ڽӾ��󣬶��ڽӱ���ֱ���ж� v1, v2 ֮���Ƿ��бߣ������ü���
int isGirl[maxn];
int n, m, k;

void search(int id1, int id2) {
    int fg1, fg2;
    if (isGirl[id1] == isGirl[id2]) fg1 = fg2 = isGirl[id1];
    else fg1 = isGirl[id1], fg2 = !fg1;
    for (auto fid1: s[id1]) {
        // ����Ҫ�ж� fid != id1 ��Ϊ�Լ����������Լ����ھ�
        if (fid1 == id2 || isGirl[fid1] != fg1) continue;
        for (auto fid2: s[fid1]) {
            // ͬ��Ҳ����Ҫ�ж� fid2 != id2 ��� fid2 == id2 ��ô s[fid2] �� find �����Լ�
            if (fid2 != id1 && isGirl[fid2] == fg2 && s[fid2].find(id2) != s[fid2].end()) {
                res.pb(mp(fid1, fid2));
            }
        }
    }
}

bool cmp(pii p1, pii p2) {
    return p1.first == p2.first? p1.second < p2.second: p1.first < p2.first;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        string sid1, sid2;
        cin >> sid1 >> sid2;
        // ע�������Ǹ��ӵ� ��� id = -0000 �� int ��ž��� 0���޷��ж�������Ů������ֻ�����ַ���
        int id1 = abs(atoi(sid1.c_str())), id2 = abs(atoi(sid2.c_str()));
        if (sid1[0] == '-') isGirl[id1] = 1;
        if (sid2[0] == '-') isGirl[id2] = 1;
		s[id1].insert(id2);
		s[id2].insert(id1);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        res.clear();
        id1 = abs(id1), id2 = abs(id2);
        search(id1, id2);
        printf("%d\n", res.size());
        sort(res.begin(), res.end(), cmp);
        for (auto p: res) {
            printf("%04d %04d\n", p.first, p.second);
        }
    }
    return 0;
}
