#include<iostream>
using namespace std;
class node
{
public:
   int x;
    node *next,*prev;
};
class binary

{  public:
    node *head=NULL,*temp=NULL, *head1=NULL,*temp1=NULL, *head2=NULL,*temp2=NULL,*temp3=NULL,*head3=NULL;
     string c;
      
       void insert();
       void binary1();
       void binary2();
       void add();
       void com();
       void comp();
       void display();
};
void binary :: insert()
{  int f;
	do
	{ f=1;
     string q;
	cout<<"\n Enter the binary number ";
	cin>>q;
	c=q;
	for(int i=0;i<c.length();i++)
	{
		if(c[i]=='1'||c[i]=='0');
		else
		{
		f=0;
		cout<<"\n Entera valid binary number";
		break;
	}
	}
	}while(f==0);
	}
void binary :: binary1()
{
   insert();
   	head1=temp1=NULL;
   	head2=temp2=NULL;
   	head=temp=NULL;

	for(int i=0;i<c.length();i++)
	{node  *p=new node;  
	p->x=(int)c[i]-48;
	p->next=NULL;
	p->prev=NULL;
		if(head1==NULL)
		{
			head1=p;
			temp1=head1;
			head1->prev=NULL;
		}
		else{
		temp1->next=p;
		p->prev=temp1;
		temp1=p;}
	}
}
void binary :: binary2()
{
   insert();
   head2=temp2=NULL;
	for(int i=0;i<c.length();i++)
	{ 
        node  *p=new node;
			 p->x=c[i]-48;
			 	p->next=NULL;
	        p->prev=NULL;
		if(head2==NULL)
		{
			head2=p;
			temp2=head2;
			head2->prev=NULL;
		}
		else
		{
		temp2->next=p;
		p->prev=temp2;
		temp2=p;}
	
	}
}
void binary ::add()
{    
int carry=0;
while(temp1!=NULL&&temp2!=NULL)
{ 
    
node  *temp=new node;
  temp->next=NULL;
  temp->prev=NULL;
  
	if(temp1->x+temp2->x==1)
	{   if(carry==0)
		{
		temp->x=1;
		carry=0;
	}
	else{
		temp->x=0;
		carry=1;
	}
	}
	else
	{
		if(temp1->x+temp2->x==0)
		 {
			temp->x=carry;
			carry=0;
		}
		else{
			temp->x=carry;
			carry=1;
		}
	}
	if(head==NULL)
	{
	head =temp;
	head->next=NULL;}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
	}
	temp1=temp1->prev;
	temp2=temp2->prev;
   }
   if(temp1!=NULL||temp2!=NULL)
   {
   	if(temp1!=NULL)
   	{
   		while(temp1!=NULL)
   		{  node *temp=new node;
   			if(temp1->x+carry==2)
   			{
   				temp->x=0;
   				carry=1;
			   }
			else
			{
				temp->x=temp1->x+carry;
				carry=0;
			}
			head->prev=temp;
			temp->next=head;
			head=temp;
			temp1=temp1->prev;
		   }
	   }
	   else
   	{
   		while(temp2!=NULL)
   		{  node *temp=new node;
   			if(temp2->x+carry==2)
   			{
   				temp->x=0;
   				carry=1;
			   }
			else
			{
				temp->x=temp2->x+carry;
				carry=0;
			}
			head->prev=temp;
			temp->next=head;
			head=temp;
			temp2=temp2->prev;
		   }
	   }
   }
   
   if(carry==1)
   {
   	node *temp=new node;
   	temp->x=carry;
   	temp->next=head;
   	head->prev=temp;
   	head=temp;
   	head->prev=NULL;
   }
   display();
}
void binary ::com()
{  int f=0;
    temp=temp1;
	while(temp!=NULL)
	{   
		if(temp->x==0)
		{
			temp->x=1;
		}
		else
		temp->x=0;
		  temp=temp->prev;
		}
	}

void binary :: comp()
{
	com();
	cout<<"\n The one's complement is :";
	head=head1;
	display();
	
	cout<<"\n THe two's complement is :";
	node *head=new node;
     int carry =1;
     while(temp1!=NULL)
     {
         if(temp1->x==1)
         {
             if(carry==0)
              temp1->x=1;
             else
             {
                 temp1->x=0;
                 carry=1;
             }
         }
         else
         {
             temp1->x=carry;
             carry=0;
         }
         temp1=temp1->prev;
     }
     if(carry==1)
     {
         cout<<"1";
     }
     head=head1;
    display();
    

}
void binary :: display()
{  temp=head;
	while(temp!=NULL)
	{
		cout<<temp->x;
		temp=temp->next;
	}

}
int main()
{
	 binary b;
              int m;
              char ch;
             do{    cout<<"\n********MENU******";
                         
                         cout<<"\n Enter 1.for binary addition";
                         cout<<"\n Enter 2. for 1's and 2's compliment of Binary no."; 
                         cout<<"\n Enter 3. To exit";
                         cout<<endl<<"Enter your choice: ";
                         cin>>m;
                         
                         switch(m)
                         {   
                              case 1:   b.binary1(); 
                                        b.binary2();
                                        b.add();
                                                 break;
                              case 2:   
                                        b.binary1(); 
                                        b.comp();
                                        
                                        
                                                 break;  
                              case 3:
                              	        cout<<"\n Program exited";
                              	        break;
                            
                               default: cout<<"Invalid choice. Enter again";
                               
            }
			}while(m!=3);
              }

