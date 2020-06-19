#include<bits/stdc++.h>

using namespace std;
void paracheck(std::string s){
    stack<char> temp;
    for(int i=0;i<s.size();i++){
        if(s[i]=='[' || s[i]=='{',s[i]=='('){
            temp.push(s[i]);
        }else if(( temp.top()=='['  && s[i]==']' ) ||
                  ( temp.top()=='('  && s[i]==')' ) ||
                  ( temp.top()=='{'  && s[i]=='}' )
                  ){
                      if(temp.empty()){return ;}
                      temp.pop();
                      cout<<"Success";
                  }
                  else{
                      cout<<i<<" "<<s[i];
                  }
    }
}

int main(){
    std::string str="{[()]}";
    paracheck(str);
    return 0;
}