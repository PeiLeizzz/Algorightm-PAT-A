#include <bits/stdc++.h>
using namespace std;

// <first, second>: distance, price
pair<double, double> station[505];

int main() {
	int n;
	double Cmax, Distance, Davg;
	scanf("%lf %lf %lf %d", &Cmax, &Distance, &Davg, &n);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf", &station[i].second, &station[i].first);
	}
	// ������������һ��վ�㣬��ʾ�յ�
	station[n].first = Distance;
	station[n].second = 0;
	sort(station, station + n);
	// ̰�Ĳ��ԣ�
	// 1. �������λ����û�п��Լ���(map����key=0�ļ�ֵ��)�ģ����û�У�ֱ��return 0
	// 2. ����У����ȼ��ͣ����ڼ���������ʻ�ķ�Χ�ڡ�������������վ
	//    ����б�֮ǰ����վ�۸�͵ģ�ѡ�����м۸���͵ģ����ϴμ��;͡����ü��ܹ������¸�����վ��������
	//    ���û�б�֮ǰ����վ�۸�͵ģ��ȼ����ͣ�֮�󾭹�ʱ��ѡ��һ���۸���͵Ľ��в���
	//    �����ʻ���������룬·;��û�������ļ���վ����˵���޷�����Ŀ�ĵ�
	
	// ����޼���վ���޷���ʻ
	if (station[0].first != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double mostDisOnce = Cmax * Davg, res = 0, gasVolume = 0;
	int preStation = 0;
	while (preStation < n) {
		//printf("%d\n", preStation);
		int curStation = -1;
		double minPrice = 1e9;
		for (int i = preStation + 1; i <= n && station[i].first <= station[preStation].first + mostDisOnce; i++) {
			if (station[i].second < minPrice) {
				curStation = i;
				minPrice = station[i].second;
				// ������ϴμ����ͼ۵ͣ����˳�ѭ��
				if (minPrice < station[preStation].second) break;
			}
		}
		// ������û�м���վ��˵�������ܵ���
		if (curStation == -1) break;
		// ��preStation��curStation·;���������
		double need = (station[curStation].first - station[preStation].first) / Davg;
		// ���ϴ��ͼ۵�
		if (minPrice < station[preStation].second) {
			// �����ǰ��������need��ֻ���պõ�curStation������
			if (gasVolume < need) {
				res += (need - gasVolume) * station[preStation].second;
				gasVolume = 0;
			}
			else {
				gasVolume -= need;
			}
		}
		// ���ϴ��ͼ۸�
		else {
			// �������䣨ע�ⲻ��Cmax����Ϊ������ܲ��ǿյģ�
			res += (Cmax - gasVolume) * station[preStation].second;
			gasVolume = Cmax - need;
		}
		preStation = curStation;
	}
	if (preStation == n) {
		printf("%.2f", res);
	}
	else {
		printf("The maximum travel distance = %.2f", station[preStation].first + mostDisOnce);
	}
	return 0;
}
