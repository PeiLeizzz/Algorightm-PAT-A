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
			// ÿ�� push ǰ���ջ��С������˵���޷���������
			if (st.size() == M) break;
			else {
				st.push(i);
				// ע�������ж� while
				while (current < N && !st.empty() && st.top() == popSequence[current]) {
					st.pop();
					current++;
				}
			}
			// pop ���м�����
			if (current == N) {
				flag = 1;
				break;
			}
		}
		flag == 1? printf("YES\n"): printf("NO\n");
	}
	return 0;
}
