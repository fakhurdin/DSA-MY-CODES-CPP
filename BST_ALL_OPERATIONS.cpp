#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node * left;
		Node * right ;
		Node(){
			this->data=0;
			this->left=NULL;
			this->right=NULL;
		}
		Node(int _data){
			this->data=_data;
			this->left = NULL;
			this->right = NULL;
		}
};
class BST{
	public: 
	Node * root;
	BST(){
		root=NULL;
	}
	Node* insert(Node * current,int _data){
		if(current==NULL){
			return new Node(_data);
		}
		
		if(_data > current->data){
			current->right=insert(current->right,_data);
		}
		if(_data<current->data){
			current->left = insert(current->left,_data);
		}
		
		return current;
	}
	Node* max(Node *node)
	{
	while(node->right!=NULL){
			node = node->right;
		}
		return node;
	}
	Node* min(Node* node){ 
		while(node->left!=NULL){
			node = node->left;
		}
		return node;
	}
	//---------------
Node* deleting(Node * current, int val) {
if(current==NULL){
	return NULL;
}

if(val > current->data){
	current->right = deleting(current->right,val);
}
else if(val < current->data){
	current->left = deleting(current->left,val);
}
else{
	if(current->left==NULL && current->right == NULL){
		delete current;
		return NULL;
	}
	else if(current->left == NULL){
		Node * temp = current->right;
		delete current;
		return temp;
	}
	else if(current->right == NULL){
		Node* temp = current->left;
		delete current;
		return temp;
	}
	else{
		Node * temp = min(current->right);
		current->data = temp->data;
		current->right = deleting(current->right,temp->data);
	}
}
return current;
}

	//-------------------
	
	void preorder(Node * current){
		if(current!=NULL){
			cout<<current->data<<" ";
			preorder(current->left);
			preorder(current->right);
		}
	}
		void postorder(Node * current){
		if(current!=NULL){
			preorder(current->left);
			preorder(current->right);
			cout<<current->data<<" ";
		}
	}
		void inorder(Node * current){
		if(current!=NULL){
			preorder(current->left);
			cout<<current->data<<" ";
			preorder(current->right);
		}
	}
	Node* Search (Node* current , int val){
		if(current==NULL || current->data == val){
			return current;
		}
		if(val > current->data){
			return Search(current->right,val);
		}
		else{
			
			return Search(current->left,val);
		}
	}
};
int main(){
	BST b;
 	b.root = b.insert(b.root, 10);
    b.root = b.insert(b.root, 15);
    b.root = b.insert(b.root, 50);
    b.root = b.insert(b.root, 11);
    cout<<"\nPREORDER TRAVERSAL BEFORE DELETE"<<endl;
    b.preorder(b.root);
    b.deleting(b.root,15);
    cout<<"\nPREORDER TRAVERSAL AFTER DELETE"<<endl;
    b.preorder(b.root);
    Node* r = b.Search(b.root, 20);
    if(r!=NULL){
    	cout<<"Value Found : "<<endl;
	}
	else{
		cout<<"VALUE NOT FOUND"<<endl;
	}
//    cout<<"\nPOST TRAVERSAL"<<endl;
//    b.postorder(b.root);
//    cout<<"\nINORDER TRAVERSAL"<<endl;
//    b.inorder(b.root);
//    cout<<"\n MINIMUM ELEMENT IN TREE : "<<b.min(b.root)->data;
//    cout<<"\n  Maximum ELEMENT IN TREE : "<<b.max(b.root)->data;
//	
}
