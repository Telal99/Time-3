/*
My name : Telal Almubarak Abdualgbar ALhussian
Class : second
Department:computer */
/*

This program was made piece by piece, part after another, and
was then reassembled to hold three data structure types in one
code, there has been a lot of bugs and debugging, in order to
release a stable code.

*/
#include <iostream>
// including input/output library for user input and preview
using namespace std;
// this line litreally sets us free from writing std:: each time
// for input/output operations
struct Node {
	int data;
	struct Node *next;
// defining grouped variables under one name, allowing different
// variables to be accessed via the declared name
};
struct Node* top = NULL;
// initial stack is empty, waiting for a later user input
void push(int val) {
// void specifies that the function doesn't return a value
// to be noted, void can point to a function, but not to a class member
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
// new elements are inserted on the top of view, showing as the first
// element, of course it can be changed, if desired
}
struct node {
	int info;
// defining variable as integer
	struct node *next;
// defining grouped variables under one name, allowing different
// variables to be accessed via the declared name
	}*start;
	class list {
// creating object constructor defined by the programmer to be used in
// the program
		public:
// a class member that is available from any function
			node* create_node(int);
			void insert_begin();
			void insert_pos();
			void insert_last();
			void delete_pos();
// defining our main functions to be used in later codes, obviously
// these are our main functions for doing operations
			void search();
			void displayo();
			list() {
				start = NULL;
			}
	};
node *list::create_node(int value)
// this is a reference to a pointer to a node object, allowing you
// to change the memory address pointed to by the pointer through the
// reference as well as the node value, through the pointer. we used
// scope resolution operator to define a function outside the class
		{
		struct node *temp;
		temp = new(struct node);
		if (temp == NULL){
			cout<<"\nMemory allocation issue"<<endl;
			exit(1);
		}
		else {
			temp->info = value;
			temp->next = NULL;
			return temp;
		}
		}
void list::insert_begin()
		{
			int value;
			cout<<"\nEnter the value to be inserted: ";
			cin>>value;
			struct node *temp, *p;
			temp = create_node(value);
			if (start == NULL) {
				start = temp;
				start->next = NULL;
			}
			else
			{
				p = start;
				start = temp;
				start->next = p;
			}
			cout<<"\nElement Inserted at beginning"<<endl;
		}
void list::insert_last()
// function used for element insertion purposes
		{
			int value;
			cout<<"\nEnter the value to be inserted: ";
			cin>>value;
			struct node *temp, *s;
			temp = create_node(value);
			s = start;
			while (s->next != NULL)
			{
				s = s->next;
			}
			temp->next = NULL;
			s->next = temp;
			cout << "\nElement Inserted at last" << endl;
		}
void list::insert_pos()
		{
			int value, pos, counter = 0;
			cout << "\nEnter the value to be inserted: ";
			cin >> value;
			struct node *temp, *s, *ptr;
			temp = create_node(value);
			cout << "\nEnter the postion at which node to be inserted: ";
			cin >> pos;
			int i;
			s = start;
			while (s != NULL)
			{
				s = s->next;
				counter++;
// adding to the middle is a little bit complicated, thus, it has been
// phased out and replaced with a more effective, easier one
			}
			if (pos == 1) {
				if (start == NULL) {
					start = temp;
					start->next = NULL;
				}
				else {
					ptr = start;
					start = temp;
					start->next = ptr;
				}
			}
			else if (pos > 1  && pos <= counter) {
				s = start;
				for (i = 1; i < pos; i++) {
					ptr = s;
					s = s->next;
				}
				ptr->next = temp;
				temp->next = s;
			}
			else {
				cout<<"\nPositon out of range"<<endl;
			}
		}
void list::delete_pos() {
// function used for element deletion purposes
			int pos, i, counter = 0;
			if (start == NULL) {
				cout<<"\nList is empty"<<endl;
				return;
			}
			cout<<"\nEnter the position of value to be deleted: ";
			cin>>pos;
			struct node *s, *ptr;
			s = start;
			if (pos == 1) {
				start = s->next;
			}
			else {
				while (s != NULL) {
					s = s->next;
					counter++;
				}
				if (pos > 0 && pos <= counter) {
					s = start;
					for (i = 1;i < pos;i++) {
						ptr = s;
						s = s->next;
					}
					ptr->next = s->next;
				}
				else {
					cout<<"\nPosition out of range"<<endl;
				}
				free(s);
				cout<<"\nElement Deleted"<<endl;
			}
		}
void list::search() {
// function used for element search purposes
	int value, pos = 0;
	bool flag = false;
	if (start == NULL) {
		cout<<"\nList is empty"<<endl;
		return;
	}
	cout<<"\nEnter the value to be searched: ";
	cin>>value;
	struct node *s;
	s = start;
	while (s != NULL) {
		pos++;
		if (s->info == value) {
			flag = true;
			cout<<"\nElement "<<value<<" is found at position "<<pos<<endl;
		}
// using while loop to check every element in the list for the
// condition, the mechanism is that it checks positions one by one
// until it find a matching value, this mechanism can also be used in
// case we want to update an existing element with another recent
// element, but no need for it right now
		s = s->next;
	}
	if (!flag)
	cout<<"\nElement "<<value<<" not found in the list"<<endl;
}
void list::displayo() {
// function used to display elements
	struct node *temp;
	if (start == NULL) {
		cout<<"\nThe List is Empty"<<endl;
		return;
	}
	temp = start;
		cout << "\nElements of the list are: " << endl;
		while (temp != NULL) {
			cout << temp->info << " --> ";
			temp = temp->next;
		}
	cout<<"null"<<endl;
}



void pop() {
// same as line 40/41
// removes the element on top of the stack , effectively reducing
// its size by one the element, the removed element is the
// latest element inserted into the stack
	if (top == NULL){
		cout << "\nStack Underflow!" << endl;
//using if condition to detect an error condition that occurs if
// an item is called for from the stack , but the stack is empty

	}
	else {
		cout << "\nThe popped element is: " << top->data << endl;
		top = top->next;
	}
}
void display() {
// display info on screen using void
	struct Node* ptr;
	if(top == NULL)
	cout << "\nStack is empty, try to add some elements first!";
	else {
// replacement in case if condition failed, which in our case shows
// the existing elements
		ptr = top;
		cout << "Stack elements are: ";
		while (ptr != NULL) {
			cout << ptr->data << " ";
			ptr = ptr->next;
		}
	}
	cout << endl;
}
int queue[50], n = 50, front = - 1, rear = - 1;
void Insert() {
	int val;
	if (rear == n - 1)
	cout << "\nQueue Overflow" << endl;
	else {
		if (front == - 1)
		front = 0;
		cout << "\nInsert the element in queue: ";
		cin >> val;
		rear++;
		queue[rear] = val;
	}
}
void Delete() {
	if (front == - 1 || front > rear) {
		cout << "\nQueue Underflow!" << endl;
		return ;
	} else {
		cout << "\nElement deleted from queue is: " << queue[front] << endl;
		front++;;
	}
}
void Display() {
	if (front == - 1)
	cout << "\nQueue is empty" << endl;
	else {
	cout << "\nQueue elements are: ";
	for (int i = front; i <= rear; i++)
	cout << queue[i]<<" ";
		cout << endl;
}
}
int A;
int main(){
	cout << "1 for Queue, 2 for Stack, 3 for Linkedlist, 4 for exit";
	cout << "\n\nWhat data structure type do you want: ";
	cin>>A;
	if (A == 1){
		int ch;
		cout << "1) Insert element to Queue" << endl;
		cout << "2) Delete element from Queue" << endl;
		cout << "3) Display all the elements of Queue" << endl;
		cout << "4) Exit" << endl;
		do {
			cout << "\nEnter your choice : ";
			cin >> ch;
			switch (ch) {
				case 1: Insert();
					break;
				case 2: Delete();
					break;
				case 3: Display();
					break;
				case 4:
					exit(1);
				default:
					cout<<"\nInvalid choice"<<endl;
					break;
			}
	} while(ch!=4);
	}
	else if (A == 2){
		int ch, val;
		cout << "(1) Push in Stack" << endl;
		cout << "(2) Pop from Stack" << endl;
		cout << "(3) Display Stack" << endl;
		cout << "(4) Exit" << endl;
		do {
			cout << "\n\nEnter your choice: ";
			cin >> ch;
			switch(ch) {
				case 1: {
					cout << "\nEnter a value to be pushed: ";
					cin >> val;
					push(val);
					break;
				}
				case 2: {
					pop();
					break;
				}
				case 3: {
					display();
					break;
				}
				case 4: {
					exit(1);
				}
				default: {
					cout << "\nInvalid Choice" << endl;
					break;
				}
			}
		} while(ch!=4);
	}
	else if (A == 3) {
		int choice;
		list sl;
			start = NULL;
			while (1)
// while(1) is used for infinite loop, it has no condition, and
// as 1 presents, then the condition is always true, to come out
// from this infinite loop, we have to use conditional statement
// and break statement
			{
				cout<<"(1) Insert element at beginning"<<endl;
				cout<<"2- Insert element at last"<<endl;
				cout<<"3- Insert element at position"<<endl;
				cout<<"4- Delete element"<<endl;
				cout<<"5- Search element"<<endl;
				cout<<"6- Display element"<<endl;
				cout<<"7- Exit "<<endl;
				cout<<"\nEnter your choice: ";
				cin >> choice;
// the above outputs are concerned in displaying list of options, so
// the user is aware of what he is doing
				switch(choice){
				case 1:
					sl.insert_begin();
					cout<<endl;
					break;
// common case codes to interact with user using input, and to check or
// compare the inserted value with the switch case, for if it is true,
// its condition will be performed, break is used to terminate the loop
				case 2:
					sl.insert_last();
					cout<<endl;
					break;
				case 3:
					sl.insert_pos();
					cout<<endl;
					break;
				case 4:
					sl.delete_pos();
					break;
				case 5:
					sl.search();
					cout<<endl;
					break;
				case 6:
					sl.displayo();
					cout<<endl;
					break;
				case 7:
					exit(1);
				default:
					cout<<"\nWrong choice"<<endl;
					break;
				}
// the default case can be used for performing a task when none of the
// cases is true, no break is needed in the default case
			}
	}
	else if (A == 4) {
		return 0;
	}
	else {
		cout << "\nWrong choice\n" << endl;
		exit(1);
	}
	return 0;
}
