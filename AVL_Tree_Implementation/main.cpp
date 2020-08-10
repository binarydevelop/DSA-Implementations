#include<iostream>
#include"avl.h"

using namespace std;

int main(){
  avl<int> a1;
  a1.add_node(20);
  a1.add_node(25);
  a1.add_node(30);  
  a1.add_node(10);
 a1.add_node(5);
 a1.add_node(15);
 a1.add_node(27);
 a1.add_node(19);
 a1.add_node(16);
 
  cout<<"\n";


cout<<a1.search(3210);






  
}