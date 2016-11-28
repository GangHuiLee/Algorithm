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
	point(int n, int m) :t(n), v(m) {}
	bool operator<(const point a)const {
		return this->v > a.v;
	}
};
struct from
{
	int s, d;
	from(int n, int m) :s(n), d(m) {}
};
struct edge
{
	
	int s, t;
	edge (int n, int m):s(),t(){
		int temp;
		if (n > m) {
			s = m;
			t = n;
		}
		else {
			s = n;
			t = m;
		}
	}
	bool operator<(edge const a) const{
		if (this->s == a.s)
			return this->t < a.t;
		return this->s < a.s;
	}
};
bool cmp(point a, point b) {
	return a.v > b.v;
}
int V, E, Q;
FILE *ip, *op;
vector<point> map[10002];
void dfs(int s, int t) {
	priority_queue<point> pq;
	vector<bool> visited(V + 1, false);
	vector<int> distance(V + 1, -1);
	vector<edge> ans;
	vector<from> From[10002];
	int now_s, now_v, i;
	int t1, v1;
	distance[s] = 0;
	pq.push(point(s,0));
	while (!pq.empty()) {
		now_s = pq.top().t;
		now_v = pq.top().v;
		//distance[now_s] = now_v;
		pq.pop();
		for (i = 0; i != map[now_s].size(); i++) {
			
			t1 = map[now_s][i].t;
			v1 = now_v+map[now_s][i].v;
			if (distance[t1] ==-1||distance[t1]>=v1) {
				if (distance[t1] != v1) {
					From[t1].clear();
					distance[t1] = v1;
				}
				From[t1].push_back(from(now_s, map[now_s][i].v));
				pq.push(point(t1, v1));
			}
		}
	}
	pq.push(point(t,distance[t]));
	while (!pq.empty()) {
		now_s = pq.top().t;
		now_v = pq.top().v;
		pq.pop();
		for (i = 0; i != From[now_s].size(); i++) {
			t1 = From[now_s][i].s;
			v1 = now_v-From[now_s][i].d;
			if (v1 <= distance[t] / 2) {
				
				ans.push_back(edge(t1,now_s));
				continue;
			}
			pq.push(point(t1,v1));
		}
	}
	sort(ans.begin(),ans.end());
	fprintf(op,"%d %d\n", ans[0].s, ans[0].t);
}
int main() {
	ip = fopen("contact.inp", "r");
	op = fopen("contact.out", "w");
	int T;
	int i, j;
	int s, t, v;
	fscanf(ip, "%d", &T);
	while (T--) {
		fscanf(ip, "%d %d %d", &V, &E, &Q);
		for (i = 0; i != E; i++) {
			fscanf(ip, "%d %d %d", &s, &t, &v);
			map[s].push_back(point(t, v));
			map[t].push_back(point(s, v));
		}
		for (i = 0; i != Q; i++) {
			fscanf(ip, "%d %d", &s, &t);
			dfs(s, t);
		}
		for (i = 1; i <= V; i++) {
			map[i].clear();
		}
	}

	return 0;
}