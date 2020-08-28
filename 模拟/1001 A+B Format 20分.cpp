#include <bits/stdc++.h>
using namespace std;

int main() {
  long a, b;
  cin >> a >> b;
  string s = to_string(a+b);
  string res = "";
  int t = 1;
  for (int i = s.size()-1; i >= 0; i--) {
    res = s[i] + res;
    if (t % 3 == 0 && i != 0) {
      res = "," + res;
    }
    t++;
  }
  cout << res << endl;
  return 0;
}
