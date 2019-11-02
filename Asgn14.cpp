#include<bits/stdc++.h>
using namespace std;


struct node
{
  int job;
  node *next;
  	
}*f=NULL,*r=NULL,*p=NULL;
class jobq
{   public:
	int j;
	void sq();
	void dsq();
	int delsq();
};
void jobq::sq()
{
	cout<<"\n Enter the job";
	cin>>j;
	struct node *p;
	p=new node;
	if(!p)
	{
		cout<<"\n NO memory allocated ";
		
	}
	else
	{
	p->job=j;
	p->next=NULL;
	if(f==NULL&&r==NULL)
	{
		f=r=p;
	}
	else
	{
		p->next=r;
		r=p;
	}
	}
}
void jobq::dsq()
{
	if(f==NULL && r==NULL)
	{
		cout<<"\n NO jobs present";
	}
	else{
		cout<<"\n Jobs are: ";
		p=r;
		while(p!=NULL)
		{
			cout<<p->job<<" ";
			p=p->next;		
		}
	}
}
int jobq :: delsq()
{   int m;
	if(f==NULL && r==NULL)
	{
		cout<<"\n NO jobs present to delete";
	}
	else if (f!=r)
	   {
	   	p=r;
	   	while(p->next!=f)
	   	{
	   	  p=p->next;
		   }
		f=p;
		
		p=p->next;
		m=p->job;
		free(p);
		return(m);
		
	   }
	   else{
	   	m=f->job;
	   	free(f);
	   	f=r=NULL;
	   	return(m);
	   }

	
}
int main()
{
	int s;
	z:
	cout<<"\n *****Menu*****";
	cout<<"\n Enter 1 to add job";
	cout<<"\n Enter 2 to delete from queue";
	cout<<"\n Enter 3 to display the queue";
	cout<<"\n Enter 4 to exit";
	cin>>s;
	jobq ob;
	switch(s)
	{
		case 1 :
			ob.sq();
			break;
		case 2:
			cout<<"\n The deleted job is"<<ob.delsq();
			break;
		case 3:
			ob.dsq();
			break;
		case 4:
			cout<<"\n Program exited";
			break;
		default:
			cout<<"\n Wrong Input. Enter again";
	}
	if(s!=4)
	goto z;
}


