#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	//freopen("p1037.txt", "r", stdin);
	int n;
	int a, b;
	int i;
	a = 2000000000;
	b = 1;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &i);
		a = a < i ? a : i ;
		b = b > i ? b : i;
	}
	printf("%d", a*b);
	return 0;
}