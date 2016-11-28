#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int V, E;
struct edge
{
	int n,s,t, v;
	edge(int n,int a, int b,int c) :n(n),s(a), t(b), v(c) {}
	edge(int a, int b) :t(a), v(b) {}
	edge() :t(), v() {}
	bool operator<(const edge a)const {
		if (this->v == a.v)
			return this->n > a.n;
		return this->v > a.v;
	}
};
bool cmp(edge a, edge b) {
	if (a.v == b.v)
		return a.n < b.n;
	return a.v < b.v;
}
struct vertex
{
	int v, n, value;
	vertex() : v(), n(), value() {}
	vertex(edge e) : v(e.t),n(e.n),value(e.v){}
	bool operator<(const vertex a)const {
		if (this->value == a.value)return this->n > a.n;
		return this->value > a.value;
	}
};
edge arr_edge[100002];
vector<edge> edges[10002];
struct mst
{
	int parent[10002], level[10002];
	mst(int size) :parent(), level() {
		for (int i = 0; i < size; i++)parent[i] = i, level[i] = 1;
	}
	void merge(int v,int w) {
		v = find(v),w=find(w);
		if (level[v] > level[w]) {
			int temp = v;
			v = w;
			w = temp;
		}
		parent[w] = v;
		if (level[w] == level[v])level[v]++;
	}
	int find(int inp) {
		while (parent[inp] != inp)inp = parent[inp];
		return inp;
	}
};
void kruskal() {
	mst krsk = mst(V);
	int ans[10002];
	ans[0] = 0;
	int i, cnt;
	for (i = 0, cnt = 1; cnt < V; i++) {
		edge temp = arr_edge[i];
		int u, v;
		u = temp.s;
		v = temp.t;
		if (krsk.find(u) != krsk.find(v)) {
			ans[cnt] = temp.n;
			cnt++;
			ans[0] += temp.v;
			krsk.merge(u, v);
		}
	}
	printf("Tree edges by Kruskal algorithm: ");
	for (i = 0; i < V; i++)printf("%d\n", ans[i]);
}
void prim(int src) {
	mst pr = mst(V);
	int ans[10002];
	vector<int> dist(V+1,2000000000);
	dist[src] = 0;
	ans[0] = 0;
	int i, cnt=1;
	vertex now, temp;
	priority_queue<vertex> pq;
	for (i = 0; i < edges[src].size(); i++) { pq.push(vertex(edges[src][i])); dist[edges[src][i].t] = edges[src][i].v; }
	while (cnt<V)
	{
		while (pr.parent[pq.top().v] == src||pq.top().value>dist[pq.top().v])pq.pop();
		now = pq.top();
		pr.parent[now.v] = src;
		ans[0] += now.value;
		ans[cnt] = now.n;
		cnt++;
		for (i = 0; i < edges[now.v].size();i++) {
			temp = vertex(edges[now.v][i]);
			if (pr.parent[temp.v] == src||temp.value>=dist[temp.v])continue;
			pq.push(temp);
		}
	}
	printf("Tree edges by Prim algorithm with starting vertex %d: ", src);
	for (i = 0; i < V; i++)
		printf("%d\n", ans[i]);
}
int main() {
	freopen("mst.inp", "r", stdin);
	freopen("mst.out", "w", stdout);
	scanf("%d%d", &V, &E);
	int s, t, v;
	for (int i = 0; i < E; i++) {
		scanf("%d%d%d", &s, &t, &v);
		arr_edge[i] = edge(i,s, t, v);
		edges[s].push_back(edge(i, s, t, v));
		edges[t].push_back(edge(i, t, s, v));
	}
	sort(arr_edge, arr_edge + E,cmp);
	kruskal();
	prim(0);
	prim(V / 2);
	prim(V - 1);
	return 0;
}