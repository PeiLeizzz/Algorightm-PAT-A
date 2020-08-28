#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int, float> res;
  	int k;
  	cin >> k;
  	while (k--) {
	    int e;
	    float c;
	    cin >> e >> c;
	    res[e] += c;
  	}

	cin >> k;
	while (k--) {
	    int e;
	    float c;
	    cin >> e >> c;
	    res[e] += c;
	    if (!res[e]) {
	      	res.erase(e);
	    }
	}

	cout << res.size();
	// map按key值由小到大排序，这里用反向迭代器
	for (map<int, float>::reverse_iterator it = res.rbegin(); it != res.rend(); it++) {
	    cout << " " << it->first << " " << fixed << setprecision(1) << it->second;
	}
	return 0;
}
