#include <bits/stdc++.h>
using namespace std;
char num[10005];

int main() {
	scanf("%s", num);
	int len = strlen(num);
	int i = 0;
	if (num[i] == '-') {
		printf("-");
	}
	i++;
	int ex = 0;  // ex 是指数的数值
	for (; i < len; i++) {
		if (num[i] == 'E') {
			i--;  // 此时i是小数位最后一个数的位置，所以小数位为[1, i]
			break;
		}
	}
	int j = i + 2;
	
	bool f = false;
	if (num[j] == '-') {
		f = true;
	}
	j++;
	for (; j < len; j++) {
		ex = ex * 10 + num[j] - '0';
	}
	/** 其实小数点的位置是确定的，科学计数法小数点位置肯定在2 **/
	for (j = 1; j <= i; j++) {
		if (num[j] == '.') {
			break;  // 此时的j是小数点的位置，整数位有j-1位([1, j-1])，小数位有i-j位([j+1, i])
		}
	}
	
    /** 其实在本题中，如果ex为负，则结果整数为有1个0，紧接着小数位有ex-1个0 **/
	if (f) {
		// f为true代表ex为负，此时小数点需要往前ex位
		if (ex >= j-1) {
			// 此时整数位有j-1位
			// 此时需要在开头增加ex-(j-2)个0，整数位1个0，小数位ex-j+1个0
			printf("0.");
	  		for (int k = 0; k < ex-j+1; k++) {
				printf("0");
			}
			for (int k = 1; k <= i; k++) {
				if (k == j) {
					continue;
				}
				printf("%c", num[k]);
			}
		}
		else {
			// 此时小数点移到j-ex处
			for (int k = 1; k < j-ex; k++) {
				printf("%c", num[k]);
			}
			printf(".");
			for (int k = j-ex+1; k <= i; k++) {
				if (k == j) {
					continue;
				}
				printf("%c", num[k]);
			}
		}
	}
	else {
		// 指数为正数的情况
		if (ex >= i-j) {
			for (int k = 1; k <= i; k++) {
				if (k == j) {
					continue;
				}
				printf("%c", num[k]);
			}
			for (int k = 0; k < ex-(i-j); k++) {
				printf("0");
			}
		}
		else {
			// 整数部分变为j-1+ex位 [1, j+ex] 其中j位是原来的小数点忽略
			for (int k = 1; k <= j+ex; k++) {
				if (k == j) {
					continue;
				}
				printf("%c", num[k]);
			}
			printf(".");
			for (int k = j+ex+1; k <= i; k++) {
				printf("%c", num[k]);
			}
		}
		/**
        上面两种情况可以归为一种，小数点一定加在exp+2的位置上（并且小数点和E之间的数字个数pos-3不能等于exp)
        如果exp > pos-3，则后面可以加0
        **/
	}
	return 0;
}
