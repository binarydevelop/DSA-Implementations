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
   
};