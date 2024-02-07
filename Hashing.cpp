#include<iostream>
#include<vector>
#include<list>
#include<algorithm> 
using namespace std;
class Hash{
	public:
	vector<list <int> > Table;
	int buck;
	Hash(int _size){
		buck=_size;
		Table.resize(_size);
	}
	
	int hashvalue(int key){
		return key%buck;
	}
	void add(int key){
		int index = hashvalue(key);
		Table[index].push_back(key);
	}
	//Search()
	list<int>::iterator Search(int key){
		int index = hashvalue(key);
		return find(Table[index].begin(),Table[index].end(),key);
		
	}
void deletefromheap(int key) {
    int index = hashvalue(key);
    list<int>::iterator it = Search(key); // Explicit declaration of iterator

    if (it != Table[index].end()) {
        Table[index].erase(it); // Erase the element from the list
        cout << key << " is Deleted" << endl;
    } else {
        cout << "KEY IS NOT THERE" << endl;
    }
}



};

int main(){
	Hash h1(10);
	h1.add(5);
	h1.add(9);
	h1.add(3);
	
	h1.deletefromheap(3);
	
}
