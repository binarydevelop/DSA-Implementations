#include "c_list.h"
#include<iostream>
using namespace std;

int main(){
      c_list<int> c1;
      c1.addnode(50);
      c1.addnode(60);
      c1.addnode(70);
   
    c1.insertat(40,1);
    c1.insertat(430,2);
    c1.deleteat(1);
    c1.printlist();
 
    return 0;
}