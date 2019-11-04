#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *next;
}*p = NULL, *top = NULL, *save = NULL,*ptr;

void push(char x)
{
    p = new node;
    p->data = x;
    p->next = NULL;
    if (top == NULL)
    {
        top = p;
    }

    else
    {
        save = top;
        top = p;
        p->next = save;
    }

}

char pop()
{
    if (top == NULL)
    {
        cout<<"underflow!!";
    }

    else
    {
        ptr = top;
        top = top->next;
        return(ptr->data);
        delete ptr;
    }

}

int main()
{
	char ch='y';
    int i;
    char c[1000], a, y, z;
    while(ch=='y')
	{
    cout<<"enter the expression:\n";
    cin>>c;
    for (i = 0; i < strlen(c); i++)
    {
	if ((c[i] == '(') || (c[i] == '{') || (c[i] == '['))
	{
            push(c[i]);
	}
	else
	{
	    switch(c[i])
	    {
		case ')':
  			 	 a = pop();
		         if ((a == '{') || (a == '['))
			 {
			     cout<<"invalid expr!!\n";

			 }
			 break;
		case '}':
  			 y = pop();
			 if ((y == '[') || (y == '('))
			 {
			     cout<<"invalid expr!!\n";

			 }
			 break;
		case ']':
             z = pop();
			 if ((z == '{') || (z == '('))
			 {
			     cout<<"invalid expr!!\n";

			 }
			 break;
	    }
	}
    }
    if (top == NULL)
    {
	cout<<"balanced expr!!\n\n";
    }
    else
    {
	cout<<"string is not valid.!!\n\n";
	}
	cout<<"do you want to continue?\t 1.y 2.n";
	cin>>ch;
 	}


}
