#include<bits/stdc++.h>
using namespace std;

class matrix
{
	public:
		int i,j,m,n,count;
		int a[100][100];
		int b[100][100];
		int tr[100][100];

	void mat1()
	{
	 cout<<"enter matrix"<<endl;
r: 	 cout<<"enter no. of rows";
	 cin>>m;
	 if(m<=0)
	 {
	 	cout<<"please enter a proper value\n";
	 	goto r;
	 }
q:	cout<<"enter no. of coloumns";
	 cin>>n;
	 if(n<=0)
	 {
	 	cout<<"please enter a proper value\n";
	 	goto q;
	 }
	count=0;
	for(i=0;i<m;i++)
	{
	 for(j=0;j<n;j++)
		{
		 cout<<"enter element "<<i<<j<<"   ";
		 cin>>a[i][j];
		if(a[i][j]!=0)
		{
			count++;
			b[count][0]=i;
			b[count][1]=j;
			b[count][2]=a[i][j];
		}
		}
	}
	}
	int flag=0;
	void print()
	{
		if(count>(m*n/2))
		{
			cout<<"not a sparce matrix"<<endl;
   			flag=1;
		}
		else
		{
		b[0][0]=m;
		b[0][1]=n;
		b[0][2]=count;
		cout<<"the sparce matrix of given matrix is "<<endl;
		for(i=0;i<count+1;i++)
		{
			for(j=0;j<n;j++)
			{
				cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}
		}
	}
	int r[20]={0};
	void tra()
	{
		if(flag==1)
		{
			cout<<"as sparse don't exist so no transpose.\n";
		}
		else
		{
		for(i=0;i<count+1;i++)
		{
			r[i]=b[i][1];
			b[i][1]=b[i][0];
		}
		
		for(i=0;i<count+1;i++)
		{
			b[i][0]=r[i];
		}
		for(i=0;i<=count;i++)
		{
			for(j=0;j<3;j++)
			{
				tr[i][j]=b[i][j];
			}
		}
		cout<<"the transpose matrix of given matrix is "<<endl;
		for(i=0;i<count+1;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}
		}
	}
	
	void fasttr()
	{
		if(flag==1)
		{
			cout<<"as transpose don't exist so no fast transpose.\n";
		}
		else
		{
		int col_num,location;
		int freq[count+1]={0};
		int pos[count+1]={0};
		for(i=0;i<=count;i++)
		{
			
			freq[b[i][1]]++;
		}
		pos[0]=0;
		for(i=1;i<count;i++)
		{
			pos[i]=pos[i-1]+freq[i-1];
		}
		
		for(i=1;i<=count;i++)
		{
			col_num=pos[b[i][1]];
			location=pos[col_num]+1;
			pos[col_num]++;
			tr[location][0]=b[i][1];
			tr[location][1]=b[i][0];
			tr[location][2]=b[i][2];
		}
		cout<<"the fast transpose of the given matrix is \n";
		for(i=0;i<count+1;i++)
		{
			for(j=0;j<3;j++)
			{
				cout<<tr[i][j]<<" ";
			}
			cout<<endl;
		}
	 }
	}

};

int main()
{
	
	matrix m;
	m.mat1();
	int u;
	char ch='y';
	while(ch=='y')
	{
	
	cout<<"\twhat do you want to do?\n\n";
	cout<<"\t1.print the matrix\n\t2.transpose \n\t3.fast transpose.\n";
	cin>>u;
	switch(u)
	{
	
	case 1: m.print();
		 	break;
	case 2:	m.tra();
		 	break;
	case 3:	m.fasttr();
		 	break;
	
	return 0;
	cout<<"do want to continue?\t Y or N\n";
	cin>>ch;
	}
	}
}

