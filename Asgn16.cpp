#include<iostream>
using namespace std;

class pizza{
int order[10];
int max;
int front,rear;

public :
pizza()
{
front=-1,rear=-1;
cout<<"\nEnter Maximum order : ";
cin>>max;
}

int full()
{
  if(((front==0)&&(rear==(max-1)))||(front==(rear+1)%max))
         return 1;
     else
         return 0;
}
int qempty()
{
        if(front==-1)
            return 1;
        else
            return 0;
    }

void add(int a)
{
if(full())
{
cout<<"\nOrder is Full!!!";
}
else{
if(front==-1)
{
front=rear=0;
}
else
{
rear=(rear+1)%max;
}
order[rear]=a;
}
}

void remove()
{
int i;
i=order[front];
      if(front==rear)
	  {
		front=rear=-1;
		}
else
{
front=(front+1)%max;
}
cout<<"\n Order deleted : "<<i;


}

void display()
{
int temp;
temp=front;
if(qempty())
    {
        cout<<"\nNo orders currently\n";

    }
else
{
cout<<"\nThe orders are : \n\n";
while(temp!=rear)
{
cout<<"  "<<order[temp];
temp=(temp+1)%max;
}
cout<<"  "<<order[temp];
}
cout<<endl;
}

};

int main()
{

int ch;
pizza p;
do{
cout<<"\n1. Order \n2. Remove order \n3.Display orders \n4. Exit\n";
cin>>ch;
switch(ch)
{
case 1:int o;
      cout<<"\nEnter Order number : ";
      cin>>o;
      p.add(o);
      break;
case 2:p.remove();
      break;
case 3:p.display();
      break;
}

}while(ch!=4 &&ch<=3);
return 0;

}
