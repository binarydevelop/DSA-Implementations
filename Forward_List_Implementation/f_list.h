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
           Node<T>* new_node= new Node<T>(50);
           if(head==nullptr){
               this->head= new_node;
               this->tail=new_node;
               this->f_list_size+=1;
           }
       }
};