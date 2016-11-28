#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>
using namespace std;
char map[52][52];
int apt[52][52];
int d[8][2] = {1,0,1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1};
struct point
{
	int x, y, k;
};
point p;
int n, k;
void dfs() {
	stack<point> st;
	point now=p;
	point temp;
	int i;
	now.k = k;
	st.push(now);
	while (!st.empty())
	{	
		now = st.top();
		st.pop();
		for (i = 0 ; i != 8 ; i++) {
			temp.x = now.x + d[i][0];
			temp.y = now.y + d[i][1];
			if (map[temp.x][temp.y]!='\0') {
				if (map[temp.x][temp.y] == 'K') {
					temp.k--;
				}
			}
		}
	}
}
int main() {
	FILE *ip;
	ip = fopen("p2842.txt", "r");
	int i, j;
	fscanf(ip, "%d\n", &n);
	for (i = 1; i != n + 1; i++)fscanf(ip, "%s", map[i] + 1);
	for (i = 1; i != n + 1; i++) {
		for (j = 1; j != n + 1; j++) {
			if (map[i][j] == 'P') {
				p.x = i;
				p.y = j;
			}
			fscanf(ip, "%d", &apt[i][j]);
		}
	}

	return 0;
}