#include<iostream>
#include<string>
using namespace std;
int main() {
	int i,cnt;
	char j;
	string inp;
	cin >> inp;
	for (i = 0; i < inp.size();) {
		j = inp[i];
		for (cnt = 0; j == inp[i]; cnt++, i++) {}
		cout << j << cnt;
	}


	return 0;
}