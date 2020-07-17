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
      ~bst(){
          deletree(root);
      }
      Node<T>* gethead(){
          return this->root;
      }  

        void addnode(Node<T>* node,T data){
            
            if(this->root==nullptr){
                Node<T>* new_node= new Node<T>(data);
               this->root= new_node;
               }
            else if(data>node->m_data){
            if(node->m_right!=nullptr){

                addnode(node->m_right,data);
                }else{
                    Node<T>* new_node= new Node<T>(data);
                    node->m_right=new_node;
                }
             
           }else
            if(data<node->m_data){
            if(node->m_left!=nullptr){
                addnode(node->m_left,data);
             }else{
                 Node<T>* new_node= new Node<T>(data);
                    node->m_left=new_node;
                }
         }
         
     }
        void addnode(T data){
         addnode(this->root,data);
     }
        void deletree(Node<T>* node){
            if(node){
                 deletree(node->m_left);
                 deletree( node->m_right);
                delete node;
            }
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
        //in-order Traversal 
        void inorder_traversal(Node<T>* node){
            if(node==nullptr){
                return ;
            }
            inorder_traversal(node->m_left);
            std::cout<<node->m_data<<" ";
            inorder_traversal(node->m_right);
        }    
        void inorder_traversal(){
            Node<T>* node =this->root;
            inorder_traversal(node);
        }
        //pre-order
         void preorder_traversal(Node<T>* node){
            if(node==nullptr){
                return ;
            }
            std::cout<<node->m_data<<" ";
            preorder_traversal(node->m_left);
            preorder_traversal(node->m_right);
        }
         void preorder_traversal(){
            Node<T>* node =this->root;
            preorder_traversal(node);
        }
        //postorder
         void postorder_traversal(Node<T>* node){
            if(node==nullptr){
                return ;
            }
            postorder_traversal(node->m_left);
            postorder_traversal(node->m_right);
            std::cout<<node->m_data<<" ";
        }
         void postorder_traversal(){
            Node<T>* node =this->root;
            postorder_traversal(node);
        }

        void deletenode(T key){
            if(this->root==nullptr){
                  std::cout<<"Tree is empty";
              }
              //node is leaf
              
              //node has a single child though the child can have two children
           //node is the root itself
              //node has more than one child
            
        }
         Node<T>* searchkey(T data) { 
        return searchkey(data,this->root);
}

   Node<T>* searchkey(T data, Node<T> *node) {
    if (node == nullptr) { // <-- check if node is null
        return node;
    } else if (node->m_data > data) {
        return searchkey(data, node->m_left);
    } else if (node->m_data < data) {
        return searchkey(data, node->m_right);
    }
    return node; // match found
}
};