#include"node.h"
#include<iostream>

template<class T>
class Queue{
   private:
      Node<T>* top;
      Node<T>* rear;
      int node_count;
   public:
        T m_data;
        Queue():node_count(0){
           top=nullptr;
           rear=nullptr;
        }

     int getnodecount(){return node_count;}
    
     void enqueue(T value){
       Node<T>* new_node= new Node<T>(value);
       if(this->rear==nullptr){
          this->top=new_node;
          new_node->m_next=nullptr;
          rear=new_node;
          ++node_count;
       }
       else{
          rear->m_next=new_node;
          new_node->m_next=nullptr;
          rear=new_node;
          ++node_count;
       }
    }

     void displayqueue(){
        Node<T>* temp= this->top;
        while(temp){
           std::cout<<temp->m_data<<" ";
           temp=temp->m_next;
        }
        std::cout<<"\n";
     }
     
     void dequeue(){
         if(top==nullptr){
             return ;
         }else{
             Node<T>* temp=this->top;
             top=top->m_next;
             delete temp;
             --node_count;
         }
     }
};