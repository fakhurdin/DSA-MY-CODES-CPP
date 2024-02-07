
#include<iostream>
using namespace std;
class Heap{
	public:
		int arr[100];
		int size;
		Heap(){
			arr[0]=-1;
			size = 0;
		}
		void insert(int _data){
			size = size + 1;
			int index = size;
			arr[index]=_data;
			while(index>1){
				int parrent = index/2;
				if(arr[parrent]<arr[index]){
					swap(arr[parrent],arr[index]);
					index = parrent;
				}
				else{
					return ;
				}
			}
		}
		
		void print(){
			for(int i=1 ; i<=size;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
void deletefromheap(){
	if(size==0){
		return;
	}
	else{
		//step 1;
		arr[1]=arr[size];
		//step 2
		size--;
		
		//step 3
		int i = 1;
		while(i<size){
			int left = 2*i;
			int right = 2*i+1;
			
			if(left < size && arr[i] < arr[left]){
				swap(arr[i],arr[left]);
				i = left;
			}
			else if(right < size && arr[i] < arr[right]){
				swap(arr[i],arr[right]);
				i = right;
			}
			else{
				return;
			}
		}
	}
}		


};
int main(){
	Heap h1;
	h1.insert(10);
	h1.insert(20);
	h1.insert(30);
	h1.insert(40);
	cout<<"HEAP BEFOR DELETATION"<<endl;
	h1.print();
	cout<<"HEAP AFTER DELETATION"<<endl;
	h1.deletefromheap();
	h1.print();
	
	
}
