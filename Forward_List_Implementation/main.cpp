#include"f_list.h"
#include<iostream>

using namespace std;

int main(){
    f_list<int> f1;
    

    f1.addashead(60);
 


    
    f1.addashead(34);
 

  
    f_list<int> f2;
    
    f1.addastail(64);
   

    f1.insertat(3,2);
   
  
   
    f1.printlist();
    cout<<"\n";
    f2=f1;
    f2.printlist();
    return 0;
}