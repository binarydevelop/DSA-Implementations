template<class T>
class Node{
    private:
    public:
       T m_data;
       Node<T>* left;
       Node<T>* right;
       Node(T data){
           this->m_data=data;
           this->left=nullptr;
           this->right=nullptr;
       }
       
};