#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
using namespace std;

char inp[12][12];
int main() {
	FILE *ip;
	ip = fopen("p1339.txt", "r");
	int n;
	int i, j, k;
	fscanf(ip, "%d\n", &n);
	for (i = 0; i != n; i++) {
		fscanf(ip, "%s\n", &inp[i]);
	}

	return 0;
}