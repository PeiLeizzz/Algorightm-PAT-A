#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
int M, N, K;
int main() {
	scanf("%d %d %d", &M, &N, &K);
	while (K--) {
		stack<int> st;
		vector<int> popSequence;
		for (int i = 0; i < N; i++) {
			int t;
			scanf("%d", &t);
			popSequence.push_back(t);
		}
		int current = 0, flag = 0;
		for (int i = 1; i <= N; i++) {
			// 每次 push 前检查栈大小，满了说明无法满足条件
			if (st.size() == M) break;
			else {
				st.push(i);
				// 注意连续判断 while
				while (current < N && !st.empty() && st.top() == popSequence[current]) {
					st.pop();
					current++;
				}
			}
			// pop 序列检查完毕
			if (current == N) {
				flag = 1;
				break;
			}
		}
		flag == 1? printf("YES\n"): printf("NO\n");
	}
	return 0;
}
