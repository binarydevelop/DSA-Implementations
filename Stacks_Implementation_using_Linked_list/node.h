template<class T>
class Node{
   private:
      
   public:
     T m_data;
     Node<T>* next;
     Node()=default;
     Node(T data){
        m_data=data;
     }
     Node(T data, Node<T>* next_ptr){
         m_data=data;
         next=next_ptr;
     }

};