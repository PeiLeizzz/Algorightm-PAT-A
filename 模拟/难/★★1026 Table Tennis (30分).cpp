
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, inf = 1 << 30;
int n, k, m, st, en;

struct Player {
    int arrive, serve, play, isVip; // ����ʱ�䣬��ʼʱ�䣬����ʱ�䣬�Ƿ� vip
} newPlayer;

vector<Player> player;

struct table {
    int end, num, isVip; // ����ʱ�䣬��������ʹ�ù����Ƿ� vip
} table[maxn];

int toSecond(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

bool cmp1(const Player& p1, const Player& p2) {
    return p1.arrive < p2.arrive;
}

bool cmp2(const Player& p1, const Player& p2) {
    return p1.serve < p2.serve;
}

void allocate(int tid, int pid) {
    // ��Ա������ʱ�� ������ռ��
    if (player[pid].arrive <= table[tid].end) {
        player[pid].serve = table[tid].end;
    }
    else {
        player[pid].serve = player[pid].arrive;
    }
    table[tid].num++;
    table[tid].end = player[pid].serve + player[pid].play;
}

int findNextVip(int vipId) {
    for (int i = vipId + 1; i < n; i++) {
        if (player[i].isVip == 1) return i;
    }
    return n;
}

int main() {
    st = toSecond(8, 0, 0), en = toSecond(21, 0, 0);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, mi, s, t, p, v;
        scanf("%02d:%02d:%02d %d %d", &h, &mi, &s, &p, &v);
        t = toSecond(h, mi, s);
        if (t >= en) continue; // 9 �㼰�Ժ����ģ�ֱ�Ӻ���
        newPlayer.arrive = t;
        if (p > 120) newPlayer.play = 7200; // ѵ��ʱ�䲻�ܳ��� 2 Сʱ
        else newPlayer.play = p * 60; // ת��Ϊ����Ϊ��λ
        newPlayer.isVip = v;
        newPlayer.serve = en;
        // ��ʼ��ʼʱ����Ϊ 21 �㣬��Ϊ����������ȵ� 21 ���Ժ�Ҳû��ѵ��
        // �������Ŀ�ʼʱ��Ҳ���ᱻ�޸ģ����ʱ���Խ�������
        player.push_back(newPlayer);
    }
    scanf("%d %d", &k, &m);
    for (int i = 1; i <= k; i++) {
        table[i].end = st; // ���������Ľ���ʱ���ʼ��Ϊ 8 ��
    }
    for (int i = 1; i <= m; i++) {
        int id;
        scanf("%d", &id);
        table[id].isVip = 1;
    }
    sort(player.begin(), player.end(), cmp1); // ����Ա���ﵽʱ������
    int pid = 0, n = player.size(), vipId = findNextVip(-1); // id: ��һ����Ա���±� vipId: ��һ�� vip ��Ա���±�
    while (pid < n) {
        // Ѱ��������е�����
        int tid = -1, minT = inf;
        for (int j = 1; j <= k; j++) {
            if (table[j].end < minT) {
                minT = table[j].end;
                tid = j;
            }
        }
        if (table[tid].end >= en) break; // ��������ʱ�䣬�����������޷��� 9 ��֮ǰѵ��
        if (player[pid].isVip == 1 && pid < vipId) {
            // �����ǰ��Ա�� vip��������һ��Ҫ�ҵ� vip ������
            // ˵������֮ǰ�Ѿ������� vip ѵ����������
            pid++;
            continue;
        }

        // ����ǵ�ǰ�� vip ����
        if (table[tid].isVip == 1) {
            // ��������� vip ��Ա���һ�δѵ����û��������
            // �򽫸������������
            if (player[pid].isVip == 1) {
                allocate(tid, pid);
                // if (pid == vipId)
                    vipId = findNextVip(vipId);
                pid++;
            }
            else {
                // ���ײ��� vip ��Ա
                // �����һ�� vip ��Ա����ʱ���Ƿ��ڸ���������ʱ��֮ǰ
                // ���ǣ��򽫸� vip �����������һ�� vip ��Ա
                // �����ǣ��������������������Ա
                // vipId < n ���ڼ�� vip ��Ա�Ƿ��Ѿ�ȫ��ѵ��
                // ��Ϊ���֮��û�� vip ��Ա��findNextVip �������� n
                if (vipId < n && player[vipId].arrive <= table[tid].end) {
                    allocate(tid, vipId);
                    vipId = findNextVip(vipId);
                }
                else {
                    allocate(tid, pid);
                    pid++;
                }
            }
        }
        else {
            // �����ǰ���� vip ����
            if (player[pid].isVip == 0) {
                // ���������Ա���� vip��ֱ�ӽ������������
                allocate(tid, pid);
                pid++;
            }
            else {
                // ���������Ա�� vip
                // ������������ vip ����
                // ����� vip ��Ա�ĵ���ʱ���ڸ� vip ��������ʱ��֮�󣨼�����֮���п��е� vip ������
                // �򽫸� vip ����������� vip ��Ա
                // ���򣬽�����ͨ����������� vip ��Ա
                int tVipId = -1, minT = inf;
                for (int j = 1; j <= k; j++) {
                    if (table[j].isVip == 1 && table[j].end < minT) {
                        minT = table[j].end;
                        tVipId = j;
                    }
                }
                if (tVipId != -1 && player[pid].arrive >= table[tVipId].end) {
                    allocate(tVipId, pid);
                    // if (pid == vipId)
                        vipId = findNextVip(vipId);
                    pid++;
                }
                else {
                    allocate(tid, pid);
                    // if (pid == vipId)
                        vipId = findNextVip(vipId);
                    pid++;
                }
            }
        }
    }

    sort(player.begin(), player.end(), cmp2); // ����ʼѵ����ʱ������
    for (int i = 0; i < n; i++) {
        if (player[i].serve >= en) break;
        int t1 = player[i].arrive, t2 = player[i].serve;
        printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
        printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
        printf("%.0f\n", round((t2 - t1) / 60.0)); // 30 ����Ҫ��λ�� 1 ����
    }
    for (int i = 1; i <= k; i++) {
        if (i > 1) printf(" ");
        printf("%d", table[i].num);
    }
    return 0;
}

