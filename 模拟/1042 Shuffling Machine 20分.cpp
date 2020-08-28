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

/* ������������ļ������
freopen("in.txt","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ
freopen("out.txt","w",stdout); //����ض���������ݽ�������out.txt�ļ���
while(cin>> a >> b)
    cout<< a+b <<endl; // ע��ʹ��endl
fclose(stdin);//�ر��ļ�
fclose(stdout);//�ر��ļ�
*/

