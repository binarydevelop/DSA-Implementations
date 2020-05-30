#include"f_list.h"
#include<iostream>

using namespace std;

int main(){
    f_list<int> f1;
    cout<<f1.gethead()<<" Initail ";

    f1.addashead(60);
 
    cout<<f1.gethead()<<"\n";

    
    f1.addashead(34);
    cout<<f1.gethead()<<"\n";

    cout<<f1.gettail()<<"\n";
   
    
    f1.addastail(64);
    f1.printlist();
    cout<<" \n";
    f1.flistreverse();
    f1.printlist();
    return 0;
}