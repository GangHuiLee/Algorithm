#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	freopen("p10828.txt", "r", stdin);
	int n, ans;
	stack<int> st;
	string inst;
	scanf("%d\n", &n);
	while (n--)
	{
		cin >> inst;
		//scanf("%s", &inst);
		if (!inst.compare("push")) {
			scanf("%d\n", &ans);
			st.push(ans);
			continue;
		}
		if (!inst.compare("pop")) {
			if (st.empty())
				ans = -1;
			else {
				ans = st.top();
				st.pop();
			}
		}
		else if (!inst.compare("top")) {
			ans = st.empty() ? -1 : st.top();
		}
		else if (!inst.compare("empty")) {
			ans = st.empty()? 1: 0;
		}
		else {
			ans = st.size();
		}
		printf("%d\n", ans);
	}
	return 0;
}