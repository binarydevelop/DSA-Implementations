#include<iostream>
#include"node.h"
template<class T>
class f_list{
    private:
    Node<T>* head;
    Node<T>* tail;
    int f_list_size;

    public:
    f_list(){
        head=nullptr;
        tail=nullptr;
        f_list_size=0;
    }
       int getlistsize(){return f_list_size;}
       Node<T>* gethead(){return head;}
       Node<T>* gettail(){return tail;}

       void addashead(T data){
           Node<T>* new_node= new Node<T>(data);
           if(head==nullptr){
               
               this->head= new_node;
               this->tail=new_node;
               new_node->m_next=nullptr;
               this->f_list_size+=1;
           }else{
               new_node->m_next=this->head;
               this->head=new_node;
               this->f_list_size+=1;
           }
       }

       void addastail(T data){
            Node<T>* new_node= new Node<T>(data);
            if(tail==head){
                new_node->m_next=nullptr;
                this->tail=new_node;
                this->f_list_size+=1;
            }else{
                this->tail->m_next=new_node;
                new_node->m_next=nullptr;
                this->tail=new_node;
                this->f_list_size+=1;
            }
       }
       
       void printlist(){
           Node<T>* temp =this->head;
           while(temp){
               std::cout<<temp->m_data<<"->";
               temp=temp->m_next;
           }
       }

       Node<T>* flistreverse(){
           Node<T>* current= this->head;
           Node<T>*  next=nullptr;
           Node<T>* prev=nullptr;
           while(current!=nullptr){
               next=current->m_next;
              current->m_next=prev;
              prev=current;
              current=next;
           }
           this->head=prev;
           return prev;
       }
    
       
 };