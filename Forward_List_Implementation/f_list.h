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
    
       Node<T>* begin(){
             return this->head;
       }
 
       Node<T>* end(){
           return this->tail;
       }
 
       bool isempty(){
           return this->head==nullptr && f_list_size==0;
       }
 
       T& back(){
           return this->tail->m_data;
       }

        T& front(){
           return this->head->m_data;
       }
        
        void removefromfront(){
            if(head==nullptr){return;}
            Node<T>* temp= this->head;
            this->head=this->head->m_next;
            delete temp;
            this->f_list_size-=1;
        }

        void removefromback(){
            if(head==nullptr){return;}
            Node<T>* curr= this->head;
            Node<T>* prev= nullptr;
            while(curr->m_next!=nullptr){   
                prev=curr;
             curr=curr->m_next; 
        }
      this->tail=prev;
      this->tail->m_next=nullptr;
      this->f_list_size-=1;
        }
        
        void insertat(T data, int index){
            if(index<0 || index>f_list_size){return;}
            else{
                Node<T>* temp= this->head;
                 Node<T>* prev= nullptr;
                int i=0;
                while(i<index){
                    prev=temp;
                    temp=temp->m_next;
                    i++;
                }
               Node<T>* new_node= new Node<T>(data);
                prev->m_next=new_node;
                new_node-> m_next= temp;
            }
        }
        
        void removeat(int index){
            if(this->head==nullptr){return;}

            Node<T>* temp=this->head;
            int i=0;
            Node<T>* prev=nullptr;
            while(i<index){
                prev=temp;
                temp=temp->m_next;
                i++;
            }
            prev->m_next=temp->m_next;
            temp->m_next=nullptr;
        }
        
        f_list& operator=(f_list& f2){
            this->head=f2.head;
            this->tail=f2.tail;
            return *this;
        }


    
 };