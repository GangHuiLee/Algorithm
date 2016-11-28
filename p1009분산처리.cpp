#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;

int main() {
	freopen("p1009.txt", "r", stdin);
	int t, a ,b;
	int i, j;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &a, &b);
		j = 1;
		for (i = 0; i != b; i++) {
			j *= a;
			j %= 10;
		}
		if (j != 0)
			printf("%d\n", j);
		else
			printf("10\n");
	}
}