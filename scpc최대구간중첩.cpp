#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include<vector>
#include<algorithm>
#include <stdio.h>
using namespace std;
struct line
{
	int low, high;
	bool operator<(const line a)const {
		if (this->low == a.low)
			return this->high>a.high;
		return this->low < a.low;
	}
};
line inp[100003];
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
	int n;
	int i, j;
	int s, e, c;
	vector<int> ans;
	vector<int> from,now;
	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
		scanf("%d", &n);
		ans.clear();
		for (i = 1; i != n+1; i++) scanf("%d %d", &inp[i].low, &inp[i].high);
		sort(inp+1, inp + n+1);
		from.resize(n+1);
		ans.push_back(-10000002);
		now.clear();
		now.push_back(0);
		from[0] = 0;
		for (i = 1; i != n+1; i++) {
			s = 0; e = ans.size();
			while (s<e) {
				c = (s + e) / 2;
				if (ans[c]<inp[i].high) {
					e = c;
				}
				else {
					s = c + 1;
				}
			}
			
			if (s == ans.size()) {
				ans.push_back(inp[i].high);
				now.push_back(i);
				from[i] = now[s-1];
			}
			else {
				ans[s] = inp[i].high;
				if(s!=0)
					from[i] = now[s-1];
				if (s == 0)
					from[i] = 0;
				now[s] = i;
			}
		}

		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);
		printf("%d\n", ans.size());
		for (j = now[now.size() - 1]; j != 0; j = from[j]) {
			printf("%d ", inp[j].high);
		}
		printf("\n");
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}