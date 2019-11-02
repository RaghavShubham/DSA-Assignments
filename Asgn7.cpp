#include <bits/stdc++.h>
using namespace std;

struct node
{
    int prn;
    char name[30];
    node *next;
}*start;

class pinnacle
{
public:
    node *create(int, char[]);
    void add_pres();
    void add_sec();
    void display();
    void add_mem();
    void d_pres();
    void d_sec();
    void d_mem();
    void no_mem();
    void rev();
};

node *pinnacle::create(int prn, char name[30])
{
    struct node *temp;
    temp = new(struct node);
    if(temp==NULL)
    {
        cout<<"\nMemory not allocated!";
        exit(1);
    }
    else
    {
        strncpy(temp->name, name, 30);
        temp->prn=prn;
        temp->next=NULL;
        return temp;
    }
}

void pinnacle::add_pres()
{
    int prn;
    char name[30];
    cout<<"\nAdd President:";
    cout<<"\nEnter PRN no:";
    cin>>prn;
    cout<<"\nEnter name:";
    cin>>name;
    struct node *temp, *l;
    temp=create(prn, name);
    if(start==NULL)
    {
        start=temp;
        start->next=NULL;
    }
    else
    {
        l=start;
        start=temp;
        start->next=l;
    }
    cout<<"\nPresident inserted at beginning."<<endl;
}

void pinnacle::add_sec()
{
    int prn;
    char name[30];
    cout<<"\nAdd Secretary:";
    cout<<"\nEnter PRN no:";
    cin>>prn;
    cout<<"\nEnter name:";
    cin>>name;
    struct node *temp, *s;
    temp=create(prn, name);
    s=start;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    temp->next=NULL;
    s->next=temp;
    cout<<"\nSecretary inserted."<<endl;
}

void pinnacle::display()
{
    struct node *temp;
    if(start==NULL)
    {
        cout<<"\nThe list is empty!"<<endl;
        return;
    }
    temp=start;
    cout<<"\nMembers of list are:"<<endl;
    while(temp!=NULL)
    {
        cout<<"\n\nPRN no:"<<temp->prn<<"  and NAME:"<<temp->name<<endl;
        temp=temp->next;
    }
    cout<<"\n!!!"<<endl;
}

void pinnacle::add_mem()
{
    int prn, counter=0;
    char name[30];
    cout<<"\nAdd member PRN no:";
    cin>>prn;
    cout<<"\nEnter member name:";
    cin>>name;
    struct node *temp, *s, *ptr;
    temp=create(prn, name);
    s=start;
    while(s!=NULL)
    {
        s=s->next;
        counter++;
    }
    if(start==NULL)
    {
        start=temp;
        start->next=NULL;
    }
    else
    {
        s=start;
        for(int i=1;i<counter;i++)
        {
            ptr=s;
            s=s->next;
        }
        ptr->next=temp;
        temp->next=s;
    }
}

void pinnacle::d_pres()
{
    struct node*s;
    s=start;
    start=s->next;
    free(s);
}

void pinnacle::d_sec()
{
    struct node *s;
    s=start;
    while(s->next->next!=NULL)
    {
        s=s->next;
    }
    free(s->next);
    s->next=NULL;
}

void pinnacle::d_mem()
{
    int pos, i, counter=0;
    if(start==NULL)
    {
        cout<<"\nList is empty!";
        return;
    }
    cout<<"\nEnter position of member to be deleted:";
    cin>>pos;
    struct node *s,*ptr;
    s=start;
    if(pos==1)
    {
        start=start->next;
    }
    else
    {
        while(s!=NULL)
        {
            s=s->next;
            counter++;
        }
        if(pos>0 && pos<=counter)
        {
            s=start;
            for(i=1;i<pos;i++)
            {
                ptr=s;
                s=s->next;
            }
            ptr->next=s->next;
        }
        else
        {
            cout<<"\nOut of range!";
        }
        free(s);
        cout<<"\nMember deleted!"<<endl;
    }
}

void pinnacle::no_mem()
{
    int c=0;
    struct node *s;
    s=start;
    while(s!=NULL)
    {
        s=s->next;
        c++;
    }
    cout<<"\nNo of members:"<<c<<endl;
}

void pinnacle::rev()
{
    struct node *ptr1, *ptr2, *ptr3;
    if(start==NULL)
    {
        cout<<"\nList is empty!";
        return;
    }
    if(start->next==NULL)
    {
        return;
    }
    ptr1=start;
    ptr2=ptr1->next;
    ptr3=ptr2->next;
    ptr1->next=NULL;
    ptr2->next=ptr1;
    while(ptr3!=NULL)
    {
        ptr1=ptr2;
        ptr2=ptr3;
        ptr3=ptr3->next;
        ptr2->next=ptr1;
    }
    start=ptr2;
}


int main()
{
    int choice;
    pinnacle p;
    start=NULL;
    while(1)
    {
        cout<<"\n1. Add President.";
        cout<<"\n2. Add Secretary.";
        cout<<"\n3. Display.";
        cout<<"\n4. Add Member.";
        cout<<"\n5. Delete President.";
        cout<<"\n6. Delete Secretary.";
        cout<<"\n7. Delete Member.";
        cout<<"\n8. No of members.";
        cout<<"\n9. Reverse.";
        cout<<"\n10. Exit."<<endl;

        cout<<"Enter choice:";
        cin>>choice;
        switch(choice)
        {
             case 1:
                p.add_pres();
                cout<<endl;
                break;
            case 2:
                p.add_sec();
                cout<<endl;
                break;
            case 3:
                p.display();
                cout<<endl;
                break;
            case 4:
                p.add_mem();
                cout<<endl;
                break;
            case 5:
                p.d_pres();
                cout<<endl;
                break;
            case 6:
                p.d_sec();
                cout<<endl;
                break;
            case 7:
                p.d_mem();
                cout<<endl;
                break;
            case 8:
                cout<<"Total Members : "<<endl;
                p.no_mem();
                cout<<endl;
                break;
            case 9:
                cout<<"Reverse Members : "<<endl;
                p.rev();
                p.display();
                cout<<endl;
                break;
            case 10:
                cout<<"Exiting!";
                exit(1);
                break;
            default:
                cout<<"\nWrong choice!"<<endl;
        }
    }
    return 0;
}
