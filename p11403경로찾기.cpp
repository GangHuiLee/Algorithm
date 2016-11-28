#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>
using namespace std;
int inp[102][102];
int ans[102][102];
int v;
void dfs(int s) {
	stack<int> st;
	bool visit[102];
	int now;
	for (int i = 0; i != v; i++)visit[i] = true;
	st.push(s);
	while (!st.empty()) {
		now = st.top();
		st.pop();
		for (int i = 0; i != v; i++) {
			if (visit[i]&&inp[now][i] == 1) {
				st.push(i);
				visit[i] = false;
				ans[s][i] = 1;
			}
		}
	}
}

int main() {
	FILE *ip;
	ip = fopen("p11403.txt", "r");
	int i, j, k;
	fscanf(ip, "%d", &v);
	for (i = 0; i != v; i++) for (j = 0; j != v; j++)fscanf(ip, "%d", &inp[i][j]);
	for (i = 0; i != v; i++)dfs(i);
	for (i = 0; i != v; i++) {
		for (j = 0; j != v; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}