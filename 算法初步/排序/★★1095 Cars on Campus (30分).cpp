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
	map<string, int> allTime; // ���ÿ������ͣ����ʱ��
	int maxTime = -1, index = 0;
	for (int i = 1; i < n; i++) {
		if (strcmp(carInfo[i].id, carInfo[i-1].id) == 0 && carInfo[i].status == 1 && carInfo[i-1].status == 0) {
			// �����Ϲ淶�ļ�¼����valid���飨������map����Ϊmap�Ĳ����¼����Ӷ�Ϊlog(N))
			valid[index++] = carInfo[i-1];
			valid[index++] = carInfo[i];
			allTime[carInfo[i].id] += carInfo[i].time - carInfo[i-1].time;
			// ��¼���ʱ��
			maxTime = max(maxTime, allTime[carInfo[i].id]);
		}
	}

    // ��valid���鰴���¼�˳�����򣬱������򣬲�Ȼ����ᳬʱ
	sort(valid, valid + index, cmpByTime);
	for (int i = 0; i < k; i++) {
		int h, m, t;
		scanf("%d:%d:%d", &h, &m, &t);
		int T = getTime(h, m, t);
		int cnt = 0;
		for (int j = 0; j < index && valid[j].time <= T; j ++) {
			// ����ʱ�����������Tʱ��ǰin����Tʱ�䣨��������out
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
