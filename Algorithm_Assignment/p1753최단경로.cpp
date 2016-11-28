#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
struct edge
{
	int t, value;
	edge(int a,int b):t(a),value(b) {}
	edge() :t(), value() {}
	bool operator<(const edge a)const {
		return this->value > a.value;
	}
};
bool cmp(edge a, edge b) {
	return a.value < b.value;
}
vector<edge> map[20002];
//int map[1002][1002];
int v, e, s, t;
void bfs() {
	int i, j, n;
	edge now, temp;
	priority_queue<edge> pq;
	vector<bool> visited(v + 1,false);
	vector<int> dist(v+1,100000005);
	dist[s] = 0;
	n = 0;
	pq.push(edge(s, 0));
	while (!pq.empty())
	{
		now = pq.top();
		pq.pop();
		if (dist[now.t]<now.value)continue;
		for (i = 0; i != map[now.t].size(); i++) {
			temp.t = map[now.t][i].t;
			temp.value = now.value + map[now.t][i].value;
			if (!visited[temp.t] && dist[temp.t] > temp.value) {
				dist[temp.t] = temp.value;
				pq.push(temp);
			}
		}
	}
	for (i = 1; i != v + 1; i++) {
		if (dist[i] == 100000005)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
}
int main() {
	freopen("p1753.txt","r",stdin);
	int i, j, k;
	int a, b, c;
	//memset(map, 100000002,sizeof(map));
	
	scanf("%d\n%d\n", &v, &e);
	scanf("%d\n", &s);
	for (i = 0; i != e; i++) {
		scanf("%d %d %d\n", &a, &b, &c);
		map[a].push_back(edge(b, c));
	}
	
	bfs();
	return 0;
}