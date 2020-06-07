#include"Queue.h"
#include<iostream>

using namespace std;

int main(){
    
        Queue<int> q1;
        q1.enqueue(5);
        q1.enqueue(10);
        q1.enqueue(15);
        q1.enqueue(20);
        cout<<q1.getnodecount();
       q1.displayqueue();
       q1.dequeue();
       q1.dequeue();
       cout<<q1.getnodecount();
        q1.displayqueue();
    return 0;
}