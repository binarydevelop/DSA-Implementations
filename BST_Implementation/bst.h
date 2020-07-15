#include "node.h"
#include<queue>

template<class T>
class bst{
   private:
       Node<T>* root;
   public:
      bst(){
          root=nullptr;
      } 

      Node<T>* gethead(){
          return this->root;
      }  

        void addnode(Node<T>* node,T data){
            Node<T>* new_node= new Node<T>(data);
            if(node==nullptr){
               this->root= new Node<T>(data); 
               }
            else if(data>node->m_data){
            if(node->m_right!=nullptr){
                addnode(node->m_right,data);
                }else{
                    node->m_right=new_node;
                }
             
           }else
            if(data<node->m_data){
            if(node->m_left!=nullptr){
                addnode(node->m_left,data);
             }else{
                    node->m_left=new_node;
                }
         }
         
     }
        void addnode(T data){
         addnode(this->root,data);
     }
          
        //level_order
        void level_order_traversal(){
            if(this->root==nullptr){
                return;
            }
            std::queue<Node<T>* > q;
            q.push(this->root);
            
            while(!q.empty()){
                 Node<T>* current_node= q.front();
                 q.pop();
                 std::cout<<current_node->m_data<<" ";   
                 if(current_node->m_left!=nullptr){
                     q.push(current_node->m_left);
                 }
                 if(current_node->m_right!=nullptr){
                     q.push(current_node->m_right);
                 }
            }
        }

};