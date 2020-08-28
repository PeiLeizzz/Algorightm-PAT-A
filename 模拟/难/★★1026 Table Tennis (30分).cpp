
#include <bits/stdc++.h>
using namespace std;
const int maxn = 105, inf = 1 << 30;
int n, k, m, st, en;

struct Player {
    int arrive, serve, play, isVip; // 到达时间，开始时间，持续时间，是否 vip
} newPlayer;

vector<Player> player;

struct table {
    int end, num, isVip; // 结束时间，被多少人使用过，是否 vip
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
    // 球员到来的时候 球桌被占用
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
        if (t >= en) continue; // 9 点及以后来的，直接忽略
        newPlayer.arrive = t;
        if (p > 120) newPlayer.play = 7200; // 训练时间不能超过 2 小时
        else newPlayer.play = p * 60; // 转化为以秒为单位
        newPlayer.isVip = v;
        newPlayer.serve = en;
        // 初始开始时间设为 21 点，因为后面可能他等到 21 点以后也没有训练
        // 所以他的开始时间也不会被修改，输出时可以将他跳过
        player.push_back(newPlayer);
    }
    scanf("%d %d", &k, &m);
    for (int i = 1; i <= k; i++) {
        table[i].end = st; // 所有球桌的结束时间初始化为 8 点
    }
    for (int i = 1; i <= m; i++) {
        int id;
        scanf("%d", &id);
        table[id].isVip = 1;
    }
    sort(player.begin(), player.end(), cmp1); // 将球员按达到时间排序
    int pid = 0, n = player.size(), vipId = findNextVip(-1); // id: 下一个球员的下标 vipId: 下一个 vip 球员的下标
    while (pid < n) {
        // 寻找最早空闲的球桌
        int tid = -1, minT = inf;
        for (int j = 1; j <= k; j++) {
            if (table[j].end < minT) {
                minT = table[j].end;
                tid = j;
            }
        }
        if (table[tid].end >= en) break; // 超出最晚时间，其他所有人无法在 9 点之前训练
        if (player[pid].isVip == 1 && pid < vipId) {
            // 如果当前球员是 vip，但是下一个要找的 vip 不是他
            // 说明他在之前已经加入了 vip 训练，则跳过
            pid++;
            continue;
        }

        // 如果是当前是 vip 球桌
        if (table[tid].isVip == 1) {
            // 如果队首是 vip 球员，且还未训练（没被跳过）
            // 则将该球桌分配给他
            if (player[pid].isVip == 1) {
                allocate(tid, pid);
                // if (pid == vipId)
                    vipId = findNextVip(vipId);
                pid++;
            }
            else {
                // 队首不是 vip 球员
                // 检查下一个 vip 球员到达时间是否在该球桌结束时间之前
                // 若是，则将该 vip 球桌分配给下一个 vip 球员
                // 若不是，将该球桌分配给队首球员
                // vipId < n 用于检查 vip 球员是否已经全部训练
                // 因为如果之后没有 vip 球员，findNextVip 函数返回 n
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
            // 如果当前不是 vip 球桌
            if (player[pid].isVip == 0) {
                // 如果队首球员不是 vip，直接将球桌分配给他
                allocate(tid, pid);
                pid++;
            }
            else {
                // 如果队首球员是 vip
                // 检查最早结束的 vip 球桌
                // 如果该 vip 球员的到达时间在该 vip 球桌结束时间之后（即来了之后有空闲的 vip 球桌）
                // 则将该 vip 球桌分配给该 vip 球员
                // 否则，将该普通球桌分配给该 vip 球员
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

    sort(player.begin(), player.end(), cmp2); // 按开始训练的时间排序
    for (int i = 0; i < n; i++) {
        if (player[i].serve >= en) break;
        int t1 = player[i].arrive, t2 = player[i].serve;
        printf("%02d:%02d:%02d ", t1 / 3600, t1 % 3600 / 60, t1 % 60);
        printf("%02d:%02d:%02d ", t2 / 3600, t2 % 3600 / 60, t2 % 60);
        printf("%.0f\n", round((t2 - t1) / 60.0)); // 30 秒需要进位到 1 分钟
    }
    for (int i = 1; i <= k; i++) {
        if (i > 1) printf(" ");
        printf("%d", table[i].num);
    }
    return 0;
}

