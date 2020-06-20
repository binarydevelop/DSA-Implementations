#include<iostream>
#include "b_tree.h"
using namespace std;
int main(){
    
                                                          /*   45  
                                                            /   \
                                                            24    154
                                                          /  \     / \
                                                        2434  1034 243 103
                                                          /\    /
                                                        274 20 21
                                                          */
  b_tree<int> b1;

  b1.addnode_levelorder(45);
  b1.addnode_levelorder(24);
  b1.addnode_levelorder(154);
  b1.addnode_levelorder(2434);
  b1.addnode_levelorder(1034);
  b1.addnode_levelorder(243);
  b1.addnode_levelorder(103);
  b1.addnode_levelorder(274);
  b1.addnode_levelorder(20);
  b1.addnode_levelorder(21);
  b1.levelorder_traversal();
  cout<<"\n";
  b1.preorder_traversal();
  cout<<"\n";
  b1.inorder_traversal();
  cout<<"\n";
   b1.levelorder_traversal();
   b1.delete_node(103);
    cout<<"\n";
   b1.levelorder_traversal();
   cout<<"\n";
   cout<<std::boolalpha<<b1.searchnode(21);
   cout<<b1.height_of_tree();
    return 0;
}