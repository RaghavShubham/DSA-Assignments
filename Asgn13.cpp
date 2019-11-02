#include<bits/stdc++.h>
using namespace std;
#define bool int
class NODE
{
  public:
   char data;
   NODE *next;
};
void push(NODE** top_ref, int dat)
{
  NODE *new_node;
  new_node = new NODE;

  if (new_node == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }
  new_node->data  = dat;
  new_node->next = (*top_ref);
  (*top_ref) = new_node;
}

int pop(NODE** top_ref)
{
  char res;
  NODE *top;
  if (*top_ref == NULL)
  {
     printf("Stack overflow \n");
     getchar();
     exit(0);
  }
  else
  {
     top = *top_ref;
     res = top->data;
     *top_ref = top->next;
     free(top);
     return res;
  }
}
bool iMP(char ch1, char ch2)
{
   if (ch1 == '(' && ch2 == ')')
     return 1;
   else if (ch1 == '{' && ch2 == '}')
     return 1;
   else if (ch1 == '[' && ch2 == ']')
     return 1;
   else
     return 0;
}
bool PB(char exp[])
{
   int i = 0;
   NODE *stack = NULL;
   while (exp[i])
   {
      if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
        push(&stack, exp[i]);

      if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
      {
         if (stack == NULL)
           return 0;
         else if ( !iMP(pop(&stack), exp[i]) )
           return 0;
      }
      i++;
   }
   if (stack == NULL)
     return 1; 
   else
     return 0; 
}

int main()
{
  char exp[100] ;
  cout<<"ENTER THE EXPRESSION: ";
  cin>>exp;
  if (PB(exp))
    cout<<"\n Balanced ";
  else
    cout<<"\n Not Balanced ";
  return 0;
}
