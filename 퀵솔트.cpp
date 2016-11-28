#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stack>
#include<queue>
using namespace std;
struct info
{
	int s, e;
	info(int a, int b) :s(a), e(b) {}
	info() :s(), e() {}
};
void qst2(int *arr, int s, int e) {
	queue<info> q;
	info now;
	int l, r, m, temp;
	q.push(info(s, e));
	while (!q.empty())
	{
		now = q.front();
		s = now.s;
		e = now.e;
		q.pop();
		if (e - s <= 1)continue;
		l = s + 1;
		r = e - 1;
		while (1)
		{
			while (arr[l] < arr[s] && l < e)l++;
			while (arr[r] > arr[s] && r >= s)r--;
			if (l >= r)break;
			temp = arr[l]; arr[l] = arr[r]; arr[r] = temp;
		}
		temp = arr[s]; arr[s] = arr[l - 1]; arr[l - 1] = temp;
		q.push(info(s,l-1));
		q.push(info(l,e));
	}

}
void qst(int *arr,int s,int e) {
	if (e - s <= 1)return;
	int l, r, m, temp;
	l = s+1,r = e - 1;
	m = (s + e) / 2;
	temp = arr[s];
	arr[s] = arr[m];
	arr[m] = temp;
	while (1)
	{
		while (arr[l] < arr[s] && l < e)l++;
		while (arr[r] > arr[s] && r > 0)r--;
		if (l >= r)break;
		temp = arr[l];
		arr[l] = arr[r];
		arr[r] = temp;
	}
	temp = arr[s];
	arr[s] = arr[l-1];
	arr[l-1] = temp;
	qst(arr, s, l - 1);
	qst(arr, l, e);
}
void quick2(int list[], int start, int end) {
	stack<int> s;
	s.push(end);
	s.push(start);
	while (!s.empty()) {
		int start = s.top(); s.pop();
		int end = s.top(); s.pop();
		if (start < end) {
			int x = list[end];
			int i = start - 1;
			for (int j = start; j < end; j++) {
				if (list[j] <= x) {
					i++;
					swap(list[i], list[j]);
				}
			}
			swap(list[i + 1], list[end]);
			s.push(end);
			s.push(i + 2);
			s.push(i);
			s.push(start);
		}
	}
}
int main() {
	int a[8] = { 1,6,43,7,8,12,74,2 };
	qst2(a, 0, 8);
	//quick2(a, 0, 7);
	for (int i = 0; i < 8; i++)printf("%d ", a[i]);
	return 0;
}