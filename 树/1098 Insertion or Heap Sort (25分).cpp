#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N, heap[maxn], pri[maxn], changed[maxn];

bool isSame(int a[], int b[]) {
	for (int i = 1; i <= N; i++) {
		if (a[i] != b[i]) return false;
	}
	return true;
}

void print(int a[]) {
	for (int i = 1; i <= N; i++) {
		if (i > 1) printf(" ");
		printf("%d", a[i]);
	}
}

void swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void downAdjust(int low, int high) {
	int i = low, j = i * 2, flag = 0;
	while (j <= high) {
		if (j + 1 <= high && heap[j+1] > heap[j]) j++;
		if (heap[i] < heap[j]) {
			swap(heap[i], heap[j]);
			i = j;
			j *= 2;
		}
		else break;
	}
}

void createHeap() {
	for (int i = N / 2; i >= 1; i--) {
		downAdjust(i, N);
	}
}

void heapSort() {
	createHeap();
	int flag = 0;
	for (int i = N; i >= 1; i--) {
		swap(heap[1], heap[i]);
		downAdjust(1, i - 1);
		if (flag == 1) {
			print(heap);
			return;
		}
		if (isSame(heap, changed)) {
			printf("Heap Sort\n");
			flag = 1;
		}
	}
}

bool insertSort() {
	int flag = 0;
	for (int i = 2; i <= N; i++) {
		int x = pri[i];
		int j = i;
		while (j > 1 && x < pri[j-1]) {
			pri[j] = pri[j-1];
			j--;
		}
		pri[j] = x;
		if (flag == 1) {
			print(pri);
			return true;
		}
		if (isSame(pri, changed)) {
			printf("Insertion Sort\n");
			flag = 1;
		}
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &pri[i]);
		heap[i] = pri[i];
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &changed[i]);
	}
	if (!insertSort()) heapSort();
	return 0;
}
