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
	int ex = 0;  // ex ��ָ������ֵ
	for (; i < len; i++) {
		if (num[i] == 'E') {
			i--;  // ��ʱi��С��λ���һ������λ�ã�����С��λΪ[1, i]
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
	/** ��ʵС�����λ����ȷ���ģ���ѧ������С����λ�ÿ϶���2 **/
	for (j = 1; j <= i; j++) {
		if (num[j] == '.') {
			break;  // ��ʱ��j��С�����λ�ã�����λ��j-1λ([1, j-1])��С��λ��i-jλ([j+1, i])
		}
	}
	
    /** ��ʵ�ڱ����У����exΪ������������Ϊ��1��0��������С��λ��ex-1��0 **/
	if (f) {
		// fΪtrue����exΪ������ʱС������Ҫ��ǰexλ
		if (ex >= j-1) {
			// ��ʱ����λ��j-1λ
			// ��ʱ��Ҫ�ڿ�ͷ����ex-(j-2)��0������λ1��0��С��λex-j+1��0
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
			// ��ʱС�����Ƶ�j-ex��
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
		// ָ��Ϊ���������
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
			// �������ֱ�Ϊj-1+exλ [1, j+ex] ����jλ��ԭ����С�������
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
        ��������������Թ�Ϊһ�֣�С����һ������exp+2��λ���ϣ�����С�����E֮������ָ���pos-3���ܵ���exp)
        ���exp > pos-3���������Լ�0
        **/
	}
	return 0;
}
