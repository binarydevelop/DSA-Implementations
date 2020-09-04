#include"node.h"
#include<iostream>
template<class T>
class splay_tree{
private:
	Node<T>* root;
public:
	splay_tree(){
		this->root=nullptr;
		
	}
    //GetNode
	Node<T>* getroot(){
		return this->root;
		std::cout<<this->root->m_data;
	}
	//-----------------------------Traversal-----------------------

			//----------------------pre order--------------------------
	void preorder(){
		preorder(this->root);
	}

	void preorder(Node<T>* node){
		if(node==nullptr){return;}
		else{
			std::cout<<node->m_data;
			preorder(node->m_left);
			preorder(node->m_right);
		}
	}

			//----------------------in order--------------------------
	void inorder(){
		inorder(this->root);
	}
	void inorder(Node<T>* node){
		if(node==nullptr){return ;}
		else{
			inorder(node->m_left);
			std::cout<<node->m_data<<" ";
			inorder(node->m_right);
		}
	}
			//----------------------post order--------------------------
	void postorder(){
		postorder(this->root);
	}

	void postorder(Node<T>* node){
		if(node==nullptr){return ;}
		else{
			postorder(node->m_left);
			postorder(node->m_right);
			std::cout<<node->m_data;
		}
		
	}
	
 void left_rotate(Node<T>* node){
     if(node==nullptr){return ;}
     else{
         Node<T>* temp= node->m_right;
         node->m_right=temp->m_left;
         if(temp->m_left){
             temp->m_left->m_parent=node;
         }
         temp->m_parent=node->m_parent;
         if(node->m_parent==nullptr){
             this->root=temp;
         }else if(node==node->m_parent->m_left){
             node->m_parent->m_left=temp;
         }else if(node== node->m_parent->m_right){
             node->m_parent->m_right=temp;
         }
         temp->m_left=node;
         node->m_parent=temp;
     }
    
 }
void right_rotate(Node<T>* node){
        Node<T>* temp=node->m_left;
        node->m_left=temp->m_right;
        if(temp->m_right){
            temp->m_right->m_parent=node;
        }
        temp->m_parent= node->m_parent;
        if(node->m_parent==nullptr){
            this->root=temp;
        }else if(node==node->m_parent->m_left){
            node->m_parent->m_left=temp;
        }else if(node== node->m_parent->m_right){
            node->m_parent->m_right=temp;
        }
        temp->m_right=node;
        node->m_parent=temp;
   }

   //splay Function
      void splay(Node<T>* node){
		while(node->m_parent){
			if(!node->m_parent->m_parent){
				if(node==node->m_parent->m_left){//zig Rotation
					right_rotate(node->m_parent);
				}else if(node==node->m_parent->m_right){
					left_rotate(node->m_parent);
				}
			}
			else if(node==node->m_parent->m_left && node->m_parent==node->m_parent->m_parent->m_left){//Zig Zig 
				right_rotate(node->m_parent->m_parent);
				right_rotate(node->m_parent);
			}else if(node== node->m_parent->m_right && node->m_parent==node->m_parent->m_parent->m_right){//zag zag
				left_rotate(node->m_parent->m_parent);
				left_rotate(node->m_parent);
			}else if(node==node->m_parent->m_left && node->m_parent== node->m_parent->m_parent->m_right){
				right_rotate(node->m_parent);
				left_rotate(node->m_parent);
			}else if(node== node->m_parent->m_right && node->m_parent== node->m_parent->m_parent->m_left){
				left_rotate(node->m_parent);
				right_rotate(node->m_parent);
			}
		}
	  }



	//Insert Function
void insert(T data){
	Node<T>* new_node= new Node<T>(data);
	Node<T>* y= nullptr;
	Node<T>* x= this->root;
	while (x!= nullptr){
		y=x;
		if(new_node->m_data<x->m_data){
			x= x->m_left;
		}
		else{
			x=x->m_right;
		}
	}
		// y is a m_parent of x
		new_node->m_parent=y;
		if(y==nullptr){
			this->root=new_node;
		}else if(new_node->m_data<y->m_data){
			y->m_left=new_node;
		}else{
			y->m_right=new_node;
		}
	
	splay(new_node);
}

};