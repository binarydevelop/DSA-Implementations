#include<iostream>
#include"pair.h"
using namespace std;

int main(){

    Pair<int,float> p1 (23,56.7);
  
    
    Pair<int,float> p2(256,78.8);
    
     cout<<p1.getfirst()<<" ";
     cout<<p1.getsecond()<<"\n";
     cout<<p2.getfirst()<<" ";
     cout<<p2.getsecond()<<"\n";
     cout<<"After";
   p2.swap(p1);

     cout<<p1.getfirst()<<" ";
     cout<<p1.getsecond()<<"\n";
     cout<<p2.getfirst()<<" ";
     cout<<p2.getsecond()<<"\n";
    return 0;
}