#include<iostream>
#include "node.h"

template<class T>
class c_list{
    private:
       int c_list_size;
       Node<T>* last;
    public:
        c_list():c_list_size(0){
            this->last=nullptr;
        }

       Node<T>* getlast(){return last; }

       Node<T>* gethead(){return last->m_next;}
        
       int getlength(){return c_list_size;}

       void addnode(T data){
           Node<T>* new_node= new Node<T>(data);
           if(last==nullptr){
              last= new_node;
              new_node->m_next=last;
           }else{
             new_node->m_next=last->m_next;
             last->m_next=new_node;
             last=new_node;
           }
       }

    Node<T>* begin(){return this->last->m_next; }
    Node<T>* end(){return this->last;}

    bool isempty(){return this->last==nullptr && c_list_size==0;}

    T& back(){return this->last->m_data;}
    T& front(){return this->last->m_next->m_data;}
    
    void printlist(){
        Node<T>* temp =last->m_next;
        while(temp!=last){
            std::cout<<temp->m_data<<"->";
            temp=temp->m_next;
        }
        std::cout<<temp->m_data;
    }
   
    
};