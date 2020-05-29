#include "d_list.h"

#include<iostream>
using namespace std;



int main(){
  
    d_list<int> d1;
   
     d1.addashead(30);
     d1.addastail(50);
      d1.addashead(370);
     d1.addastail(550);
     
d_list<int> d2;
d2=d1;
    

d2.printlist();
   
    return 0;
}
