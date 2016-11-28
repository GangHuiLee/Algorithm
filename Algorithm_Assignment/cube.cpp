#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
using namespace std;
int d[202][202][202];
int go(int w,int l,int h) {
	if (w==h&&h==l)return 1;
	if (d[w][l][h] > 0)return d[w][l][h];
	int a[3];
	a[0] = w;
	a[1] = l;
	a[2] = h;
	sort(a, a + 3);
	w = a[2];
	l = a[1];
	h = a[0];
	if (h == 1)return d[w][l][h] = w*l;
	d[w][l][h] = 800000000;
	//printf("%d %d %d\n", w, l, h);
	for (int i = 1; i <= w / 2; i++)
		d[w][l][h] = min(d[w][l][h],go(i,l,h)+go(w-i,l,h));
	for (int i = 1; i <= w / 2; i++)
		d[w][l][h] = min(d[w][l][h], go(w, i, h) + go(w, l-i, h));
	for (int i = 1; i <= w / 2; i++)
		d[w][l][h] = min(d[w][l][h], go(w, l, i) + go(w, l, h-i));
	d[w][h][l] = d[l][w][h] = d[l][h][w] = d[h][l][w] = d[h][w][l] = d[w][l][h] ;

	return d[w][l][h];
}
int main() {
	freopen("cube.inp", "r", stdin);
	//freopen("cube.out", "w", stdout);
	int n;
	int w, l, h;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d%d",&w,&l,&h);
		printf("%d\n",go(w,l,h));
	}
	return 0;
}