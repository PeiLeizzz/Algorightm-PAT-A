#include <bits/stdc++.h>
using namespace std;
int main() {
	double w, t, l, sum = 1.0;
	char r[3];
	for (int i = 0; i < 3; i++) {
		double m;
		scanf("%lf %lf %lf", &w, &t, &l);
		if (w > t) {
			if (w > l) {
				m = w;
				r[i] = 'W';
			}
			else {
				m = l;
				r[i] = 'L';
			}
		}
		else {
			if (t > l) {
				m = t;
				r[i] = 'T';
			}
			else {
				m = l;
				r[i] = 'L';
			}
		}
		sum *= m;
	}
	sum = (sum * 0.65 - 1) * 2;
	printf("%c %c %c %.2f", r[0], r[1], r[2], sum);
}
