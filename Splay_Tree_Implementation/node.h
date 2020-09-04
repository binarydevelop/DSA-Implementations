template<class T>
class Node{

   public:
   Node<T>* m_left;
   Node<T>* m_right;
   Node<T>* m_parent;
   T m_data;

      Node(T data){
         m_left=nullptr;
         m_right=nullptr;
         m_parent=nullptr;
         m_data=data;
      }

};