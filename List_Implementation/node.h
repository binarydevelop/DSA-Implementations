template <class T>
class Node{
    private:
       
       
    public:
       T m_data;
       Node<T>* next;
       Node<T>* previous;
        Node()=default;
        Node(T data){
           m_data=data;
           previous=nullptr;
           next=nullptr;
        }
        Node(Node<T>* prev, T data , Node<T>* nex){
           previous=prev; 
           m_data=data;
           next= nex;
        }
       ~Node();
        

};