#include<iostream>
using namespace std;
const int T_S = 200;
class hashtablentry{
	public:
		int k;
		int v;
		hashmap(){
			this->k=0;
			this->v=0;
		}
		hashmap(int _k,int _v){
			this->k=_k;
			this->v=_v;
			}
			
};
class HashMapTable {
   public:
      hashtablentry **t;
      HashMapTable() {
         t = new hashtablentry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int k) {
         return k % T_S;
      }
      void Insert(int k, int v) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new hashtablentry(k, v);
      }		
};
int main() {
	HashMapTable h1;
	h1.Insert(2,7);
}
