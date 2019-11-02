#include<iostream>
using namespace std;
class s
{
	int a[100][100],m,n,i,j,k;
	public: 
		void input()
		{
			cout<<"Enter the size of the matrix: ";
			cin>>m>>n;
			while(m<0||n<0)
			{
				cout<<"Enter size again: ";
				cin>>m>>n;
			}
			cout<<"Enter the elements of the matrix: ";
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					cin>>a[i][j];
				}
			}
		}
		void output()
		{
			for(i=0;i<m;i++)
			{
				cout<<endl;
				for(j=0;j<n;j++)
				{
					cout<<a[i][j]<<" ";
				}
			}
		}
		void saddle()
		{
			int l=0;
			for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{	
					int flag=0;
					for(int k=0;k<n;k++)
					{
						if(a[i][j]>a[i][k])
						{ flag=1;
							break;
						}
						if(a[i][j]<a[k][j])
						{
							flag=1;
							break;
						}
					}
					if(flag==0)
					{
						l=1;
						cout<<endl<<"The saddle point of the matrix is at the location: a["<<i<<"]["<<j<<"]"<<endl;
					}
				}
			}
			if(k==0)
			{
				cout<<"No Saddle Point found!"<<endl;
		  }
		}
};
int main()
{
	s A;
	A.input();
	A.output();
	A.saddle();
	return 0;
}
