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
     b1.addnode(43);
     
     b1.level_order_traversal();
     cout<<"\n";
     b1.deletenode(31);
     b1.level_order_traversal();
     cout<<"\n";
     b1.deletenode(14);
     b1.level_order_traversal();
     cout<<"\n";
     b1.deletenode(20);
     b1.level_order_traversal();
     cout<<"\n";
     
    
    return 0;
}
       