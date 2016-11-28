#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
using namespace std;
char inp[11][12][12];
int d[4][2] = { 1,0,0,1,-1,0,0,-1 };
int init[4][2] = { 0,0,0,0,1,0,0,1 };
int plus[4][2] = { 0,1,1,0,0,1,1,0 };
int r, c;
int go(int phase,int direction) {
	if (phase == 11)return 0;
	int x, y;
	int i, j, k;
	x = init[direction][0];
	y = init[direction][1];
	for (;;) {
		
		for (;x>=0&&x<r&&y>=0&&y<c;x+=d[direction][0],y+=d[direction][1]) {
			if (inp[phase - 1][x][y] == '#') {
				inp[phase][x][y] = '#';
				continue;
			}
			else {
				char next = inp[phase][x - d[direction][0]][y - d[direction][1]];
				char now;
				inp[phase][x][y] = inp[phase - 1][x][y];
				switch (next)
				{
				case 'R':
				case 'B':
				case '#':
					inp[phase][x][y] = inp[phase-1][x][y];
					break;
				case '.':
					if (inp[phase - 1][x][y] == 'R' || inp[phase - 1][x][y] == 'B') {
						inp[phase][x - d[direction][0]][y - d[direction][1]] = inp[phase - 1][x][y];
						inp[phase][x][y] = '.';
					}
					else {
						inp[phase][x - d[direction][0]][y - d[direction][1]] = '.';
					}
					break;
				case 'O':
					if (inp[phase - 1][x][y] == 'R')
						return 1;
					else if (inp[phase - 1][x][y] == 'B')
						return 0;
					else {
						inp[phase][x - d[direction][0]][y - d[direction][1]] = 'O';
					}
					break;
				}
			}
		}
		if (plus[direction][0] == 0) {
			x = init[direction][0];
			y += plus[direction][1];
		}
		else {
			x += plus[direction][0];
			y = init[direction][1];
		}
		if (!(x >= 0 && x < r&&y >= 0 && y < c))
			break;
	}
	for (i = 0; i != 4; i++) {
		int ans = go(phase + 1, i);
		if (ans == 1)
			return 1;
	}
	return 0;
}
int main() {
	freopen("p13459.txt", "r", stdin);
	int i, j;
	int h_x, h_y;
	int ans = 0;
	scanf("%d %d\n", &r, &c);
	for (i = 0; i != r; i++)
		scanf("%s\n", &inp[0][i]);
	for (i = 1; i != r; i++) {
		for (j = 1; j != c; j++) {
			if (inp[0][i][j] == 'O') {
				h_y = j;
				h_x = i;
			}
		}
	}
	init[2][0] = r - 1;
	init[3][1] = c - 1;
	for (i = 0; i != 4; i++) {
		ans = go(1, i);
		if (ans == 1)
			break;
	}
	printf("%d\n", ans);
	return 0;
}