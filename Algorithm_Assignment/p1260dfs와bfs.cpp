#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;
bool map[1002][1002];
int V, E, S;
void bfs() {
	int now, temp, i, j;
	queue<int> q;
	bool visited[1002];
	memset(visited, false, sizeof(bool)*(V + 1));
	visited[S] = true;
	q.push(S);
	while (!q.empty())
	{
		now = q.front();
		printf("%d ", now);
		q.pop();
		for (i = 1; i != V + 1; i++) {
			if (!visited[i] && map[now][i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
	printf("\n");
}
void dfs() {
	int now, temp, i, j;
	bool flag;
	stack<int> st;
	st.push(S);
	bool visited[1002];
	memset(visited, false, sizeof(bool)*(V + 1));
	visited[S] = true;
	printf("%d ",S);
	while (!st.empty())
	{
 		flag = false;
		now = st.top();	
		for (i = 1; i != V + 1; i++) {
			if (!visited[i] && map[now][i]) {
				st.push(i);
				printf("%d ", i);
				visited[i] = true;
				flag = true;
				break;
			}
		}
		if (!flag)
			st.pop();
	}
	printf("\n");
}
int main() {
	freopen("p1260.txt", "r", stdin);
	int i, j, k, s, t;
	scanf("%d %d %d", &V, &E, &S);
	for (i = 0; i != E; i++) {
		scanf("%d %d", &s, &t);
		map[s][t] = true;
		map[t][s] = true;
	}
	dfs();
	bfs();

	return 0;
}