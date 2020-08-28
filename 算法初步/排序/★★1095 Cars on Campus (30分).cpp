#include <bits/stdc++.h>
using namespace std;

struct car {
	char id[10];
	int time, status;
} carInfo[10005], valid[10005];

int getTime(int h, int m, int s) {
	return h * 3600 + m * 60 + s;
}

bool cmp(car c1, car c2) {
	int res = strcmp(c1.id, c2.id);
	return (res != 0)? res < 0: c1.time < c2.time;
}

bool cmpByTime(car c1, car c2) {
	return c1.time < c2.time;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	getchar();
	for (int i = 0; i < n; i++) {
		int h, m, s;
		char st[5];
		scanf("%s %d:%d:%d %s", carInfo[i].id, &h, &m, &s, st);
		carInfo[i].time = getTime(h, m, s);
		if (strcmp(st, "in") == 0) {
			carInfo[i].status = 0;
		}
		else {
			carInfo[i].status = 1;
		}
	}
	
	sort(carInfo, carInfo + n, cmp);
	map<string, int> allTime; // 存放每辆车的停留总时间
	int maxTime = -1, index = 0;
	for (int i = 1; i < n; i++) {
		if (strcmp(carInfo[i].id, carInfo[i-1].id) == 0 && carInfo[i].status == 1 && carInfo[i-1].status == 0) {
			// 将符合规范的记录加入valid数组（而不用map，因为map的插入事件复杂度为log(N))
			valid[index++] = carInfo[i-1];
			valid[index++] = carInfo[i];
			allTime[carInfo[i].id] += carInfo[i].time - carInfo[i-1].time;
			// 记录最大时间
			maxTime = max(maxTime, allTime[carInfo[i].id]);
		}
	}

    // 将valid数组按照事件顺序排序，必须排序，不然下面会超时
	sort(valid, valid + index, cmpByTime);
	for (int i = 0; i < k; i++) {
		int h, m, t;
		scanf("%d:%d:%d", &h, &m, &t);
		int T = getTime(h, m, t);
		int cnt = 0;
		for (int j = 0; j < index && valid[j].time <= T; j ++) {
			// 符合时间的条件：在T时间前in，在T时间（包含）后out
			if (valid[j].status == 0) cnt++;
			else cnt--;
		}
		printf("%d\n", cnt);
	}
	
	for (auto it = allTime.begin(); it != allTime.end(); it++) {
		if (it->second == maxTime) {
			printf("%s ", it->first.c_str());
		}
	}
	printf("%02d:%02d:%02d", maxTime/3600, maxTime%3600/60, maxTime%60);
	return 0;
}
