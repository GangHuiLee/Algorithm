#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct road
{
	int start, end;
	bool operator<(const road a)const {
		return this->start > a.start;
	}
};
bool cmp(road a, road b) {
	return a.end < b.end;
}
int main() {
	FILE *ip;
	ip = fopen("p13334.txt", "r");
	int n, d;
	int ans=0;
	int i, j, temp, start, end;
	fscanf(ip, "%d", &n);
	vector<road> inp(n);
	priority_queue<road> pq;
	for (i = 0; i != n; i++) { 
		fscanf(ip, "%d%d", &start, &end);
		if (end < start) {
			temp = end;
			end = start;
			start = temp;
		}
		inp[i].start = start;
		inp[i].end = end;
	}
	fscanf(ip, "%d", &d);
	sort(inp.begin(), inp.end(),cmp);
	j = 0;
	i = 0;
	for (; i <inp[n - 1].end;) {
		i = inp[j].end;
		for (; j!=n&&inp[j].end <= i; j++)pq.push(inp[j]);
		while (!pq.empty()&&pq.top().start < i - d)pq.pop();
		if (pq.size()>ans)ans = pq.size();
	}
	printf("%d\n", ans);
	return 0;
}