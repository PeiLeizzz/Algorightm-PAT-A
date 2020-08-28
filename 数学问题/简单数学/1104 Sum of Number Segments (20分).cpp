#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	double sum = 0.0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double t;
		scanf("%lf", &t);
		sum += t * (n - i) * (i + 1);
		// sum += (n - i) * (i + 1) * t; 这种写法 (n - i) * (i + 1)可能会溢出
	}
	// 0.1   0.2   0.3     0.4      0.5
	//  5    4+4  3+3+3  2+2+2+2 1+1+1+1+1
	// 5*1   4*2   3*3     2*4      1*5
	// => (n-i)*(i+1)
	printf("%.2f\n", sum);
	return 0;
}
