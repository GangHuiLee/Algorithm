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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	freopen("input.txt", "r", stdin);

	/* setbuf 함수를 사용하지 않으면, 본인의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	C++에서 printf를 사용할 경우, printf로 출력한 내용이 채점되지 않고 '0점'이 될 수도 있습니다.
	따라서 printf를 사용할 경우 setbuf(stdout, NULL) 함수를 반드시 사용하시기 바랍니다. */
	setbuf(stdout, NULL);

	int T;
	int test_case;
	int i, j;
	int s, t, v;
	scanf("%d", &T);	// Codeground 시스템에서는 C++에서도 scanf 함수 사용을 권장하며, cin을 사용하셔도 됩니다.
	for (test_case = 1; test_case <= T; test_case++) {
		// 이 부분에서 알고리즘 프로그램을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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

		// 이 부분에서 정답을 출력하십시오. Codeground 시스템에서는 C++에서도 printf 사용을 권장하며, cout을 사용하셔도 됩니다.
		printf("Case #%d\n", test_case);
		dfs();
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}