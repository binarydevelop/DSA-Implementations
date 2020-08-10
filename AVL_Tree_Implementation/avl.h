//UNDERSTAND - https://www.youtube.com/watch?v=a96JFhw5Ee4 [CODING Blocks]
// Rob Edwards 
#include"node.h"
#include<queue>
template<class T>
class avl{
   private:
      Node<T>* root;
    public:
    //CONSTRUCTOR
       avl(){
           root=nullptr;
       }
    //GET_ROOT
    Node<T>* get_root(){
        std::cout<<this->root->m_data;
        return this->root;
    }
    //HEIGHT FUNCTION
    int get_height(){
       return get_height(this->root);   
    }
    int get_height(Node<T>* node){
        int l_height,r_height;
        if(node==nullptr){return -1;}
        else{
        l_height=get_height(node->m_left);
        r_height=get_height(node->m_right);

        if(l_height>=r_height){return l_height+1;}
        else{return r_height+1;}
        }
    }
    //BALANCE_FACTOR
    int balance_factor(Node<T>* node){
        if(node==nullptr){return 0;}
        return get_height(node->m_left)- get_height(node->m_right);
    }
    Node<T>* ll_rotate(Node<T>* &node){
        Node<T>* temp=node->m_right;
        Node<T>* orphan= temp->m_left;
        node->m_right=orphan;
        temp->m_left=node;
        return temp;
    }
     Node<T>* rr_rotate(Node<T>* &node){
        Node<T>* temp=node->m_left;
        Node<T>* orphan =temp->m_right;
        node->m_left=orphan;
        temp->m_right=node;
        return temp;

    }
    Node<T>* rl_rotate(Node<T>* &node){
        node->m_right=rr_rotate(node->m_right);
        return ll_rotate(node);
    }
        Node<T>* lr_rotate(Node<T>* &node){
        node->m_left=ll_rotate(node->m_left);
        return rr_rotate(node);
    }
    //Rebalance Tree
   Node<T>* rebalance(Node<T>* &node){
       int bf= balance_factor(node);
       if(bf>1){
           if(balance_factor(node->m_left)>0){
               return rr_rotate(node);
           }else{return lr_rotate(node);}
       }
       if(bf<-1){
           if(balance_factor(node->m_right)>0){
               return rl_rotate(node);
           }else{return ll_rotate(node);}
       }
       return node;
   }
    //ADD_NODE
    Node<T>* add_node(T data,Node<T>* node){
            if(node==nullptr){
                Node<T>* new_node= new Node<T>(data);
                 return new_node;
            }
            if(data>node->m_data){
                node->m_right=add_node(data,node->m_right);
            } else if(data<node->m_data){
                node->m_left=add_node(data,node->m_left);
            }
        /*    int bf= balance_factor(node);
            //ll case
            if(bf>1 && data<node->m_left->m_data){
                return rr_rotate(node);
            }//rr case
            if(bf<-1 && data>node->m_right->m_data){
                return ll_rotate(node);
            }//lr case
            if(bf>1 && data>node->m_left->m_data){
                  return lr_rotate(node);
            }//rl case
             if(bf<-1 && data<node->m_right->m_data){
                  return rl_rotate(node);
            }*/
            return rebalance(node);
    }
    void add_node(T data){
       this->root=add_node(data,this->root);
    }
    //LEVEL_ORDER_TRAVERSAL
    void level_order(){
        level_order(this->root);
    }
    void level_order(Node<T>*node){
           if(this->root==nullptr){return ;}
           else{
               std::queue<Node<T>* > q;
               q.push(this->root);
               while(!q.empty()){
                   Node<T>* current_node=q.front();
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
    }
    //PRE-ORDER_TRAVERSAL
    void pre_order(){
        pre_order(this->root);
    }
    Node<T>* pre_order(Node<T>* node){
        if(node==nullptr){return nullptr;}
        std::cout<<node->m_data<<" ";
        node->m_left=pre_order(node->m_left);
        node->m_right=pre_order(node->m_right);
        return node;
    }
    //POST-ORDER_TRAVERSAL
    void post_order(){
        post_order(this->root);
    }
    Node<T>* post_order(Node<T>* node){
        if(node==nullptr){return nullptr;}
        
        node->m_left=post_order(node->m_left);
        node->m_right=post_order(node->m_right);
        std::cout<<node->m_data<<" ";
        return node;
    }
    //IN-ORDER_TRAVERSAL
     void in_order(){
        in_order(this->root);
    }
    Node<T>* in_order(Node<T>* node){
        if(node==nullptr){return nullptr;}
        node->m_left=in_order(node->m_left);
        std::cout<<node->m_data<<" ";
        node->m_right=in_order(node->m_right);
        return node;
    }
     //findmin function
     Node<T>* findmin(Node<T>* node){
         if(node==nullptr){return node;}
          else if(node->m_left==nullptr){
                return node;
            }
         return findmin(node->m_left);
     }
     //findmax function
     Node<T>* findmax(Node<T>* node){
         if(node==nullptr){return node;}
          else if(node->m_right==nullptr){
                return node;
            }
         return findmax(node->m_right);
     }

    //DELETE_NODE
    void  delete_node(T data){
        delete_node(data,this->root);
    }
    Node<T>* delete_node(T data,Node<T>* &node){
        if(node==nullptr){return node;}
        if(data<node->m_data){
            node->m_left=delete_node(data,node->m_left);
        }
        if(data>node->m_data){
            node->m_right=delete_node(data,node->m_right);
        }
        else if(data==node->m_data){//1st case
              if(node->m_left==nullptr && node->m_right==nullptr){
                   delete node;
                  node=nullptr;
                  
                  //2nd case
              }else if(node->m_left==nullptr){
                  Node<T>* temp =node;
                  node=node->m_right;
                  delete temp;
              }
               else if(node->m_right==nullptr){
                        Node<T>* temp=node;
                        node=node->m_left;
                        delete temp;
                    }//3rd case
                else {
                    Node<T>* temp=findmin(node->m_right);
                    node->m_data=temp->m_data;
                    node->m_right=delete_node(temp->m_data,node->m_right);
                
                }
        }
        if(node){
            node=rebalance(node);
        }
        
        return node;
    }
    
    //SEARCH
    
};