#include"f_list.h"
#include<iostream>

using namespace std;

int main(){
    f_list<int> f1;
    cout<<f1.gethead()<<" ";

    f1.addashead(60);
    cout<<f1.gethead();
    cout<<f1.gettail();
    return 0;
}