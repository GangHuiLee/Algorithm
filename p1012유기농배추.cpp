#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int map[52][52];
int d[4][2] = { 1,0,0,1,-1,0,0,-1 };
struct point
{
	int x, y;
	point(int a,int b):x(a),y(b){}
	point() :x(), y() {}
};
void bfs(int x,int y) {
	queue<point> q;
	point now, temp;
	q.push(point(x, y));
	map[x][y] = 0;
	while (!q.empty()) {
		now = q.front();
		q.pop();
		for (int i = 0; i != 4; i++) {
			temp.x = now.x + d[i][0];
			temp.y = now.y + d[i][1];
			if (map[temp.x][temp.y] == 1) {
				q.push(temp);
				map[temp.x][temp.y] = 0;
			}
		}
	}
}
int main() {
	freopen("p1012.txt", "r", stdin);
	int r, c, k;
	int T;
	int i, j;
	int a, b;
	int ans;
	scanf("%d", &T);
	while (T--) {
		ans = 0;
		memset(map, 0, sizeof(map));
		scanf("%d %d %d", &c, &r, &k);
		for (i = 0; i != k; i++) {
			scanf("%d %d", &a, &b);
			map[b][a] = 1;
		}
		for (i = 1; i != r + 1; i++) {
			for (j = 1; j != c + 1; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}