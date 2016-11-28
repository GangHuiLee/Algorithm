#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct point
{
	long long x, y;
	bool operator<(point const a)const {
		if (this->x == a.x)
			return this->y < a.y;
		return this->x < a.x;
	}
};
point inp[1005];
int n;
long long rans;
unsigned long long length(int i, int j) {
	return pow(inp[i].x - inp[j].x, 2) + pow(inp[i].y - inp[j].y, 2);
}
bool search(point target) {
	int s,e,c;
	s = 0; e = n - 1;
	for(;s<=e;) {
		c = (s + e) / 2;
		if (inp[c].x == target.x&&inp[c].y == target.y)
			return true;
		else if (s == e) {
			return false;
		}
		else if (inp[c].x > target.x) {
			e = c - 1;
		}
		else if (inp[c].x == target.x&&inp[c].y>target.y) {
			e = c - 1;
		}
		else if (inp[c].x == target.x&&inp[c].y<target.y) {
			s = c + 1;
		}
		else if(inp[c].x < target.x){
			s = c + 1;
		}
		else break;
	}
	return false;
}
long long check(int a, int b, int c) {
	int temp[3];
	int i, m=0;
	long long ans = 0;
	long long s = inp[a].x*inp[b].y + inp[b].x*inp[c].y + inp[c].x*inp[a].y - inp[a].x*inp[c].y - inp[b].x*inp[a].y - inp[c].x*inp[b].y;
	long long line[3];
	double g,ye,x,y;
	point target;
	temp[0] = a;
	temp[1] = b;
	temp[2] = c;
	if (s < 0)
		s *= -1;
	
	if (s < rans)
		return 0;
	line[0] = length(a, b);
	line[1] = length(b, c);
	line[2] = length(c, a);
	for (i = 1; i != 3; i++) {
		if (line[m] < line[i])
			m = i;
	}
	m = (m + 2) % 3;
	if (line[(m + 2) % 3] + line[(m % 3)]!=line[(m+1)%3])
		return 0;
	target.x = inp[temp[(m+2)%3]].x- inp[temp[(m) % 3]].x+ inp[temp[(m + 1) % 3]].x;
	target.y = inp[temp[(m + 2) % 3]].y - inp[temp[(m) % 3]].y + inp[temp[(m + 1) % 3]].y;
	if (search(target))
		return s;
	else
		return 0;
	
} 
int main() {
	FILE *ip, *op;
	ip = fopen("rectangle.inp", "r");
	op = fopen("rectangle.out", "w");
	int T;
	long long  temp;
	int i, j, k;
	fscanf(ip, "%d", &T);
	while (T--) {
		rans = 0;
		fscanf(ip, "%d", &n);
		for (i = 0; i != n; i++) {
			fscanf(ip, "%lld%lld", &inp[i].x, &inp[i].y);
		}
		sort(inp, inp + n);
		for (i = 0; i != n - 2; i++) {
			for (j = i + 1; j != n - 1; j++) {
				for (k = j + 1; k != n; k++) {
					temp = check(i, j, k);
					rans = max(rans, temp);
				}
			}
		}
		fprintf(op,"%lld\n", rans);
	}


	return 0;
}