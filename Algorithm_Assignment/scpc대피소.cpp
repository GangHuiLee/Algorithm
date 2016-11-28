#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include<string.h>
#include <queue>
using namespace std;
struct edge
{
	int f, t, v;
	edge() :t(),v(){}
	edge(int a, int b,int c) :t(a), v(b), f(c) {}
	bool operator<(const edge a)const {
		if (this->v == a.v)
			return this->t > a.t;
		return this->v > a.v;

	}
};
vector<edge> map[100002];
int dist[100002];
int from[100002];
bool visited[100002];
int n, m, k;
long long F, S;
priority_queue<edge> pq;
void dfs() {
	edge now, temp;
	int i;
	int num = 0;
	pq.push(edge(0, 0, 0));
	while (!pq.empty()){
		now = pq.top();
		pq.pop();
		if (!visited[now.t]) {
			visited[now.t] = true;
		}
		else
			continue;
		
		for (i = 0; i != map[now.t].size(); i++) {
			temp.t = map[now.t][i].t;
			temp.v = now.v + map[now.t][i].v;
			temp.f = from[now.t];
			if (!visited[temp.t] && dist[temp.t] > temp.v) {
				dist[temp.t] = temp.v;
				if(now.t!=0)
					from[temp.t] = from[now.t];
				pq.push(temp);
			}
			else if (dist[temp.t] == temp.v&&from[temp.t] > from[now.t])
				from[temp.t] = from[now.t];

			
		}
	}
	for (i = 1; i != n + 1; i++) {
		S += dist[i];
		F += from[i];
	}
	printf("%lld\n%lld\n", S, F);
}
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int i, j;
	int s, t, v;
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		scanf("%d %d %d", &n, &m, &k);
		F = 0;
		S = 0;
		for (i = 0; i != n+1; i++) {
			map[i].clear();
			visited[i] = false;
			dist[i] = 2000000000;
		}
		while (!pq.empty())pq.pop();
		for (i = 0; i != m; i++) {
			scanf("%d %d %d", &s, &t, &v);
			map[s].push_back(edge(t, v, 0));
			map[t].push_back(edge(s, v, 0));
		}
		for (i = 0; i != k; i++) {
			scanf("%d", &j);
			map[0].push_back(edge(j, 0, j));
			from[j] = j;
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		dfs();
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}