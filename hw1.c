#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main() {
	freopen("1.txt", "r", stdin);
	//freopen("hw1.out", "w", stdout);
	int n, temp;
	int i, j, k, l;
	int bucket[27][1000];
	int b[1000];
	char a[1000][10];
	scanf("%d\n", &n);
	memset(bucket, 0, sizeof(bucket));
	memset(a, 96, sizeof(a));
	for (i=0;i<n;i++)
	{
		scanf("%s", a+i);
		b[i] = i;
	}
	for (i = 2; i > -1; i--) {
		memset(bucket, 0, sizeof(bucket));
		for (j = 0; j != n; j++) {
			temp = (int)(a[b[j]][i] - 96);
			temp = temp < 0 ? 0 : temp;
			bucket[temp][0]++;
			bucket[temp][bucket[temp][0]] = b[j];
		}
		l = 0;
		for (j = 0; j != 27; j++) {
			for (k = 1; k <= bucket[j][0]; k++) {
				b[l] = bucket[j][k];
				l++;
				printf("%s ", a[bucket[j][k]]);
			}
		}
		printf("\n");
	}
	printf("*");
	return 0;
}