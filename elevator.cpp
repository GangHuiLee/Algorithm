#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;
struct person
{
	int f, d, u;
	bool operator<(const person a)const {
		return this->f < a.f;
	}
};
int d[203][502], memo[503][502];
person Person[502];
int p, s;
int go() {
	int i, j, k, l;
	int memo[503][503] = { 0, };
	for (i = 1; i <= p; i++) {
		d[1][i] = 0;
		for (j = 1; j <= p; j++) {
			int f1, f2, h, l;
			f1 = Person[i].f, f2 = Person[j].f;
			if (f1 > f2) {
				l = (f1 - f2)*Person[j].d;
				h = (f2 - 1)*Person[j].u;
				d[1][i] += h < l ? h : l;
			}
			else {
				d[1][i] += (f2 - f1)*Person[j].u;
			}
		}
	}
	for (i = 2; i <= s; i++) {
		int m = i - 1;
		for (j = i; j <= p - s + i; j++) {
			d[i][j] = 2000000000;
			int temp;
			for (m = i - 1; m < j; m++) {
				if (memo[m][j] == 0) {
					temp = d[i - 1][m];
					for (k = j; k <= p; k++)
						temp -= (Person[j].f - Person[m].f)*Person[k].u;
					for (k = m + 1; k < j; k++) {
						int a, b;
						a = (Person[k].f - Person[m].f)*Person[k].u;
						b = (Person[j].f - Person[k].f)*Person[k].d;
						if (a > b) {
							temp -= a;
							temp += b;
						}
					}
					memo[m][j] = d[i - 1][m] - temp;
				}
				temp = d[i - 1][m] - memo[m][j];
				d[i][j] = d[i][j] < temp ? d[i][j] : temp;
			}

		}
	}
	j = d[s][s];
	for (i = s + 1; i <= p; i++)
		j = j < d[s][i] ? j : d[s][i];
	return j;
}
int main() {
	freopen("elevator.inp", "r", stdin);
	freopen("elevator.out", "w", stdout);
	int T;
	scanf("%d", &T);
	Person[0].f = 1;
	while (T--)
	{
		scanf("%d%d", &p, &s);
		//memset(memo, 0, sizeof(memo));
		for (int i = 1; i <= p; i++) {
			scanf("%d%d%d", &Person[i].f, &Person[i].d, &Person[i].u);
		}
		sort(Person, Person + p + 1);
		printf("%d\n", go());
	}


}