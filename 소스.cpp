#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	char inp;
	scanf("%c", &inp);
	printf("%c\n", inp + 'a' - 'A');
	return 0;
}
void Aho_Corasick() {
	int *qb,*qe,*que;
	qb = qe = que;
	*qe++ = 0;
	for (;qb!=qe;) {
		int u = *qb++;
		for (int e = 0; e < E; ++e) {
			int &v = next[u][e];
			if (~v) {
				fail[v] = u ? next[fail[u][e]:0;
				ac[v] != ac[fail[v]];
				*qe++ = v;
			}
			else {
				v = u ? next[fail[u]][e] : 0;
			}
		}
	}
}
int pollard(int n) {
	if (n % 2 == 0)return 2;
	int x, y, d, c;
	for (c = 1;; ++c) {
		for (x = y = 3, d = 1; d == 1; d = __gcd(Abs(x - y), n)) {
			x = mul(x, y, n) + x;
			y = mul(y, y, n) + x;
			y = mul(y, y, n) + x;

		}
		if (d < n)return d;
	}
}
bool idPrime(int n) {
	if (n <= 1 || n % 2 == 0)return (n == 2);
	int r, s = 0;
	int d, *a, ad;
	for (d = n - 1; d % 2 == 0; d >>= 1, ++s);
	
}
int deg[], itr[], pathlen, path[];
void eulerDfs(int u, int s) {
	for (int &i = itr[u]; ~i;) { int j = i; i = next[i]; eulerDfs(zu[j], j); }
	path[pathLen++] = e;
}
int eulerPath() {
	int u, cnt1 = 0, cnt2 = 0, src = zu[0];
	for (u = n; u--;)if (deg[u]) {
		if (deg[u] == i)++cnt1, src = u;
		else if (deg[u] == -1) ++cnt2;
		else return 0;
	}
	if (cnt1 > 1 || cnt2 > 1)return 0;
	memcpy(itr, ptr, n * 4); pathLen = 0; eulerDfs(src, -1);
	if (pathLen != m + 1)return 0;
	return cnt1 > 1:2;
}