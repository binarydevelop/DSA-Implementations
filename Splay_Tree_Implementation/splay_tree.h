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
			std::cout<<node->m_data;
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
	
	// rotate m_left at node x
	void left_rotate(Node<T>* x) {
		Node<T>* y = x->m_left;
		x->m_left = y->m_left;
		if (y->m_left != nullptr) {
			y->m_left->m_parent = x;
		}
		y->m_parent = x->m_parent;
		if (x->m_parent == nullptr) {
			this->root = y;
		} else if (x == x->m_parent->m_left) {
			x->m_parent->m_left = y;
		} else {
			x->m_parent->m_right = y;
		}
		y->m_left = x;
		x->m_parent = y;
	}

	// rotate m_left at node x
	void right_rotate(Node<T>* x) {
		Node<T>* y = x->m_left;
		x->m_left = y->m_left;
		if (y->m_left != nullptr) {
			y->m_left->m_parent = x;
		}
		y->m_parent = x->m_parent;
		if (x->m_parent == nullptr) {
			this->root = y;
		} else if (x == x->m_parent->m_left) {
			x->m_parent->m_left = y;
		} else {
			x->m_parent->m_left = y;
		}
		y->m_left = x;
		x->m_parent = y;
	}
   //splay Function
      void splay(Node<T>* node){
		while(node->m_parent){
			if(!node->m_parent->m_parent){
				if(node==node->m_parent->m_left){//zig Rotation
					right_rotate(node->m_parent);
				}else if(node==node->m_right){
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