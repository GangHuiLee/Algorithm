#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct con
{
	int v, p;
	con(int a,int b):v(a),p(b){}
	con():v(),p(){ }
};
int go(int inp) {
	queue<con> q;
	con now, temp;
	vector<bool> visited(1000001, false);
	q.push(con(inp,0));
	visited[inp] = true;
	while (!q.empty())
	{
		now = q.front();
		if (now.v == 1)
			return now.p;
		q.pop();
		visited[now.v] = true;
		if (now.v % 2 == 0&&!visited[now.v/2]) {
			q.push(con(now.v / 2, now.p + 1));
		}
		if (now.v % 3 == 0 && !visited[now.v / 3]) {
			q.push(con(now.v / 3, now.p + 1));
		}
		if (now.v > 1 && !visited[now.v - 1]) {
			q.push(con(now.v - 1, now.p + 1));
		}
	}
	return 0;
}
int main() {
	//freopen("p1463.txt", "r", stdin);
	int inp;
	scanf("%d", &inp);
	printf("%d",go(inp));
	return 0;
}