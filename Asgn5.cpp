#include<bits/stdc++.h>
using namespace std;
class strg
{
	string s;
	public: 
		void enter()
		{
			cout<<"Enter a string: ";
			getline(cin,s);
		}
		void freq()
		{
			int c=0,count[26]={0};
			while(s[c]!='\0')
			{
				if(s[c]>='a'&&s[c]<='z')
				{
					count[s[c]-'a']++;
				}
				c++;
			}
			for(int i=0;i<26;i++)
			{
				if(count[i]!=0)
				cout<<(char)(i+'a')<<" occurs "<<count[i]<<" times in the string."<<endl;
			}
		}
		void palindrome()
		{
			int i,j,len,flag=1;
			for(len=0;s[len]!='\0';++len);
			for(i=0,j=len-1;i<len/2;i++,--j)
			{
				if(s[i]!=s[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				cout<<"The string is a palindrome!"<<endl;
			}
			else
			{
				cout<<"The string is not a palindrome."<<endl;
			}
		}
		void chardelete()
		{
			string b;
			b=s;
			char ch;
			cout<<"Enter what character you want to delete: ";
			cin>>ch;
			cout<<"The string after deleting the character from the string is: ";
			for(int i=0;b[i]!='\0';i++)
			{
				if(b[i]==ch)
				{
					b.erase(b.begin() + i);
				}
				cout<<b[i];
			}
			cout<<endl;
		}
		void substring()
		{
			string ca,cb;
			ca=s;
			int start,length;
			cout<<"Enter starting index for replacement: ";
			cin>>start;
			cout<<"Enter length of the string to be replaced: ";
			cin>>length;
			int v = (length+start);
			cout<<"Enter string for replacement: ";
			cin>>cb;
			cout<<"The new string is:";
			ca.replace(start,v, cb);
			cout<<ca;
			
		}
		
};
int main()
{
	strg a;
	a.enter();
	a.freq();
	a.palindrome();
	a.chardelete();
	a.substring();
	return 0;
}
