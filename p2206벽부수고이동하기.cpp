#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct point
{
	int x, y, b, t;
};
int r, c;
char map[1002][1002];
bool visited[1002][1002][2];
int d[4][2] = { 1,0,0,1,-1,0,0,-1 };
int bfs() {
	queue<point> q;
	point now, temp;
	now.x = 1;
	now.y = 1;
	now.b = 1;
	now.t = 0;
	q.push(now);
	visited[1][1][0] = true;
	visited[1][1][1] = true;
	while (!q.empty()) {
		now = q.front();
		if (now.x == r&&now.y == c)
			return now.t+1;
		q.pop();
		for (int i = 0; i != 4; i++) {
			temp.x = now.x + d[i][0];
			temp.y = now.y + d[i][1];
			temp.t = now.t + 1;
			if (map[temp.x][temp.y] == '1'|| map[temp.x][temp.y] == '0') {
				if (map[temp.x][temp.y] == '1'&&now.b==1&& visited[temp.x][temp.y][0]==false) {
					temp.b = 0;
					q.push(temp);
					visited[temp.x][temp.y][temp.b]=true;
				}
				else if(map[temp.x][temp.y] == '0' && visited[temp.x][temp.y][now.b]==false){
					temp.b = now.b;
					visited[temp.x][temp.y][temp.b] = true;
					q.push(temp);
				}
			}
		}
	}
	return -1;
}
int main() {
	FILE *ip;
	ip = fopen("p2206.txt", "r");
	int i, j;
	fscanf(ip,"%d %d\n", &r, &c);
	for (i = 1; i != r + 1; i++)fscanf(ip, "%s", map[i] + 1);
	memset(visited, false, sizeof(visited));
	printf("%d\n", bfs());
	return 0;
}