#include "c_list.h"
#include<iostream>
using namespace std;

int main(){
   c_list<int> c1;
  
   c1.insertat(0,1); 
   c1.insertat(1,2);
    c1.insertat(2,3);
    c1.insertat(2,23);
// 0 1 2
// 0 1 2
   
  c1.printlist();
    return 0;
}