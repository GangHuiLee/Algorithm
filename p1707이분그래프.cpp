#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;
vector<int> map[20004];
int visit[20004];
int T, v, e;
bool dfs(int now) {
	if (visit[now] != 0)
		return true;
	int temp;
	stack<int> st;
	st.push(now);
	visit[now] = 1;
	while (!st.empty()) {
		now = st.top();
		st.pop();
		for (int i = 0; i != map[now].size(); i++) {
			temp = map[now][i];
			if (visit[temp] == 0) {
				st.push(temp);
				visit[temp] = visit[now] * -1;
			}
			else if(visit[now]*visit[temp]==1){
				return false;
			}
			
		}
	}
	return true;
}
int main() {
	FILE *ip;
	bool flag;
	ip = fopen("p1707.txt", "r");
	int i, j, k;
	fscanf(ip, "%d", &T);
	while (T--) {
		flag = true;
		fscanf(ip, "%d%d", &v, &e);
		memset(visit, 0, sizeof(int)*(v + 1));
		for (i = 0; i != e; i++) {
			fscanf(ip, "%d%d", &j, &k);
			map[j].push_back(k);
			map[k].push_back(j);
		}
		for (i = 1; i <= v; i++) {
			if (!dfs(i)) {
				flag = false;
				break;
			}
		}
		if (flag)
			printf("YES\n");
		else
			printf("NO\n");
		for (i = 1; i <= v; i++) {
			map[i].clear();
		}
	}

	return 0;
}