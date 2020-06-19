#include "Node.h"

#include<iostream>
#include<queue>

template<class T>
class b_tree{
   private:
      Node<T>* root;
   public:
      b_tree(){
          root=nullptr;
      }
      
      Node<T>* getroot(){
          return root;
      }
       
        //insertion of node
    void addnode_levelorder(T data){
        Node<T>* new_node=new Node<T>(data);
        if(this->root==nullptr){
            this->root= new_node;
            return ;
        }else{
            std::queue<Node<T>* > Q;
            Q.push(this->root);
            while(!Q.empty()){
                Node<T>* popping_element= Q.front();
                Q.pop();

                if(!popping_element->left){
                    popping_element->left=new_node;
                    return;
                }else if(!popping_element->right){
                          popping_element->right=new_node;
                          return;
                }else{
                    Q.push(popping_element->left);
                    Q.push(popping_element->right);
                }
            }
        }

    }
    
      //Inorder traversal(Depth-First)
      void inorder_traversal(){
          Node<T>* node =this->root;
          inorder_traversal(node);
      }
      void inorder_traversal(Node<T>* node){
          if(node==nullptr){
              return ;
          }
          inorder_traversal(node->left);
          std::cout<<node->m_data<<" ";
          inorder_traversal(node->right);
    }
  
      //preorder traversal(Depth-First)
      void preorder_traversal(){
          preorder_traversal(this->root);
      }
      void preorder_traversal(Node<T>* node){
       if(node==nullptr){
           return ;
       }
       std::cout<<node->m_data<<" ";
       preorder_traversal(node->left);
       preorder_traversal(node->right);

      }
      
      //postorder traversal(Depth-First)
      void postorder_traversal(){
          postorder_traversal(this->root);
      }
      void postorder_traversal(Node<T>* node){
          if(node==nullptr){
              return ;
          }
          postorder_traversal(node->left);
          postorder_traversal(node->right);
          std::cout<<node->m_data<<" ";
      }
      //levelorder traversal(Breadth First)
      void levelorder_traversal(){
        std::queue <Node<T>* > q;
        if(this->root==nullptr){
            return ;
        }
        q.push(this->root);
        while(!q.empty()){ 
            Node<T>* current= q.front();
            std::cout<<current->m_data<<" ";
            if(current->left!=nullptr){
                q.push(current->left);
            }
            if(current->right!=nullptr){
            q.push(current->right);
            }
            q.pop();
    }
}
      
      //deletion of node

      //height of the binary tree 

};
