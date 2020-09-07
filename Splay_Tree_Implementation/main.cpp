#include "splay_tree.h"
#include<iostream>

using namespace std;

int main(){


splay_tree<int> s1;
splay_tree<int> s2;
s2.insert(342);

   s1.insert(21);
   s1.insert(2651);  
   s1.insert(1);
s1.insert(24);

s1.insert(2334);

s1.deletenode(2334);

 s1.inorder();
  return 0;
}