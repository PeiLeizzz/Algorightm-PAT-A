#include <bits/stdc++.h>
using namespace std;

struct account {
	char name[12];
	char pwd[12];
}user[1005];

bool isModified(char pwd[]) {
	int len = strlen(pwd);
	bool flag = false;
	for (int i = 0; i < len; i++) {
		switch(pwd[i]) {
			case '1': {
				pwd[i] = '@';
				flag = true;
				break;
			}
			case '0': {
				pwd[i] = '%';
				flag = true;
				break;
			}
			case 'l': {
				pwd[i] = 'L';
				flag = true;
				break;
			}
			case 'O': {
				pwd[i] = 'o';
				flag = true;
				break;
			}
		}
	}
	return flag;
}

int main() {
	int n;
	scanf("%d", &n);
	int i = 0;
	vector<int> modified;
	for (int i = 0; i < n; i++) {
		scanf("%s %s", user[i].name, user[i].pwd);
		if (isModified(user[i].pwd)) {
			modified.push_back(i);
		}
	}
	int m = modified.size();
	if (m == 0) {
		if (n == 1) {
			printf("There is 1 account and no account is modified");
		}
		else {
			printf("There are %d accounts and no account is modified", n);
		}
	}
	else {
		printf("%d\n", m);
		for (vector<int>::iterator it = modified.begin(); it != modified.end(); it++) {
			printf("%s %s\n", user[*it].name, user[*it].pwd);
		}
	}
	return 0;
}
