#include<iostream>
using namespace std;
struct node
{
	int clm,row;
	string status;
	struct node *next ,*prev;
}*head[10],*last[10];

class ticket
{
	public:
		ticket()
		{
			for(int j=0 ; j<10 ; j++)
			{
				head[j]=last[j]=NULL;
				struct node* temp;
				for(int i=1 ; i<=7 ; i++)
				{
					temp=create(i,j+1);
					if(head[j]==last[j] && head[j]==NULL)
					{
						head[j]=last[j]=temp;
						head[j]->next=last[j]->next=NULL;
						head[j]->prev=last[j]->prev=NULL;
					}
					else
					{
						temp->next=head[j];
						head[j]->prev=temp;
						head[j]=temp;
						head[j]->prev=last[j];
						last[j]->next=head[j];
					}
				}
			}	
		}

		node* create(int x,int y)
		{
			struct node*temp;
			temp=new(struct node);	
			if(temp==NULL){
			cout<<"\nMemory not allocated";
			return 0;
		}
		else
		{
			temp->clm=x;
			temp->row=y;
			temp->status="A";
			temp->next=NULL;
			temp->prev=NULL;
			return temp;
		}	

	}
	void book()
	{
		int x,y;
		do{
			cout<<"\nEnter the row and column:\n";
			cin>>x>>y;
			if(x<=0||x>10||y<=0||y>7)
			{	
				cout<<"\n Invalid seat number enter again";
			}
		}while(x<=0||x>10||y<=0||y>7);
		struct node* temp;
		temp=head[x-1];
		for(int i=0 ; i<7 ; i++)
		{
			if(temp->clm==y)
			{
 				if(temp->status=="A")
				{
  					temp->status="B";
 				}
 				else
				{
  					cout<<"\nSomeone got there before you did!!";
 				}
			}
			temp=temp->next;
		}
	display();
	}

void cancel()
{
	int x,y;
	cout<<"\nEnter row and column to cancel booking : ";
	cin>>x>>y;
	struct node* temp;
	temp=head[x-1];
	for(int i=0 ; i<7 ; i++)
	{
		if(temp->clm==y)
		{
 			if(temp->status=="B")
			{
  				temp->status="A";
 			}
 			else
 			{
  				cout<<"\nThe ticket wasn't even booked'!!"<<endl;
 			}
		}
		temp=temp->next;
	}
display();
}

void display()
{
	struct node* temp;
	cout<<"\t";
	for(int k=1; k<=7;k++)
	{
		cout<<" "<<k<<"\t";
	}
	cout<<endl;
	for(int j=0 ; j<10 ; j++)
	{
		temp=last[j];
		cout<<j+1<<"\t";
		for(int i=0 ; i<7 ; i++)
		{
			cout<<"("<<temp->status<<")\t";
			temp=temp->prev;
		}
	cout<<"\n";
	}
}
};

int main()
{
	ticket t;
	int ch;
	do{
 	cout<<"\n1.Book Ticket \n2.Cancel Booking  \n3.Display seat chart. \n4.EXIT";
 	cout<<"\nEnter choice- ";
 	cin>>ch;
 	switch(ch)
	 {
 		case 1:
		 	t.book();
			break;
 		case 2:
		 	t.cancel();
			break;
		case 3:
			t.display();
			break;
		case 4:
			exit(1);
		default:
			cout<<"Enter correct choice!!!"<<endl;
			break;
	 }
	}while(ch!=4);

return 0;
}
