#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
int main() {
	//freopen("p8462.txt", "r", stdin);
	int n;
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 0; j != i; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}