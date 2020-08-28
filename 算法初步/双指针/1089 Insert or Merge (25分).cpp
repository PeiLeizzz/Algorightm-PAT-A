#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int c[maxn], n;

bool cmp(int a[]) {
	for (int i = 0; i < n; i++) {
		if (a[i] != c[i]) return false;
	}
	return true;
}

bool insertSort(int a[]) {
	int flag = false;
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i;
		while (j > 0 && a[j-1] > x) {
			a[j] = a[j-1];
			j--;
		}
		a[j] = x;
		if (flag) {
			for (int i = 0; i < n; i++) {
				printf("%d", a[i]);
				if (i < n - 1) printf(" ");
			}
			return true;
		}
		if (cmp(a)) {
			printf("Insertion Sort\n");
			flag = true;
		}
	}
	return false;
}

// ����Ҳ����ֱ����sort����
void merge(int a[], int l1, int r1, int l2, int r2) {
	int i = l1, j = l2, index = 0;
	int temp[maxn];
	while (i <= r1 && j <= r2) {
		if (a[i] < a[j]) temp[index++] = a[i++];
		else temp[index++] = a[j++];
	}
	while (i <= r1) temp[index++] = a[i++];
	while (j <= r2) temp[index++] = a[j++];
	for (int i = 0; i < index; i++) {
		a[l1 + i] = temp[i];
	}
}

void mergeSort(int a[]) {
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2) {
		for (int i = 0; i < n; i += step) {
			int mid = i + step / 2 - 1;
			if (mid >= n) break;
			merge(a, i, mid, mid + 1, min(n - 1, i + step - 1));
		}
		// ����Ŀӵ㣡���鲢����ÿһ���ǰ���һ��������Ԫ�صĹ鲢������ģ����������������еĹ鲢��һ��
		if (flag) {
			for (int i = 0; i < n; i++) {
				printf("%d", a[i]);
				if (i < n - 1) printf(" ");
			}
			return;
		}
		if (cmp(a)) {
			flag = true;
			printf("Merge Sort\n");
		}
	}
}

int main() {
	int a[maxn], b[maxn];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);
	if (!insertSort(a)) mergeSort(b);
	return 0;
}
