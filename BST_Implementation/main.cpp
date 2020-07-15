#include <iostream>
#include "bst.h"
using namespace std;

int main(){
     
     bst<int> b1;
     
     b1.addnode(20);
    
     b1.addnode(33);
     
     b1.addnode(17);
   
     b1.addnode(14);
     b1.addnode(18);
     b1.addnode(31);
     b1.addnode(34);
     b1.level_order_traversal();
     

    return 0;
}