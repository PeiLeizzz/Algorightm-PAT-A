#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> res(55);
vector<string> shuffing(55);
vector<string> cards = {"S", "H", "C", "D"};
vector<int> t(55);

void init_res() {
	for (int i = 0; i <= 3; i++) {
		for (int j = 1; j <= 13; j++) {
			res[i * 13 + j] = cards[i] + to_string(j);
		}
	}
  	res[53] = "J1";
  	res[54] = "J2";
}

void print_res() {
	for (int i = 1; i < 55; i++) {
		cout << res[i];
		if (i < 54) {
			cout << " ";
		}
	}
}

int main() {
	int k;
	cin >> k;
	init_res();
	for (int i = 1; i < 55; i++) {
		cin >> t[i];
	}
	while (k--) {
		for (int i = 1; i < 55; i++) {
			shuffing[t[i]] = res[i];
		}
		for (int i = 1; i < 55; i++) {
			res[i] = shuffing[i];
		}
	}
	print_res();
	return 0;
}

/* 关于输入输出文件的语句
freopen("in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
freopen("out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
while(cin>> a >> b)
    cout<< a+b <<endl; // 注意使用endl
fclose(stdin);//关闭文件
fclose(stdout);//关闭文件
*/

