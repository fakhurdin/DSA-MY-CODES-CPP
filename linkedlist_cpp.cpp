#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(){
		this->data=0;
		this->next=NULL;
	}
	Node(int _data){
		this->data=_data;
		this->next=NULL;
	}
};
class list{
	public:
	Node* head;
	list(){
		this->head=NULL;
	}
	void insert_at_back(int data){
		Node* newnode = new Node(data);
		if(head==NULL){
			head = newnode;
			return;
		}
		Node*temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next = newnode;
	}
	void insert_at_front(int data){
		Node * newnode = new Node(data);
		newnode->next = head;
		head = newnode;
		
	}
	void printlist(){
		Node * temp = head;
		while(temp!=NULL){
			cout<<temp->data<<"<->";
			temp=temp->next;
		}
		cout<<" NULL "<<endl;
	}
};

int main(){
	list l1;
	list l2;
	cout<<"INSERT AT BACK DATA : "<<endl;
	l1.insert_at_back(5);
	l1.insert_at_back(8);
	l1.insert_at_back(2);
	l1.insert_at_back(1);
	l1.printlist();
	cout<<"INSERT AT FRONT DATA : "<<endl;
	l2.insert_at_front(5);
	l2.insert_at_front(8);
	l2.insert_at_front(2);
	l2.insert_at_front(1);
	l2.printlist();
	return 0;

}
