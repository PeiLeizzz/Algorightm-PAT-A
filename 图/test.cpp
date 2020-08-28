#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>>& g) {
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

void print(vector<int> g[], int l) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
//	vector<vector<int>> g(10, vector<int>(10, 1));
//	print(g);
//	g.clear();
//	cout << "-----" << endl;
//	print(g);
	vector<int> g[10];
	print(g, 10);
	return 0;
}
