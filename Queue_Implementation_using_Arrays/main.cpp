#include"Queue.h"
#include<iostream>

using namespace std;

int main(){
  Queue<int> q1(5);
  q1.enqueue(10);
  q1.enqueue(11);
  q1.enqueue(12);
  q1.enqueue(13);
  q1.enqueue(14);
  q1.enqueue(15);
  
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.displayqueue();
    return 0;
}