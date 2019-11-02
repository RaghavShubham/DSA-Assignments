#include<bits/stdc++.h>
using namespace std;

class node {
	public :
	string data;
	int priority;
	node *next;
	bool operator <= (const node& d) {
		if(priority <= d.priority)
			return true;
		return false;
	}
	bool operator == (const node& d) {
		if(priority == d.priority)
			return true;
		return false;
	}
	bool operator >= (const node& d) {
		if(priority == d.priority)
			return true;
		return false;
	}
	bool operator < (const node& d) {
		if(priority < d.priority)
			return true;
		return false;
	}
	bool operator > (const node& d) {
		return priority > d.priority;
	}
};

int input() {
	int n;
	cin >> n;
	while(n < 0) {
		cout << "\nEnter the number again : "; 
		cin >> n;
	}
	return n;
}

class Priorityqueue {
	public :
	node *head;
	Priorityqueue(){
		head = NULL;
	}
	void Insert();
	string Peek();
	void Remove();
	void display();
	bool IsEmpty();
};

void Priorityqueue :: Insert() {
	node* start = (head); 
    node* temp = new node;
    int p;
    cout << "\nEnter data : ";
    cin >> temp -> data;
    cout << "\nEnter its Priority : ";
    cin >> p;
    cout << "\n";
    temp -> priority = p;
    temp -> next = NULL;
    if(head == NULL) {
    	head = temp;
    	return ;
	}
    if (head->priority <= p) {
        temp -> next = head; 
        (head) = temp; 
    } 
    else {
        while (start -> next != NULL && 
               start -> next -> priority > p) { 
            start = start -> next; 
        }
        temp -> next = start -> next; 
        start -> next = temp; 
    }
}

void Priorityqueue :: display() {
	node *temp = head;
	cout << "Elements are as follows : \n\n";
	while(temp != NULL) {
		cout << temp -> data << " " << temp -> priority << "\n";
		temp = temp -> next;
	}
	cout << "\n";
}

string Priorityqueue :: Peek() {
	return head -> data;
}

bool Priorityqueue :: IsEmpty() {
	return head == NULL;
}												

void Priorityqueue :: Remove() {
	if(IsEmpty()) {
		cout << "\n\n The queue is empty\n\n";
		return ;
	}
	node *temp = head;
	head = head -> next;
	free(temp);
}

int main() {
	Priorityqueue obj;
	while(1) {
		cout << "1.Enter elements in Priority queue.\n";
		cout << "2.Delele Element.\n";
		cout << "3.Print Element Highest priority.\n";
		cout << "4.Display all Elements\n";
		cout << "Any key to exit\n";
		int ch;
		cin >> ch;
		switch(ch) {
			case 1 : 
				obj.Insert();
				break;
			case 2 : 
				obj.Remove();
				break;
			case 3 :
				cout << obj.Peek();
				break;
			case 4 : 
				obj.display();
				break;
			default :
				exit(0);
		}
	}
	return 0;
}
