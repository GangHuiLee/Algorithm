#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <cmath>
#include<vector>
using namespace std;
vector<long long> inp;
vector<long long> st;
long long init(vector<long long> &tree, int node, int start, int end) {
	if (start == end)
		return tree[node] = inp[start];
	else
		return tree[node] = init(tree, node * 2, start, (start + end) / 2) + init(tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
void update(vector<long long> &tree, int node, long long value, int index, int start, int end) {

	if (index < start || index > end) return;
	tree[node] = tree[node] + value;
	if (start != end) {
		update(tree, node * 2, start, (start + end) / 2, index, value);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	}
}
long long sum(vector<long long> &tree, int node, int start, int end, int left, int right) {
	long long result;
	if (left>end || right<start) {
		return 0;
	}
	else if (left <= start&&end <= right) {
		return result = tree[node];
	}
	else {
		return result = sum(tree, node * 2, start, (start + end) / 2, left, right) +
			sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	}
}
int main() {
	FILE *ip;
	ip = fopen("p2042.txt", "r");
	int i, j;
	int n, m, k;
	int a, b, d;
	long long c;
	fscanf(ip,"%d %d %d", &n, &m, &k);
	inp.resize(n + 1);
	int h = (int)ceil(log2(n));
	st.resize((1 << (h + 1)));
	for (i = 1; i <= n; i++)fscanf(ip,"%d", &inp[i]);
	init(st, 1, 0, n-1);
	for (i = 0; i != m + k; i++) {
		fscanf(ip,"%d", &a);
		if (a == 1) {
			fscanf(ip,"%d %lld", &b, &c);
			update(st, 1, c-inp[b], b, 0, n-1);
		}
		else {
			fscanf(ip,"%d %d", &b, &d);
			printf("%lld\n", sum(st, 1, 0, n-1, b, d));
		}
	}
	return 0;
}