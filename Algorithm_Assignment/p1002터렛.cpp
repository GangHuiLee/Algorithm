#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;

int main() {
	freopen("p1002.txt", "r", stdin);
	int t;
	int x1, y1, r1, x2, y2, r2;
	int ans[4] = { -1,0,1,2 };
	int index;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);
		int rd = r1 > r2 ? r1 - r2 : r2 - r1;
		int rs = r1 + r2;
		int d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		rs *= rs;
		rd *= rd;
		int ret;
		if (rd < d && d < rs)
			ret = 2;
		else if (d == rs || d == rd)
			ret = 1;
		else
			ret = 0;

		if (x1 == x2 && y1 == y2 && r1 == r2)
			ret = -1;
		printf("%d\n", ret);
	}

	return 0;
}