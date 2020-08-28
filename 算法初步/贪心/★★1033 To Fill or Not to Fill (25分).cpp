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
	// 设置虚拟的最后一个站点，以示终点
	station[n].first = Distance;
	station[n].second = 0;
	sort(station, station + n);
	// 贪心策略：
	// 1. 先找起点位置有没有可以加油(map中有key=0的键值对)的，如果没有，直接return 0
	// 2. 如果有，则先加油，【在加满油能行驶的范围内】，找其他加油站
	//    如果有比之前加油站价格低的，选择其中价格最低的，那上次加油就【正好加能够到达下个加油站的油量】
	//    如果没有比之前加油站价格低的，先加满油，之后经过时再选择一个价格最低的进行补油
	//    如果行驶完了最大距离，路途中没有其他的加油站，则说明无法到达目的地
	
	// 起点无加油站，无法行驶
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
				// 如果比上次加油油价低，则退出循环
				if (minPrice < station[preStation].second) break;
			}
		}
		// 距离内没有加油站，说明不可能到达
		if (curStation == -1) break;
		// 从preStation到curStation路途所需的油量
		double need = (station[curStation].first - station[preStation].first) / Davg;
		// 比上次油价低
		if (minPrice < station[preStation].second) {
			// 如果当前油量不足need，只补刚好到curStation的油量
			if (gasVolume < need) {
				res += (need - gasVolume) * station[preStation].second;
				gasVolume = 0;
			}
			else {
				gasVolume -= need;
			}
		}
		// 比上次油价高
		else {
			// 加满油箱（注意不是Cmax，因为油箱可能不是空的）
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
