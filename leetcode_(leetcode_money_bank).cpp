#include<iostream>
using namespace std;
class Solution {
public:
    int totalMoney(int n,int k) {
    	int temp=n;
    	if(n<7){
    		for(int i=1;i<=n;i++){
    			k+=temp--;
			}
		}
		else if(n>=7){
			int counter=0,x=n,it=1,sum=0,t=0;
			// 2 + 3 + 4 + 5 + 6 + 7 + 8
			int fak = 7;
			t=n;
			for(int i=0;i<=(x/7);i++){
				int temp1 = it;
				for(int j=0;j<fak;j++){
					sum+=temp1++;
				}
				
				t-=7;
				if(t>=7){
					fak=7;
				}
				else{
					fak = t;
				}
				it+=1;
			}
			k=sum;
		}
		else{
			return k;
		}
		

return k;   
}
};
int main(){
	Solution s1;
	cout<<"THE SUM : "<<s1.totalMoney(4,0);
}
