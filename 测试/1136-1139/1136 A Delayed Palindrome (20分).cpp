#include <bits/stdc++.h>
using namespace std;
string s1, s2, s3;

string add(string a, string b) {
    int carry = 0;
    int n = a.size();
    string res;
	res.resize(n);
    for (int i = n - 1; i >= 0; i--) {
        int sum = a[i] - '0' + b[i] - '0' + carry;
        res[i] = sum % 10 + '0';
        carry = sum / 10;
    }
    if (carry) res = to_string(carry) + res;
    return res;
}

int main() {
    cin >> s1;
    for (int i = 0; i < 10; i++) {
		s2 = s1;
		reverse(s2.begin(), s2.end());
        if (i == 0 && s1 == s2) {
            cout << s1 << " is a palindromic number.";
            return 0;
        }
        s3 = add(s1, s2);
        cout << s1 << " + " << s2 << " = " << s3 << endl;
		s2 = s3;
		reverse(s2.begin(), s2.end());
        if (s2 == s3) {
            cout << s3 << " is a palindromic number.";
            return 0;
        }
		s1 = s3;
    }
    printf("Not found in 10 iterations.");
    return 0;
}
