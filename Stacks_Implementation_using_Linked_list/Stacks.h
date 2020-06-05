#include<iostream>
#include"node.h"

template<class T>
class Stacks{
   private:
      Node<T>* top=nullptr;
      int stack_size=0;
   public:
      Stacks(){
          top=nullptr;
      }
//we push at the beginning as pushing at the end takes O(n) time while at the beginning takes constant time 
       void push(T value){
          Node<T>* new_node= new Node<T>(value);
          if(top==nullptr){
              top=new_node;
              stack_size+=1;
              new_node->next=nullptr;
          }else{
              new_node->next=top;
              top=new_node;   
              stack_size+=1;
          }
      }
   
       void printstack(){
          if(this->top==nullptr){return ;}
          else{
              while(top){
                  std::cout<<top->m_data<<"\n";
                  top=top->next;
              }
          }
      }
      
       void pop(){
           if(this->top==nullptr){
               return ;
           }else{
               Node<T>* temp= top;
               top=top->next;
               delete temp;
           }
       }

       T& displaytop(){
           std::cout<<this->top->m_data;
           return this->top->m_data;
       }

       bool isempty(){
           return top->next==nullptr;
       }
      
     

};