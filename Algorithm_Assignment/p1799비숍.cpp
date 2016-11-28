#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int N;
int a[20][20];
int d1[30];

int max = -1;


int f(int n) {
	if (n >= 2 * N - 1) {
		return 0;
	}

	int max = -1;
	int y = n < N ? n : N - 1;
	int x = n < N ? 0 : n - (N - 1);
	cout << y << ' ' << x << endl;
	while (y >= 0 && x < N) {
		if (a[y][x] == 1 && d1[x - y + N] == 0) {
			d1[x - y + N] = 1;
			int m = f(n + 2) + 1;
			max = m > max ? m : max;
			d1[x - y + N] = 0;
		}
		x++;
		y--;
	}
	if (max < 0) max = f(n + 2);

	return max;
}

int main(void) {
	FILE *ip;
	bool flag;
	ip = fopen("p1799.txt", "r");
	fscanf(ip,"%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(ip,"%d", &a[i][j]);
		}
	}

	printf("%d\n", f(0) + f(1));

	return 0;
}