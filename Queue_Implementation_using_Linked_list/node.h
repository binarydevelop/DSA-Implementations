template<class T>
class Node{
  private:
     
  public:
     T m_data;
     Node<T>* m_next;
     Node()=default;
     Node(T data){
         m_data=data;
         m_next=nullptr;
     }
     Node(T data,Node<T>* next){
         m_data=data;
         m_next=next;
     }
     
};