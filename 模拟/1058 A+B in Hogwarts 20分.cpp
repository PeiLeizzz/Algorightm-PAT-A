#include <bits/stdc++.h>
using namespace std;

int main() {
	int a1, a2, a3, b1, b2, b3, r1, r2, r3;
	scanf("%d.%d.%d %d.%d.%d", &a1, &a2, &a3, &b1, &b2, &b3);
	printf("%d.%d.%d", ((a3+b3)/29+a2+b2)/17+a1+b1, ((a3+b3)/29+a2+b2)%17 , (a3+b3)%29);
//	int t = (a3 + b3) / 29;
//	r1 = (a3 + b3) % 29;
//	a3 = (a2 + b2 + t); // 这里a3充当临时变量
//	t = a3 / 17;
//	r2 = a3 % 17;
//	a3 = (a1 + b1 + t);
//	r3 = a3;
//	printf("%d.%d.%d", r3, r2, r1);
	return 0;
}
