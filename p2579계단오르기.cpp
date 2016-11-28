#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
int inp[302];
int d[302][2];
int main() {
	freopen("p2579.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i != n; i++)scanf("%d", &inp[i+1]);
	d[0][0] = 0;
	d[0][1] = 0;
	d[1][0] = inp[1];
	d[1][1] = inp[1];
	for (int i = 2; i != n+1; i++) {
		d[i][1] = max(d[i - 2][0], d[i - 2][1]) + inp[i];
		if(d[i-1]!=0)
			d[i][0] = d[i - 1][1] + inp[i];
	}
	printf("%d", d[n][0] > d[n][1] ? d[n][0] : d[n][1]);

	return 0;
}