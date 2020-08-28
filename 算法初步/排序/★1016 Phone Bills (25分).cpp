#include <bits/stdc++.h>
using namespace std;
int charge[24];

struct person {
	char name[22];
	int month, day, hour, minute;
	bool flag;
}people[1005];

bool cmp(person p1, person p2) {
	int s = strcmp(p1.name, p2.name);
	if (s != 0) return s < 0;
	else if (p1.month != p2.month) return p1.month < p2.month;
	else if (p1.day != p2.day) return p1.day < p2.day;
	else if (p1.hour != p2.hour) return p1.hour < p2.hour;
	else return p1.minute < p2.minute;
}

int calculate(int on, int off, int& time, int& money) {
	person temp = people[on];
	while (temp.day < people[off].day || temp.hour < people[off].hour || temp.minute < people[off].minute) {
		time++;
		money += charge[temp.hour];
		temp.minute++;
		if (temp.minute >= 60) {
			temp.hour++;
			temp.minute = 0;
		}
		if (temp.hour >= 24) {
			temp.day++;
			temp.hour = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 24; i++) {
		scanf("%d", &charge[i]);
	}
	int n, m = 0;
	scanf("%d", &n);
	getchar();
	while (n--) {
		person p = people[m];
		char isOnLine[10];
		scanf("%s %d:%d:%d:%d %s", p.name, &p.month, &p.day, &p.hour, &p.minute, isOnLine);
		if (strcmp(isOnLine, "on-line") == 0) {
			p.flag = true;
		}
		else {
			p.flag = false;
		}
		people[m++] = p;
	}
	sort(people, people + m, cmp);
	int on = 0, off, next;
	while (on < m) {
		int need = 0;
		next = on;
		// �жϴ�����û����������
		while (next < m && strcmp(people[on].name, people[next].name) == 0) {
			if (need == 0 && people[next].flag == true) {
				need = 1;
			}
			else if (need == 1 && people[next].flag == false) {
				need = 2;
			}
			next++;
		}
		// ���û����������
		if (need != 2) {
			on = next;  // ֱ�ӵ���һ����(next��ʱ����һ���˵��±�)
			continue;
		}
		printf("%s %02d\n", people[on].name, people[on].month);
		int Allmoney = 0;  // �ܹ���Ǯ
		while (on < next) {
			while (on < next - 1 && !(people[on].flag == true && people[on+1].flag == false)) {
				on++; // ֱ���ҵ������� on-line��off-line
			}
			off = on + 1; // off��on����һ��
			if (off == next) { // �����Ѿ�������е������Ϣ
				on = next;
				break;
			}
			printf("%02d:%02d:%02d ", people[on].day, people[on].hour, people[on].minute);
			printf("%02d:%02d:%02d ", people[off].day, people[off].hour, people[off].minute);
			int time = 0, money = 0;
			calculate(on, off, time, money);
			printf("%d $%.2lf\n", time, money / 100.0);
			Allmoney += money;
			on = off + 1;  // ���һ����ԣ���off+1��ʼ����һ��
		}
		printf("Total amount: $%.2lf\n", Allmoney / 100.0);
	}
	return 0;
}
