#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<stack>
using namespace std;
struct node
{
	int data;
	node *lnode, *rnode;
};
void insert(int d,node* t) {
	if (t->data == d)return;
	else if (t->data > d) { if(t->lnode != NULL)insert(d, t->lnode); }
	else insert(d, t->rnode);
}
void preorder(node *t) {
	stack<node*> st;
	node *now;
	while (!st.empty())
	{
		now = st.top();
		while (now->lnode != NULL)
		{
			printf("%d\n", now->data);
			st.push(now->lnode);
			now = now->lnode;
		}
		if (now->rnode == NULL)st.pop();
		else {
			st.push(now->rnode); 
			now = now->rnode;
		}
	}
}
int main() {


	return 0;
}