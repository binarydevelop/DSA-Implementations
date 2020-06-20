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
            q.pop();
            std::cout<<current->m_data<<" ";
            if(current->left!=nullptr){
                q.push(current->left);   
            }
            if(current->right!=nullptr){
                q.push(current->right); 
            }
            
   
    }
}
      
      //remove_node
      void removenode(Node<T>* root, Node<T>* node_to_delete){
            if(root==nullptr){return ;}
            if(root== node_to_delete){
                delete node_to_delete;
                root==nullptr;
                return ;
            }
            if(root->left==node_to_delete){
                delete node_to_delete;
                root->left=nullptr;
                return ;
            }
             if(root->right==node_to_delete){
                delete node_to_delete;
                root->right=nullptr;
                return ;
            }
       removenode(root->left, node_to_delete);
       removenode(root->right,node_to_delete);
      }

      //deletion of node
      void delete_node(T data){
          if(root==nullptr){
              return ;
          }
          if(root->left==nullptr && root->right==nullptr){
              if( root->m_data==data){
                   delete root;
                   root=nullptr;
              }
          }
          
              std::queue<Node<T>* > Q;
              Q.push(this->root);
              Node<T>* curr_node=nullptr;
              Node<T>* key_node=nullptr;
              
              while(!Q.empty()){
                  curr_node= Q.front();
                  Q.pop();
                  if(curr_node->m_data==data){
                      key_node=curr_node;
                  }
                  if(curr_node->left){
                      Q.push(curr_node->left);
                  }
                  if(curr_node->right){
                      Q.push(curr_node->right);
                  } 
              }
              //at the end of queue current node becomes the last node.
              if(key_node){
              key_node->m_data=curr_node->m_data;
              removenode(this->root,key_node);
              }
              else{
                  return ;}
          }
      
      //searchnode
     bool searchnode(T data){
              std::queue<Node<T>* > Q;
              Q.push(this->root);
              while(!Q.empty()){
                  Node<T>* curr_node;
                  curr_node= Q.front();
                  Q.pop();
                  if(curr_node->m_data==data){
                     return true;
                  }
                    if(curr_node->left){Q.push(curr_node->left);}
                    if(curr_node->right){Q.push(curr_node->right);}      
     }
     return false;
}

      //height of the binary tree 
      int height_of_tree(){
          return height_of_tree(this->root);
      }
      int height_of_tree(Node<T>* root){
          //base case
          //If we are passing a leaf node then we need to return -1 so the height cancels out with +1.
          if(root==nullptr){return 0;}
          int ldepth= height_of_tree(root->left);
          int rdepth= height_of_tree(root->right);
          if(ldepth>rdepth){
              return ldepth+1;
          }
          else{
              return rdepth+1;
          }
      }

};
