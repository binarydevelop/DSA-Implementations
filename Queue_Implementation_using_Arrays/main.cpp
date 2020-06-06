#include"Queue.h"
#include<iostream>

using namespace std;

int main(){
  Queue<int> q1(5);
  cout<<q1.getsize()<<"--> Before adding elements \n ";
  q1.enqueue(10);
  q1.enqueue(11);
  q1.enqueue(12);
  q1.enqueue(13);
  q1.enqueue(14);
  q1.enqueue(15);
  cout<<q1.getsize()<<"--> After adding elements \n ";
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  q1.dequeue();
  cout<<q1.getsize()<<"--> After removing elements \n ";
  q1.displayqueue();
    return 0;
}