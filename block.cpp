#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct rect
{
	int x, y, p, q;
};
struct point
{
	int x, y;
};
rect inp[10002];
int t, n;
bool cmp_x(rect a, rect b) {
	if (a.x == b.x)
		return a.p < b.p;
	return a.x < b.x;
}
bool cmp_y(rect a, rect b) {
	if (a.y == b.y)
		return a.q < b.q;
	return a.y < b.y;
}
int sum(vector<int> &tree,int i) {
	int ans = 0;
	while (i > 0) {
		ans = ans>tree[i]? ans: tree[i];
		i -= (i & -i);
	}
	return ans;
}
void update(vector<int> &tree,int i, int num) {
	while (i <= n) {
		tree[i] = tree[i]>num? tree[i]: num;
		i += (i & -i);
	}
}
bool down() {
	inp[0].x = -1;
	inp[0].p = 2000000002;
	inp[0].y = 0;
	inp[0].q = 0;
	sort(inp, inp + n + 1,cmp_y);
	bool result = false;
	for (int i = 1; i <= n; i++) {
		int s = inp[i].x, e = inp[i].p;
		int h = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (!(inp[j].p <= s || inp[j].x >= e)) {
				if(inp[j].q<inp[i].y)
					h = h > inp[j].q ? h : inp[j].q;
				else break;
			}
		}
		if (h > -1) {
			inp[i].q += h - inp[i].y;
			inp[i].y = h;
			result = true;
		}
	}
	return result;
}
bool left() {
	inp[0].y = -1;
	inp[0].q = 2000000002;
	inp[0].x = 0;
	inp[0].p = 0;
	sort(inp, inp + n + 1, cmp_x);
	bool result = false;
	for (int i = 1; i <= n; i++) {
		int s = inp[i].y, e = inp[i].q;
		int h = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (!(inp[j].q <= s || inp[j].y >= e)) {
				if(inp[j].p<inp[i].x)
					h = h > inp[j].p ? h : inp[j].p;
				else break;
			}
		}
		if (h > -1) {
			inp[i].p += h - inp[i].x;
			inp[i].x = h;
			result = true;
		}
	}
	return result;
}
int main() {
	freopen("block.inp", "r", stdin);
	//freopen("block.out", "w", stdout);
	
	scanf("%d", &t);
	while (t--)
	{
		int r,c;
		scanf("%d", &n);
		r = -1;
		c = -1;
		for (int i = 1; i <= n; i++)scanf("%d%d%d%d",&inp[i].x,&inp[i].y,&inp[i].p,&inp[i].q);
		while (down()|left()) {}
		for (int i = n; i >= 1; i--) {
			r = r > inp[i].p ? r : inp[i].p;
			c = c > inp[i].q ? c : inp[i].q;
		}
		printf("%d %d\n", r, c);
	}

	return 0;
}