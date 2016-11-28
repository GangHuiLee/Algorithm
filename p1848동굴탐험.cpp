#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct edge
{
	int target, value;
	edge(int a, int b) :target(a), value(b) {}
	edge() :target(), value() {}
	bool operator<(const edge a)const {
		return this->value > a.value;
	}
};
vector<edge> map[5002];
int info[5002][5002];
int from[5002];
int v, e, s;
int ans = 200000000;

int dijstra2(int src) {
	vector<int> dist(v + 1, 2000000000);
	priority_queue<edge> pq;
	edge now, temp;
	int i, j, k;
	dist[src] = 0;
	pq.push(edge(src, 0));
	while (!pq.empty()) {
		now = pq.top();
		pq.pop();
		if (dist[now.target] < now.value)continue;
		if (now.target == 1)return now.value;
		for (i = 0; i != map[now.target].size(); i++) {
			temp.target = map[now.target][i].target;
			temp.value = map[now.target][i].value + now.value;
			if (dist[temp.target] > temp.value&&info[now.target][temp.target]!=-1) {
				dist[temp.target] = temp.value;
				pq.push(temp);
			}
		}
	}
	return -1;
}
vector<int> dijkstra(int src) {
	vector<int> dist(v + 1, 2000000000);
	priority_queue<edge> pq;
	edge now, temp;
	int i, j, k;
	dist[src] = 2000000000;
	pq.push(edge(src, 0));
	from[1] = 0;
	while (!pq.empty()) {
		now = pq.top();
		pq.pop();
		if (dist[now.target] < now.value)continue;
		info[from[now.target]][now.target] = -1;
		info[now.target][from[now.target]] = -1;
		k = dijstra2(now.target);
		ans = ans< dist[now.target]+ k ? ans : dist[now.target] + k ;
		for (i = 0; i != map[now.target].size(); i++) {
			temp.target = map[now.target][i].target;
			temp.value = map[now.target][i].value + now.value;
			if (dist[temp.target] > temp.value) {
				from[temp.target] = now.target;
				dist[temp.target] = temp.value;
				pq.push(temp);
			}
		}
	}
	return dist;
}
int main() {
	freopen("p1848.txt", "r", stdin);
	int i, j, k;
	int a, b, c, d;
	vector<int> src, tg;
	scanf("%d %d", &v, &e);
	for (i = 0; i != e; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		map[a].push_back(edge(b, c));
		map[b].push_back(edge(a, d));
	}
	src = dijkstra(1);
	//for (i = 2; i != v + 1; i++) {
	//
	//}
	printf("%d", ans);
	return 0;
}