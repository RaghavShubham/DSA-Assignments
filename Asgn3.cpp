# include<iostream>
using namespace std;
class Matrix
{
 
 public:
 void UT(int n,int a[100][100],int m);
 void dsum(int n,int a[100][100],int m);
 void tran(int n,int a[][100],int m);
 void M(int n,int a[][100],int m,int q,int b[][100],int p);
};

 void Matrix:: UT(int n,int a[100][100],int m)
 {
 	 int k=0;
 	  if(n==m)
 	{
 	 for(int i=1;i<n;i++)
 	 	{
 	  		int j=0;
 	  		while (j<i)
 	  		{
 	   			if(a[i][j]!=0)
 	   			{
 	    				k=1;
 	    				break;
 	   			}
 	  		}
 	 	}
 	if(k==0&&m>1&&n>1)
 	cout<<"\n Upper triangular matrix";
 	else 
 	cout<<"\n Not a Upper triangular matrix";
 	}
 	else 
 	cout<<" matrix is not a square matrix";
}
 void Matrix:: dsum(int n,int a[][100],int m)
 {
 	if(m==n)
	{
		int sum=0;
 		for(int i=0;i<n;i++)
  		{
   			sum=sum+a[i][i];
  		}
  	cout<<sum;
 }
 else
  	cout<<" Matrix is not a square matrix";
 }
  void Matrix::tran(int n,int a[][100],int m)
  {
    
   	 for(int i=0;i<m;i++)
   	 {
     		for(int j=0;j<n;j++)
     		{
      			cout<<a[j][i]<<" ";
     		}
    		cout<<"\n";
   	}
  }
 void Matrix:: M(int n,int a[][100],int m,int q,int b[][100],int p)
  {
	int s=0;
   	if(n==p)
		{
   		cout<<"\n Product of matrices= \n";
   		for(int k=0;k<m;k++)
   		{
    			for(int i=0;i<q;i++)
    			{
     				for(int j=0;j<n;j++)
      				{
       					s=s+a[k][j]*b[j][i];
       				}
        	  	cout<<s<<" ";
        		s=0;
       			}
       		cout<<"\n";
  		}	
	}	 
	else 
	cout<<"\nProduct not posiible!";
      	if(m==p&&n==q)
      { 
        	cout<<"\n Sum=\n";
        	 for(int i=0;i<m;i++)
       		{
        		int s=0;
         		for(int j=0;j<n;j++)
          		{
            			s=a[i][j]+b[i][j];
             			cout<<s<<" ";
              		}
             cout<<"\n";

           	}
          	cout<<"\n Difference of matrices= \n";
           for(int i=0;i<m;i++)
       {
        int s=0;
         for(int j=0;j<n;j++)
          {
            s=a[i][j]-b[i][j];
             cout<<s<<" ";
              }
             cout<<"\n";
            }
}
    else
    cout<<"\nSum and Difference : Not possible!";
    }
  
 int main()
{
 int m=0,n=0, p=0,q=0;
 r:
 cout<<"\n Enter the no. of row of 1st matrix";
 cin>>m;
 if(m<0)
 {
 cout<<"/n Wrong input, Enter again";
 goto r;
 }
 y:
  cout<<"\n Enter the no. of column of 1st  matrix";
 cin>>n;
  
 if(n<0)
 {cout<<"/n Wrong input, Enter again";
 goto y;
 }
 o:
  cout<<"\n Enter the no. of row of 2nd  matrix";
   cin>>p;
   
 if(p<0)
 {cout<<"/n Wrong input, Enter again";
 goto o;
 }
  t:
  cout<<"\n Enter the no. of  column of 2nd  matrix";
   cin>>q;
   
 if(q<0)
 {cout<<"/n Wrong input, Enter again";
 goto t;
 }


 int a[100][100],b[100][100];
 cout<<"\n Enter elements of first matrix";
 for(int i=0;i<m;i++)
 {
  for (int j=0;j<n;j++)
  {
   cin>>a[i][j];
  }
 }
 cout<<"\n Enter elements of second  matrix";
 for(int i=0;i<p;i++)
 {
  for (int j=0;j<q;j++)
  {
   cin>>b[i][j];
  }
 }
 int c=1,s;
Matrix ob; 
 while(c!=0)
 {
  cout<<"\n Enter 1 To check whether the matrix are upper triangular or not";
  cout<<"\n Enter 2 to get summation of diagonal elements ";
  cout<<"\n Enter 3 to compute transpose of the matrix";
  cout<<"\n Enter 4 to add ,subtract and mulitiply the matrix";
  cout<<"\n Enter 0 to exit";
  cin>>s;
  c=s;

 
  switch(s)
  {
   case 1: 
          cout<<"\n First matrix is:";
          ob.UT( n, a, m);
          cout<<"\n Second matrix is:"; 
          ob.UT( q, b, p);
           
          break;
   case 2: cout<<"\n Diagonal sum of first matrix:";
          ob.dsum( n, a, m);
            cout<<"\n Diagonal sum of second matrix:";
          ob.dsum( q,b, p);
           break;
   case 3:
          cout<<"\n Transpose of first matrix is:"<<endl;
          ob.tran( m, a, n);

            cout<<"\n Transpose  of second matrix is:"<<endl;
          ob.tran( p,b, q);
          break;
   case 4:
           ob.M( n, a, m, q, b, p);
           break;
   case 0:
          c=0;
          break;
    default:
    cout<<" Invalid input!";
    }
   }
  }

         

