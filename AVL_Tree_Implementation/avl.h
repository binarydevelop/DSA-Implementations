#include"node.h"
template<class T>
class avl{
    private:
     Node<T>* root;

    public:
      avl(){
          root=nullptr;
      }
      Node<T>* getroot(){
          return this->root;
      }

      void insert_node(T data){
          insert_node(data,this->root);
      }

      void insert_node(T data,Node<T>* node){
          if(node==nullptr){
              Node<T>* new_node= new Node<T>(data);
              this->root=new_node;
               heightofnode(node);
          }
         
      }


};