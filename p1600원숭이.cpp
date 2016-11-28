#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int map[206][206];
int visited[206][206][32];
struct point
{
	int x, y, v, t;
	bool operator<(const point a) const{
		return this->t > a.t;
	}
};
int d[12][3] = {-1,-2,-1,-2,-1,-1,-2,1,-1,-1,2,-1,1,2,-1,2,1,-1,2,-1,-1,1,-2,-1,1,0,0,0,1,0,-1,0,0,0,-1,0};
int k, r, c;
void bfs() {
	
	int ans = 40000000;
	queue<point> q;
	point now, temp;
	int i;
	now.x = 2;
	now.y = 2;
	now.v = k;
	now.t = 0;
	q.push(now);
	while (!q.empty()) {
		now = q.front();
		q.pop();
		if (now.x == r + 1 && now.y == c + 1) {
			printf("%d\n", now.t);
			return;
		}
		for (i = 0; i != 12 ; i++) {
			temp.x = now.x + d[i][0];
			temp.y = now.y + d[i][1];
			temp.t = now.t + 1;
			temp.v = now.v + d[i][2];
			if (temp.v >= 0 && map[temp.x][temp.y] == 0 && visited[temp.x][temp.y][temp.v] == 0) {
				q.push(temp);
				visited[temp.x][temp.y][temp.v] = temp.t;
				
			}
		}
	}

	printf("-1\n");

}
int main() {
	int i, j;
	FILE *ip;
	ip = fopen("p1600.txt", "r");
	fscanf(ip, "%d\n", &k);
	fscanf(ip, "%d %d\n", &c, &r);
	for (i = 0; i != r + 4; i++) {
		for (j = 0; j != c + 4; j++) {
			map[i][j] = 1;
		}
	}
	for (i = 2; i != r + 2; i++) {
		for (j = 2; j != c + 2; j++) {
			fscanf(ip, "%d", &map[i][j]);
		}
	}
	bfs();

	return 0;
}