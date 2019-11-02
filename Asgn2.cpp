#include<iostream>
using namespace std;
int main()
{
	int k,n,i,s=0,c=0,max,min,max1, a[100]={0},pos,f=0;
	cout<<"Enter the number of students in the class: ";
	cin>>n;
	while(n<0||n>60)
	{
	    cout<<"Enter number of students again: ";
	    cin>>n;
	}
	int m[n];
	cout<<"Enter the marks of the students in the subject 'Data Structures and Algorithms(Enter -1 for Absentees):  "<<endl;
	for(i=0;i<n;i++)
	{
		cin>>m[i];
		while(m[i]>100||m[i]<-1)
		{
		    cout<<"Enter marks again: ";
		    cin>>m[i];
		}
		if(m[i]!=-1)
		{	
			
			s+=m[i];
		}
	}
	cout<<"Choose what you want to see the results for: \n 1 : Average Marks: \n 2 : Highest and lowest marks: \n 3 : Maximum occuring marks: \n 4 : List of absent students: \n 5 : to exit): \n ";
	cin>>k;
	cout<<endl;
	while(k!=5)
	{
	switch (k)
	{
	case 1:
			cout<<"The average of the marks of the whole class is: "<<s/n<<endl;
			break;
	case 2:
			max=m[0];
			min=100;
			for(i=0;i<n;i++)
			{
				if(m[i]>max)
					max=m[i];
				if(m[i]<min&&m[i]!=-1)
					min=m[i];
			}
			cout<<"Maximum marks are: "<<max<<endl;
			cout<<"Minimum marks are: "<<min<<endl;
			break;
	case 3:
			
			for(i=0;i<n;i++)
			{
				a[m[i]]++;
			}
			max1=a[0];
			for(i=0;i<100;i++)
			{
				if(a[i]>max1)
				{
				max1=a[i];
				pos=i;
				}
			}
			for(i=0;i<100;i++)
			{
				if(a[i]==max1)
				{
					cout<<"The marks scored by most of the students are: "<<i<<endl;
				}
			}
			
			break;
	case 4:
				cout<<"The list of students who were absent are: "<<endl;
				
				for(i=0;i<n;i++)
				{
					if(m[i]==-1)
					{
						f=1;
						cout<<i+1<<", ";
					}
				}
				if(f==0)
				cout<<"0";
			break;
	default:
			cout<<"Please choose a number from the menu only!";
	}
	cout<<"Enter choice again: ";
	cin>>k;
	}
	return 0;
}
