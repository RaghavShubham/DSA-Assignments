#include<iostream>
using namespace std;
int main()
{
 int m,a,b,l=0;
  x:
 cout<<"Enter total no of students\n";
 cin>>m;
    if(m<0)
   {
    cout<<"\n , Invalid Input, Enter number of students Again= ";
    goto x;
  }
  y:
  cout<<"Enter no of students who play cricket\n";
  cin>>a;
     if(a<0&& a>m)
   {
    cout<<"\n  Invalid Input, Enter Again,";
    goto y;
  }
int A[a];
 cout<<"Enter roll no of students who play cricket \n";
  for(int i=0;i<a;i++)
 {t:
   cin>>A[i];
   if(A[i]<=0&&A[i]>m)
   {
    cout<<"\n Invalid Input, Enter Again= ";
    goto t;
  }
  }
   z:
 cout<<"Enter  no of students who play badminton= \n";
 cin>>b;
     if(b<0&&b>m)
   {
    cout<<"\n n, Invalid Input, Enter Again= ";
    goto z;
  }
int B[b];
 cout<<"Enter roll no of students who play  badminton =  \n";
for(int i=0;i<b;i++)
{ f:
 cin>>B[i];
    if(B[i]<=0&& B[i]>m)
   {
    cout<<"\n Invalid Input, Enter Again= ";
    goto f;
  }
  }

 int C[a+b];
cout<<"Students who play any game: \n";
int k=0;
for(int i=0;i<a;i++)
{
int c=0;
 for(int j=0;j<b;j++)
  {
    if(A[i]==B[j])
    {
      c=1;
      C[k++]=A[i];
    }
  }
  if(c==0)
  {
    l=1;
    cout<<A[i]<<"  ";
  }
}
  for(int j=0;j<b;j++)
  {
    cout<<B[j]<<"  ";
  }
  if(b==0&&l==0)
  {
    cout<<" No One";
  }

cout<<"\n Students who play both cricket and badminton: ";
 for(int i=0;i<k;i++)
    {
     cout<<C[i]<<"  ";
}

if(k==0)
cout<<" No One plays both!";

cout<<"\n  Students who play only cricket: ";
 l=0;
 for(int i=0;i<a;i++)
 { int c=0;
  for(int j=0;j<k;j++)
  {
   if(A[i]==C[j])
     c=1;
  }
  if(c==0)
  {
   cout<<A[i]<<" ";
   l=1;
   }
}
if(l==0)
cout<<" No One plays only cricket!";
 l=0;
cout<<"\n  Students who play only badminton";
 for(int i=0;i<b;i++)
 { int c=0;
  for(int j=0;j<k;j++)
  {
   if(B[i]==C[j])
     c=1;
  }
  if(c==0)
  {l=1;
   cout<<B[i]<<" ";
  }
}

if(l==0)
cout<<" No One plays only badminton";
l=0;

cout<<"\n students who don't play any game: ";
for(int i=1;i<=m;i++)
{int c=0;
 for(int j=0;j<a;j++)
  if(i==A[j])
 c=1;
  for(int j=0;j<b;j++)
  if(i==B[j])
 c=1;
  if(c==0)
  {l=1;
 cout<<i<<" ";
 }
}

if(l==0)
cout<<" None!";

}
