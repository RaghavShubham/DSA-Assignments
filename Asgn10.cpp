# include<bits/stdc++.h>
using namespace std;

struct node
{
  char c;
  node *next;
}*nptr = NULL, *top = NULL, *save = NULL,*ptr;
void push(char ch)
{
    nptr= new node;
    nptr->c=ch;
    nptr->next=NULL;
    if(top==NULL)
    {
        top=nptr;
    }
    else 
    {
		save =top;
    	top=nptr;
    	top->next=save;
    }
}
int isEmpty()
{
    if(top == NULL)
     return(1);
    else
     return(0); 
}
char pop()
{
    nptr=new node;
    nptr=top;
    top=top->next;
    char m=nptr->c; 
    free(nptr);
    return(m);
}
int prec(char s)
  {
    switch(s)
    {
      case '/': return(4);
      case '*': return(3);
      case '+': return(2);
      case '-': return(1);
      case '(': return(0);
      default: return(-1);
    }
  }
  int op(int a, int b,char ch)
  {
  	switch(ch)
  	{
  	case '/': return(a/b);
      case '*': return(a*b);
      case '+': return(a+b);
      case '-': return(a-b);	
	  }
  }
int main()
{
    char c[100], d[100];
    cout<<"\n Enter the expression";
    cin>>c;
    char f;
    char z;
    int j=0;
    int nptr;
    int n;
    for(int i=0; i<strlen(c); i++)
    {
        f=c[i];
        switch(f)
        {
            case'(' :
                     push(f);
                     break;
            case ')':
                     while((z=pop())!='(')
                     {
                      d[j++]=z;
                     }
                     break;
            case '+':
            case '-':
            case '*':
            case '/':
                     if(!(isEmpty()))
                     {
                         nptr=prec(f);
                         z=pop();
                         while(nptr<=prec(z))
                         {
                             d[j++]=z;
                             if(!(isEmpty()))
                               z=pop();
                             else
                               break;
                         }
                         if(nptr>prec(z))
                         {
                             push(z);
                         }
                         
                     }
                     push(f);
                     break;

            default:
                    d[j++]=f;
                    n++;
                    
        }
    }
    while(!(isEmpty()))
    {
        d[j++]=pop();    
    }
    d[j]='\0';
    cout<<"\n The postfix expression is"<<d;
    char ch;
    int o=1;
    do
    {
    cout<<"\n Do you want to evaluate the expression 'y''/'n'. ";
    cin>>ch;
    if(ch=='y'||ch=='n')
    {
    	o=0;
	}
	else
	cout<<"\n Invalid input. Enter again";
     }while(o==1);
     if(ch=='y')
	 {
	 	int a[n];
	 	cout<<"\n Enter the values of operands";
	 	for(int i=0;i<n;i++)
	 	{
	 		cin>>a[i];
		 }
		 int h=-1;
		 int s;
		 int e=0;
		 for(int i=0;i<strlen(d);i++)
		 {
		 	f=d[i];
		 	if(isalpha(d[i]))
		 	{
		 		push(f);
		 		h=h+1;
			 }
			 else{
			 	if(e=0)
			 	{
			 		pop();
			 		pop();
			 		s=op(a[h-1],a[h],f);
			   		h=h-1;
			 	}
			 else
			   {
			   	pop();
			   	s=op(a[h],s,ch);
			   }
			 }
			 }
			 cout<<"\n The value of the expression is : "<<s;
		 }
	 }
   
    
