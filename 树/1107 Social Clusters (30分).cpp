#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N;
int stu[maxn], size[maxn], hob[maxn], isRoot[maxn];

void init() {
	memset(hob, 0, sizeof(hob));
	fill(isRoot, isRoot + maxn, -1);
	for (int i = 0; i < N; i++) {
		stu[i] = i;
		size[i] = 1;
	}
}

// ·��ѹ��
int find(int x) {
	if (x != stu[x]) {
		return stu[x] = find(stu[x]);
	}
	return x;
}

// ��ģ�鲢
void connect(int i, int j) {
	int r1 = find(i), r2 = find(j);
	if (r1 == r2) return;
	if (size[r1] < size[r2]) {
		stu[r1] = r2;
		size[r2] += size[r1];
	}
	else {
		stu[r2] = r1;
		size[r1] += size[r2];
	}
}

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &N);
	init();
	for (int i = 1; i <= N; i++) {
		int n;
		scanf("%d: ", &n);
		for (int j = 0; j < n; j++) {
			int h;
			scanf("%d", &h);
			if (hob[h] == 0) {
				hob[h] = i; // �øð��ñ���ӵ��
			}
   			connect(i, find(hob[h]));
		}
	}
	for (int i = 0; i < N; i++) {
		isRoot[find(i)]++; // ÿ�����ڵ�ͳ���������Ǹ���� isRoot Ϊ 0
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		// ������ isRoot[i] != 0 ��Ϊ����� isRoot[0] = 0���޷��ֱ�
		if (isRoot[i] != -1) cnt++;
	}
	printf("%d\n", cnt);
	sort(isRoot, isRoot + N, cmp); // �Ӵ�С����
	for (int i = 0; i < cnt; i++) {
		if (i > 0) printf(" ");
		printf("%d", isRoot[i] + 1); // ע������Ҫ + 1
	}
	return 0;
}

/** �Լ������� �Ƚϸ��� ����Ч
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int N;
int stu[maxn], size[maxn];
vector<int> hob[maxn];
unordered_map<int, int> mp;
vector<int> res;

void init() {
	for (int i = 0; i < N; i++) {
		stu[i] = i;
		size[i] = 1;
	}
}

int find(int x) {
	if (x != stu[x]) {
		return stu[x] = find(stu[x]);
	}
	return x;
}

void connect(int i, int j) {
	//printf("%d %d\n", i, j);
	int r1 = find(i), r2 = find(j);
	if (i == j) return;
	if (size[r1] < size[r2]) {
		stu[r1] = r2;
		size[r2] += size[r1];
		mp.erase(r1);
		mp[r2] = size[r2];
	}
	else {
		stu[r2] = r1;
		size[r1] += size[r2];
		mp.erase(r2);
		mp[r1] = size[r1];
	}
}

int main() {
	scanf("%d", &N);
	init();
	for (int i = 0; i < N; i++) {
		int n, flag = 0;
		scanf("%d: ", &n);
		for (int j = 0; j < n; j++) {
			int h;
			scanf("%d", &h);
			if (hob[h].size() != 0) {
				connect(i, hob[h][0]);
				flag = 1;
			}
			hob[h].push_back(i);
		}
		if (!flag) mp[i] = 1;
	}
	printf("%d\n", mp.size());
	for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		res.push_back(it->second);
	}
	sort(res.begin(), res.end());
	for (vector<int>::reverse_iterator it = res.rbegin(); it != res.rend(); it++) {
		if (it != res.rbegin()) printf(" ");
		printf("%d", *it);
	}
	return 0;
}
*/
