#include <bits/stdc++.h>
using namespace std;
int n, k = 0;
double sum = 0.0;
double tmp = 0.0;
bool isValid(string s) {
	double x = 0.0;
	int i = 0, flag = 1, dot = -1;
	if (s[0] == '-') {
		flag = -1;
		i = 1;
	}
	for (; i < s.size(); i++) {
		char ch = s[i];
		if (ch >= '0' && ch <= '9') {
			if (dot > -1) dot++;
			if (dot > 2) return false; // 小数点后位数大于 2 位
			x = x * 10 + ch - '0';
		}
		else if (ch == '.') {
			if (dot > -1) return false; // 第二次遇到小数点
			dot++;
		}
		else return false;
	}
	x *= flag;
	if (dot > 0) x /= pow(10, dot);
	// else if (dot == 0) return false; 这句话不应该加上 2. 这样也是数字合理的
	
	if (x < -1000 || x > 1000) return false;
	tmp = x;
	return true;
}

int main() {
	// char a[50], b[50];
	// scanf("%s", a);
	// sscanf(a,"%lf",&temp); //将temp以double读入a
	// sprintf(b,"%.2f",temp);//temp按%.2f写到b
	// 再逐位比较 a 和 b
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		tmp = 0.0;
		if (isValid(s)) {
			sum += tmp;
			k++;
		}
		else {
			printf("ERROR: %s is not a legal number\n", s.c_str());
		}
	}
	printf("The average of %d ", k);
	if (k == 1) printf("number ");
	else printf("numbers ");
	printf("is ");
	if (k == 0) cout << "Undefined";
	else printf("%.2f", sum / k);
	return 0;
}
