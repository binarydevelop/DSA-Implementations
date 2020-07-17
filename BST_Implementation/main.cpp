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
     
     cout<<b1.searchkey(340);
     
     bst<char> b2;
    

    return 0;
}
       