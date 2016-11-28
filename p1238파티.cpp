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
vector<edge> map[1002];
int v, e, s;
vector<int> dijkstra(int src) {
	vector<int> dist(v+1,2000000000);
	priority_queue<edge> pq;
	edge now, temp;
	int i, j, k;
	dist[src] = 0;
	pq.push(edge(src, 0));
	while(!pq.empty()){
		now = pq.top();
		pq.pop();
		if (dist[now.target] < now.value)continue;
		for (i = 0; i != map[now.target].size(); i++) {
			temp.target = map[now.target][i].target;
			temp.value = map[now.target][i].value + now.value;
			if (dist[temp.target] > temp.value) {
				dist[temp.target] = temp.value;
				pq.push(temp);
			}
		}
	}
	return dist;
}
int main() {
	freopen("p1238.txt", "r", stdin);
	int i, j, k;
	int a, b, c;
	int ans= 0;
	vector<int> src, temp;
	scanf("%d %d %d", &v, &e, &s);
	for (i = 0; i != e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(edge(b, c));
	}
	src = dijkstra(s);
	for (i = 1; i != v + 1; i++) {
		temp = dijkstra(i);
		src[i] += temp[s];
		ans = ans>src[i]? ans: src[i];
	}
	printf("%d", ans);
	return 0;
}