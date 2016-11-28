#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct point
{
	int x, y;
};
int aabs(int a){
	if (a < 0)
		a *= -1;
	return a;
}
bool cmp(point a, point b) {
	if (a.x == b.x)
		return aabs(a.y) > aabs(b.y);
	return a.x < b.x;
}
bool zip(point l, point r) {
	return l.x==r.x;
}
vector<point> inp;
int main() {
	freopen("stains.inp", "r", stdin);
	freopen("stains.out", "r", stdout);
	int t, n;
	vector<point>::iterator it;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		inp.clear();
		inp.resize(n);
		for (int i = 0; i < n; i++) { 
			scanf("%d%d", &inp[i].x, &inp[i].y);
			if (inp[i].y < 0)inp[i].y *= -1;
		}
		sort(inp.begin(), inp.end(), cmp);
		it = unique(inp.begin(), inp.end(),zip);
		inp.erase(it, inp.end());
	}

	return 0;
}