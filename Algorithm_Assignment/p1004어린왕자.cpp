#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<math.h>
long long go(int x, int y, int r,int a,int b) {
	return pow(a - x, 2) + pow(b - y, 2) - pow(r, 2);
}
int main() {
	freopen("p1004.txt", "r", stdin);
	int t,n;
	scanf("%d", &t);
	int sx, sy, tx, ty;
	int x, y, r,ans;
	while (t--)
	{
		ans = 0;
		scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d%d%d", &x, &y, &r);
			long long a, b;
			a = go(x, y, r, sx, sy), b = go(x, y, r, tx, ty);
			if (a*b < 0)ans++;
		}
		printf("%d\n", ans);
	}

	return 0;
}