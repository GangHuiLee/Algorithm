#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
int map[102][102];
int d[4][2] = { 1,0,0,1,-1,0,0,-1 };
int n, m;
struct point
{
	int x, y;
	point(int a, int b) :x(a), y(b) {}
	point() :x(), y() {}
};
int bfs() {
	queue<point> q;
	vector<bool> visited(n*m+1,false);
	q.push(point(1,1));
	int i, j = 0;
	point now, temp;
	visited[1] = true;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (i = 0; i != 4; i++) {
			temp.x = now.x + d[i][0];
			temp.y = now.y + d[i][1];
			if (map[temp.x][temp.y] == 0 && !visited[(temp.x - 1)*m + temp.y]) {
				q.push(temp);
				visited[(temp.x - 1)*m + temp.y] = true;
			}
			else if (map[temp.x][temp.y] > 0) {
				if (visited[(temp.x - 1)*m + temp.y])map[temp.x][temp.y] = 0;
				visited[(temp.x - 1)*m + temp.y] = true;
				j++;
			}

		}
	}
	return j;
}
int main() {
	freopen("p2638.txt", "r", stdin);
	int i, j;
	scanf("%d %d", &n, &m);
	memset(map, -1, sizeof(map));
	for (i = 1; i != n + 1; i++)for (j = 1; j != m + 1; j++) { scanf("%d", &map[i][j]); map[i][j] *= 2; }
	for (i = 0; bfs() != 0; i++) {}
	printf("%d", i);
	return 0;
}