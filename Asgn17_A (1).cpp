#include<bits/stdc++.h>
using namespace std;

class student
{
	public:
	int rno[100];
	int i,n,rn,flag=0;

	 void ins()
 	{
  	  cout <<"enter no.of students attending the training\n";
  	  cin>>n;
	  cout<<"enter the student's roll no. who attended the training \n";
 	  for(i=0;i<n;i++)
 	  {
 	  	m:
 		n:
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
 	  				goto n;
				   }
			   }

		   }
      }


  void linearsort()
  {
  	cout<<"enter r.no. to be checked\n";
  	p:
	  cin>>rn;
  	if(rn<=0)
 	  	{
 	  		cout<<"wrong roll no. insert again\n";
 	  		goto p;
 	  	}
	  for(i=0;i<n;i++)
  	{
  		if(rn==rno[i])
  		{
  			flag=1;
  			cout<<"student did attend the training\n\n\n\n";
		  }

	  }
	  if(flag==0)
	  {
	  		cout<<"student didn't attend the training\n\n\n\n";
	  }
  }

  void sentinelsort()
  {
  	int last = rno[n-1];
    cout<<"enter r.no. to be checked\n";
  	o:
	  cin>>rn;
	  if(rn<=0)
 	  	{
 	  		cout<<"wrong roll no. insert again\n";
 	  		goto o;
 	  	}
	rno[n-1] = rn;
	int i = 0;
	while(rno[i]!=rn)
	{
    i++;
	}
	rno[n-1] = last;
	if( (i < n-1) || (rn == rno[n-1]) )
	{
    cout << " student did attend the training \n\n\n\n";
	}
	else
	{
	    cout << " student was absent for the training\n\n\n\n";
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
	cout<<" 1. Use linear seach \n 2. Use Sentinel linear search\n 3.exit\n";
	 cin>>ch;
		switch(ch)
		{
			case 1: p.linearsort();
				 	break;
			case 2: p.sentinelsort();
				 	break;
			case 3: exit(0);
		}

	}

}
