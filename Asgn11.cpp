#include<bits/stdc++.h>
using namespace std;

class node{
   public:
	char a;
	node * next;
	node(){
		a='0';
		next=NULL;
	}
};

class Stack{
	node* top;
   public:
	Stack(){
		top=NULL;
	}
	void push(char x){
		node * temp=new node;
		temp->a=x;
		temp->next=top;
		top=temp;
	}
	char pop(){
		char c=top->a;
		top=top->next;
		return c;
	}
	char dis(){
		return (top->a);
	}
	int isempty(){
		if(top==NULL)	return 1;
		else		return 0;
	}
};

string inpost(string s){
	int i=0;
	string a="";
	Stack st;
	char c;

	while(i<s.size()){
		if((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='z'))	a+=s[i];
		else if(s[i]=='*' || s[i]=='/')	{while(!st.isempty() && st.dis()!='(' && st.dis()!='+' && st.dis()!='-')	a+=st.pop(); st.push(s[i]);}
		else if(s[i]=='(')	st.push(s[i]);
		else if(s[i]==')')	{while(st.dis()!='(')	a+=st.pop(); st.pop();}
		else	{while(!st.isempty() && st.dis()!='(')	a+=st.pop(); st.push(s[i]);}
		if(i==s.size()-1){
			while(!st.isempty())	{a+=st.pop();}
		}
		i++;
	}

	return a;
}

string postin(string s){
	string a,b,ans,str;
	stack<string> st;
	for(int i=0;i<s.size();i++){
		if((s[i]>='0' && s[i]<='9')||(s[i]>='a' && s[i]<='z'))	str=s[i],st.push(str);
		else{
			a=st.top();st.pop();
			b=st.top();st.pop();
			ans=b+s[i]+a;
			st.push(ans);
		}		
	}
	return st.top();
}

string inpre(string s){
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]=='(')	s[i]=')';
		else if(s[i]==')')	s[i]='(';
	}
	s=inpost(s);
	reverse(s.begin(),s.end());
	return s;
}

string prein(string s){
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		if(s[i]=='(')	s[i]=')';
		else if(s[i]==')')	s[i]='(';
	}
	s=postin(s);
	reverse(s.begin(),s.end());
	return s;
}

string prepost(string s){
	s=prein(s);
	return inpost(s);
}

string postpre(string s){
	s=postin(s);
	return inpre(s);
}

string input(){
    string s;
    int c=1;
    while(c){	c=0;
                    cin>>s;
					for(int i=0;i<s.size();i++){
						if((s[i]<'0' || s[i]>'9')&&(s[i]<'a' || s[i]>'z')&&s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/'&&s[i]!='('&&s[i]!=')')
							{c=1; break;}
					}
					if(c)	cout<<"\n !! Invalid Expression !! Enter a valid Expression - ";
				}
    return s;
}

int main(){
	string s="",x;
	int ch=1,c,ans;
	while(ch){
		cout<<"\n\n\t\t   Prefix-Infix-Postfix\n\t\t===========================";
		cout<<"\n  Choose type of Operation - \n  1. Infix to Prefix\n  2. Prefix to Postfix\n  3. Prefix to Infix\n  4. Postfix to Infix\n  5. Postfix to Prefix\n  0. Exit\n\n Enter choice (0-5) - ";
		cin>>ch;
		switch(ch){
			case 1: cout<<"\n\n Enter an Infix Expression - ";  s=input();x=s;
					cout<<"\n\n The Infix Expression ("<<x<<") in PreFix Expression is - "<<inpre(s);break;
			case 2: cout<<"\n\n Enter an Prefix Expression - ";  s=input(); x=s;
					cout<<"\n\n The Prefix Expression ("<<x<<") in PostFix Expression is - "<<prepost(s);break;
			case 3: cout<<"\n\n Enter an Prefix Expression - ";  s=input(); x=s;
					cout<<"\n\n The Prefix Expression ("<<x<<") in InFix Expression is - "<<prein(s);break;
			case 4: cout<<"\n\n Enter an Postfix Expression - ";  s=input(); x=s;
					cout<<"\n\n The Postfix Expression ("<<x<<") in InFix Expression is - "<<postin(s);break;
			case 5: cout<<"\n\n Enter an Postfix Expression - ";  s=input(); x=s;
					cout<<"\n\n The Postfix Expression ("<<x<<") in PreFix Expression is - "<<postpre(s);break;
			case 0:	cout<<"\n\n\t !! Closing Program !!\n\n\n\n";break;
			default: cout<<"\n\n\t!! Enter a Valid Choice !!";
		}
	}
	return 0;
}
