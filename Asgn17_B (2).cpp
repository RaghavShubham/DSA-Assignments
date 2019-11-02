#include<bits/stdc++.h>
using namespace std;

class student
{
	public:
	int rno[100],c;
	int i,n,j,rn,flag=0,k;
		int a=0;

	 void ins()
 	{
  	  cout <<"enter no.of students attending the training\n";
  	  cin>>n;
	  cout<<"enter the student's roll no. who attended the training \n";
 	  for(i=0;i<n;i++)
 	  {
 	  	m:
		l:
		  cin>>rno[i];
 	  	if(rno[i]<=0)
 	  	{
 	  		cout<<"wrong roll no. insert again\n";
 	  		goto m;
		}
 	  		for(int j=0;j<i;j++)
 	  		{
 	  			if(rno[j]==rno[i])
 	  			{
 	  				cout<<"sorry you have already entered this r.no.\n\n";
 	  				goto l;
				   }
			   }

		   }
      }
  	  

      void binarysearch()
      {
      	cout<<"enter r.no. to be checked\n";
  	p:
	  cin>>rn;
  	if(rn<=0)
 	  	{
 	  		cout<<"wrong roll no. insert again\n";
 	  		goto p;
 	  	}

      	int low,high,mid;
      	low=rno[0];
      	high=rno[n-1];

      	mid= floor(mid);
      	while(low<high)
      	{
		  mid=(low+high)/2;
      		if(rn==rno[mid])
      		{
      			flag=1;
      			break;
			  }
 		    else if(rn<rno[mid])
 		    {
 		    	 high = mid -1;

			 }
		    else
		    low=mid+1;

		  }
		  if(flag==1)
		  cout<<"student attended the training\n\n\n";
		  else
		  cout<<"student was absent for training\n\n\n";

	  }

	   	  

		 void fibosearch()
		  {
		  	 cout<<"What do you want to search? \n";
            cin>>j;
            
            int f2 = 0;
            int f1 = 1;
            int f = f2 + f1;
            
            int m=-1;
            
            int x=n;
            
            while (x--)
            {
            	f2 = f1;
            	f1 = f;
            	f  = f2 + f1;
            	m++;
            }
            
            int i=m-2;
            
		    while (f >= 1)
		    {
		        
		        if (rno[i] < j){
		            f  = f1;
		            f1 = f2;
		            f2 = f - f1;
		            i=m-1;
		        	}
		        else if (rno[i] > j){
		            f  = f2;
		            f1 = f1 - f2;
		            f2 = f - f1;
		            i=m-2;
		        }
		        else{		
					cout<<" student did attend the training"<<"\n";
					break;		
				}
		    }	
			 
			} 
		
};

int main()
{
	student p;
	p.ins();

	int ch;
	for(;;)
	{
	 cout<<"----MENU-----\n";
	cout<<" 1. Use binary seach \n 2. Use fibonacci search\n 3.exit\n";
	 cin>>ch;
		switch(ch)
		{
			case 1: p.binarysearch();
				 	break;
			case 2: p.fibosearch();
				 	break;
			case 3: exit(0);
		}

	}
}
