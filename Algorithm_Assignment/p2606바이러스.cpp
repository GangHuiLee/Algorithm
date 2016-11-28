#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct edge
{
	int s, t;
	edge(int a, int b) :s(a), t(b) {}
	edge() :s(){}
};
vector<edge> map[102];
bool visited[102];
void bfs() {
	int now, temp;
	int ans = 0;
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		ans++;
		for (int i = 0; i < map[now].size(); i++)
			if (!visited[map[now][i].t]) { q.push(map[now][i].t); visited[map[now][i].t] = true; }
	}
	printf("%d", ans-1);
}
int main() {
	freopen("p2606.txt", "r", stdin);
	int V, E;
	int i;
	int s, t, v;
	scanf("%d%d", &V, &E);
	for (i = 0; i < E; i++) {
		scanf("%d%d", &s, &t);
		map[s].push_back(edge(s, t));
		map[t].push_back(edge(t, s));
	}
	bfs();
	return 0;
}