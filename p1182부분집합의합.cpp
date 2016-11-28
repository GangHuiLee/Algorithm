#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;

int inp[25];
int n, s, ans;
void go(int index,int sum, bool flag) {
	
	if (flag && sum == s) {
		ans++;
	}
	if (index == n)
		return;
	go(index + 1, sum,false);
	go(index + 1, sum + inp[index], true);
}
int main() {
	FILE *ip;
	ip = fopen("p1182.txt", "r");
	
	int i;
	ans = 0;
	fscanf(ip, "%d %d", &n, &s);
	for (i = 0; i != n; i++) fscanf(ip, "%d", &inp[i]);
	sort(inp, inp + n);
	go(1, 0, false);
	go(1, inp[0], true);
	printf("%d", ans);

	return 0;
}