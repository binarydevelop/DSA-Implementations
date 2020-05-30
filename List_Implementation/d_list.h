 #include<iostream>
 #include "node.h"
 
 #ifndef NODE_H
 #define NODE_H


template<class T>
class d_list{
   private:
       int l_size;
       Node<T>* head;
       Node<T>* tail;
        
   public:
       d_list():l_size(0){
          head=nullptr;
          tail=nullptr;
       }
       Node<T>* gethead(){return this->head;}
       Node<T>* gettail(){return this->tail;}
        
         int getlength(){
           return this->l_size;
         }

       void addashead(T data){
          if(this->head==nullptr){
            Node<T>* curr_node=new Node<T>(nullptr,data,nullptr);
            this->head=curr_node;
            this->tail=curr_node;
            this->l_size=l_size+1;
          }else {
            Node<T>* curr_node=new Node<T>(nullptr,data,this->head);
              this->head->previous=curr_node;
             this->head=curr_node;
              this->l_size=l_size+1;
          }
       }

       void addastail(T data ){
          Node<T>* curr_node=new Node<T>(data);
          if(this->tail==this->head){
            this->head->next=curr_node;
            curr_node->previous=this->head;
            this->tail=curr_node;
            this->tail->next=nullptr;
            this->l_size=l_size+1;
          }
          else{
            this->tail->next=curr_node;
            curr_node->previous=this->tail;
            this->tail=curr_node;
            this->l_size=l_size+1;
          }
       }
      
       Node<T>* begin(){
         return this->head;
       }
       
       Node<T>* end(){
         return this->tail;
       }

       bool isempty(){
         return this->head==nullptr;
       }
       
       T& back(){
         return this->tail->m_data;
       }
       
       T& front(){
         return this->head->m_data;
       }
       
        void printlist(){
             Node<T>* temp= this->head;
             while(temp) {
             std::cout << temp->m_data<< " -> ";
             temp = temp->next;
    }
        }

        void printlist_reverse(){
          Node<T>* temp= this->tail;
          while(temp){
            std::cout<< temp->m_data<<" -> ";
            temp=temp->previous;
          }
        }
       
        void removefromfront(){
        if(head==nullptr){return ;}
        head=head->next;
        head->previous=nullptr;
        l_size--;
      }
 
        void removefromback(){
          if(head==nullptr){return ;}
          tail=tail->previous;
          tail->next=nullptr;
          l_size--;
       }
        
        void insertat(T data, int index){
          if(index<1 || index >l_size){return;}

          Node<T>* current= this->head;
          int i=1;
          while(i<index){
           current=current->next;
            i++;
          }
          if(current->previous==nullptr){
            Node<T>* new_node= new Node<T>(nullptr,data,current);
            current->previous=new_node;
            head= new_node;
            l_size++;
          }else{
            Node<T>* new_node= new Node<T>(current->previous,data,current);
            current->previous->next=new_node;
            current->previous=new_node;
            new_node->next=current;
            
            l_size++;
          }
        
        }
      
        void removeat(int index){
          if(index<1 || index >l_size){return;}

          Node<T>* current= head;
          int i=1;
          while(i<index){
           current=current->next;
            i++;
          }
                 if(current->next==nullptr){
                  current->previous->next=nullptr;
                  
          }
          else if(current->previous==nullptr){
                  current=current->next;
                  current->next=nullptr;
                  this->head= current;
                  
          }else{
           current->previous->next=current->next;
           current->next->previous= current->previous;
           
          }
              
          }
        
          Node<T>* reverselist(){
            Node<T>* current=this->head;
            Node<T>* temp;
         while(current!=nullptr){
           temp=current->previous;
           current->previous=current->next;
           current->next=temp;
           current=current->previous;
         }
          temp=this->head;
          this->head=this->tail;
          this->tail=temp;
          return temp;
         }

         d_list& operator=(d_list& c2){
           this->l_size=c2.l_size;
           this->head=c2.head;
           this->tail=c2.tail;
                 return *this;
         }
};


 

#endif