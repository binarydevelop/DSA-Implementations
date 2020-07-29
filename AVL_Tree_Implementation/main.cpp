#include<iostream>
#include "avl.h"

using namespace std;

int main(){
    
    avl<int> a1;
    cout<<a1.getroot();
    a1.insert_node(232);
    cout<<a1.getroot();
    return 0;
}