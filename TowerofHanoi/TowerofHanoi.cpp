#include<bits/stdc++.h>

using namespace std; 
void printstep(int start,int end){
    cout<<start<<"->"<<end<<"\n";
}
void hanoi(int n,int start,int end){
    int other=0;
    if(n==1){printstep(start,end);}
    
    else{
        other=6-(start+end);
        hanoi(n-1,start,other);
        printstep(start,end);
        hanoi(n-1,other,end);
    }
}
//Minimum no of moves for n disks = (2^n-1)
int main(){
    
    hanoi(4,1,3);
    return 0;
}