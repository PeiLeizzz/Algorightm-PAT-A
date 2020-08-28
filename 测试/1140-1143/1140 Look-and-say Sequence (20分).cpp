#include <bits/stdc++.h>
using namespace std;
int main() {
    char d;
    int n;
    scanf("%c %d", &d, &n);
    string res(1, d);
    for (int i = 1; i < n; i++) {
        string str = "";
        char p = res[0];
        int cnt = 0;
        for (int j = 0; j < res.size(); j++) {
            if (res[j] != p) {
                str.push_back(p);
                str += to_string(cnt);
                cnt = 1;
            }
            else cnt++;
            p = res[j];
        }
		if (cnt) {
			str.push_back(p);
			str += to_string(cnt);
		}
        res = str;
    }
    cout << res << endl;
    return 0;
}
