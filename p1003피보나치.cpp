#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int ans1, ans2;
void fibonacci(int n) {
	if (n == 0) {
		ans1++;
		return;
	}
	else if (n == 1) {
		ans2++;
		return;
	}
	else {
		fibonacci(n - 1); 
		fibonacci(n - 2);
		return;
	}
}

int main() {
	int inp,t;

	scanf("%d", &t);
	while (t--)
	{
		ans1 = 0;
		ans2 = 0;
		scanf("%d", &inp);
		fibonacci(inp);
		printf("%d %d", ans1, ans2);
	}
	return 0;
}