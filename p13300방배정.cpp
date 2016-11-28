#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
struct info
{
	int g, s;
	bool operator<(const info a)const {
		if (this->g == a.g)
			return this->s < a.s;
		return this->g < a.g;
	}
};
int main() {
	freopen("p13300.txt", "r", stdin);
	int n, k;
	int i, j;
	int ans=0;
	info temp;
	info inp[1002];
	scanf("%d %d\n", &n, &k);
	for (i = 0; i != n; i++) scanf("%d %d\n", &inp[i].s, &inp[i].g);
	sort(inp, inp + i);
	for (i = 0; i != n;ans++) {
		temp = inp[i];
		for (j = 0; i+j<n&&j != k&&inp[i+j].g==temp.g&&temp.s==inp[i+j].s; j++) {}
		i += j;
	}
	printf("%d\n", ans);
	return 0;
}