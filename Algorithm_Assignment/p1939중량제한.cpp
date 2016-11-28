#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct point
{
	int t, v;
	point(int n,int m) :t(n), v(m) {}
	bool operator<(const point a)const {
		return this->v < a.v;
	}
};
bool cmp(point a, point b) {
	return a.v > b.v;
}
int n, m;
vector<point> map[10002];
void dfs(int s,int t) {
	priority_queue<point> pq;
	vector<bool> visited(n+1,false);
	int now_s, now_v, i;
	pq.push(point(s, 1000000001));
	while (!pq.empty()) {
		now_s = pq.top().t;
		now_v = pq.top().v;
		pq.pop();
		visited[now_s] = true;
		if (now_s == t) {
			printf("%d\n", now_v);
			return;
		}
		for (i = 0; i != map[now_s].size(); i++) {
			int t1, v1;
			t1 = map[now_s][i].t;
			v1 = map[now_s][i].v;
			if (!visited[t1]) {
				pq.push(point(t1, min(now_v, v1)));
			}
		}
	}
}
int main() {
	FILE *ip;
	ip = fopen("p1939.txt", "r");
	
	int i, j;
	int s, t, v;
	fscanf(ip, "%d %d", &n, &m);
	for (i = 0; i != m; i++) {
		fscanf(ip, "%d %d %d", &s, &t, &v);
		map[s].push_back(point(t,v));
		map[t].push_back(point(s,v));
	}
	for (i = 1; i <= n; i++) {
		sort(map[i].begin(), map[i].end(),cmp);
	}
	fscanf(ip, "%d %d", &s, &t);
	dfs(s, t);


	return 0;
}