//UNDERSTAND - https://www.youtube.com/watch?v=a96JFhw5Ee4 [CODING Blocks]
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
        return get_height(node->m_left)- get_height(node->m_right);
    }
    Node<T>* ll_rotate(Node<T>* node){
        Node<T>* temp=nullptr;
        temp=node->m_right;
        node->m_right=temp->m_left;
        temp->m_left=node;
        return temp;
    }
     Node<T>* rr_rotate(Node<T>* node){
        Node<T>* temp=nullptr;
        temp=node->m_left;
        node->m_left=temp->m_right;
        temp->m_right=node;
        return temp;
    }
    Node<T>* rl_rotate(Node<T>* node){
        node->m_right=rr_rotate(node->m_right);
        return ll_rotate(node);
    }
        Node<T>* lr_rotate(Node<T>* node){
        node->m_left=ll_rotate(node->m_left);
        return rr_rotate(node);
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
            int bf= balance_factor(node);
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
            }
            return node;
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
    //POST-ORDER_TRAVERSAL
    //IN-ORDER_TRAVERSAL
    //DELETE_NODE
    //SEARCH
    
};