#include<iostream>

template<class T>
class Node{
     private:    
     public:
        T m_data;  
        Node<T>* m_left;
        Node<T>* m_right;
       
   
     Node(T data){
         m_data=data;
         m_left=nullptr;
         m_right=nullptr;
     }
    
     int max(int a ,int b){
         if(a>b){
             return a;
         }else{
             return b;
         }
     }
     int heightofnode(Node<T>* node){
         int left_height,right_height=0;
         if(node->m_left!=nullptr){
             left_height++;
         }
         if(node->m_right!=nullptr){
             right_height++;
         }
         return (max(left_height,right_height))+1;
     }
};