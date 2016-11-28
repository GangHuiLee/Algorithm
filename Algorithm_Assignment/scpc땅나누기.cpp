
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
static char _buffer[100024];
static int _currentChar = 0;
static int _charsNumber = 0;
static inline int rd() {
	if (!_charsNumber || _currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	return _buffer[_currentChar++];
}
static inline int ri() {
	int c, x;
	c = rd();
	while (c <= 32) c = rd();
	x = 0;
	while (c > 32) {
		x *= 10;
		x += c - '0';
		c = rd();
	}
	return x;
}
pair< pair<int, int>, int> P[100001];
int n, bn, rb[262145], br[262145], d[262145];
void upd(int x, int v) {
	x += bn;
	rb[x] = v; br[x] = 1 - v;
	d[x] = 1;
	while (x > 1) {
		x /= 2;
		rb[x] = rb[x * 2] + rb[x * 2 + 1];
		br[x] = br[x * 2] + br[x * 2 + 1];
		d[x] = rb[x * 2] + br[x * 2 + 1];
		if (d[x] < d[x * 2] + br[x * 2 + 1]) d[x] = d[x * 2] + br[x * 2 + 1];
		if (d[x] < rb[x * 2] + d[x * 2 + 1]) d[x] = rb[x * 2] + d[x * 2 + 1];
	}
}
int main() {
	int T; T = ri();
	for (int tc = 1; tc <= T; tc++) {
		n = ri();
		bn = 1; while (bn < n) bn *= 2; bn--;
		for (int i = 0; i < n; i++) {
			P[i].first.first = ri();
			P[i].first.second = ri();
			P[i].second = ri();
		}
		printf("Case #%d\n", tc);
		sort(P, P + n);
		for (int i = 0; i < n; i++) upd(P[i].first.second, P[i].second);
		int res = d[1];
		for (int i = 0; i < n; i++) {
			upd(P[i].first.second, 1 - P[i].second);
			if (res < d[1]) res = d[1];
		}
		printf("%d\n", res);
		for (int i = 1; i <= bn + bn + 1; i++) d[i] = rb[i] = br[i] = 0;
	}
}