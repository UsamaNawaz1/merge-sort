#include<iostream>
using namespace std;
struct node {
	int info;
	node* link;
};
class List {
private:
	node* first, * last, * newnode;
	void Divide_List(node*&,node*&);
	node* merge(node*,node*);
	void recsort(node*&);
public:
	List():first(NULL),last(NULL),newnode(NULL){}
	void getdata(int var);
	void Display() const;
	void merge_sort();
};
void List::Divide_List(node*& first_head,node*& second_head) {
	node* middle, * current;
	if (first_head == NULL) {
		second_head = NULL;
	}
	else {
		middle = first_head;
		current = first_head->link;
		if (current != NULL) {
			current = current->link;
		}
		while (current != NULL) {
			middle = middle->link;
			current = current->link;
			if (current!= NULL) {
				current = current->link;
			}
		}
		second_head = middle->link;
		middle->link = NULL;
	}
}
node* List::merge(node* first_head,node* second_head) {
	node* newhead, * smalllast;
	if (first_head == NULL) {
		return second_head;
	}
	if (second_head == NULL) {
		return first_head;
	}
	else {
		if (first_head->info < second_head->info) {
			newhead = first_head;
			first_head = first_head->link;
			smalllast = newhead;
		}
		else {
			newhead = second_head;
			second_head = second_head->link;
			smalllast = newhead;
		}
		while (first_head != NULL && second_head != NULL) {
			if (first_head->info < second_head->info) {
				smalllast->link = first_head;
				first_head = first_head->link;
				smalllast = smalllast->link;
			}
			else {
				smalllast->link = second_head;
				second_head = second_head->link;
				smalllast = smalllast->link;
			}
		}
		if (first_head == NULL) {
			smalllast->link = second_head;
		}
		else {
			smalllast->link = first_head;
		}
		return newhead;
	}
	
}
void List::recsort(node*& ptr) {
	node* second_head;
	int count = 0;
	if(ptr!=NULL)
		if (ptr->link != NULL) {
			Divide_List(ptr,second_head);
			for (node* temp = ptr; temp->link != NULL; temp = temp->link)
			recsort(ptr);
			recsort(second_head);
			ptr=merge(ptr,second_head);
		}
}
void List::merge_sort() {
	recsort(first);
	if (first == NULL)
		last = NULL;
	else {
		last = first;
		while (last->link != NULL)
			last = last->link;
	}
}
void List::getdata(int var) {
	newnode = new node;
	newnode->info = var;
	newnode->link = NULL;
	if (first == NULL) {
		first = newnode;
		last = newnode;
	}
	else {
		last->link = newnode;
		last = newnode;
		last->link = NULL;
	}
}
void List::Display() const {
	for (node* ptr = first; ptr != NULL; ptr = ptr->link) {
		cout << "Entered data is : " << ptr->info << endl;
	}
}
int main() {
	List l1;
	l1.getdata(45);
	l1.getdata(454);
	l1.getdata(4);
	l1.getdata(231);
	l1.getdata(555);
	l1.getdata(999);
	l1.getdata(234324234);
	l1.getdata(0);

	l1.merge_sort();
	l1.Display();
}