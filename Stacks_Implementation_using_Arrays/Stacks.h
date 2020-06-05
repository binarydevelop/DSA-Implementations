#include<iostream>

template<class T>
class Stacks{
   private:
       T* array;
       int size;
       int top;
   public:
     Stacks()=default;
     Stacks(int siz){
         if(siz>0){
         T* ptr= new T[siz];
         size=siz;
         top=-1;
         }  
     }
     void push(T value){
         if(top== size-1){
             std::cout<<"Stack is Full";
         }else{
             top++;
             array[top]= value;
             
         }
     }
    void pop(){
        if(top==-1){
            std::cout<<"Stack is Empty";
        }else{
          --top;
        }
    }

    void displaytop(){
         if(top==-1){
            std::cout<<"Stack is Empty";
        }else{
            std::cout<<array[top];
        }
    }
    void traverse_stack(){
        
        if(top==-1){
            std::cout<<"Stack is Empty";
        }else{
            while(top>-1){
                std::cout<<array[top]<<"\n";
                --top;
            }
            std::cout<<"\n";
        }
    }
    
};