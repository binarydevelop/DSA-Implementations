#include<iostream>
#include "Stacks.h"

using namespace std;

int main(){
    Stacks<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    s1.printstack();
    
    return 0;
}