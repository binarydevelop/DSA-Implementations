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
	//left rotate Function 
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
 //right rotate function 
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
     Node<T>* splay(Node<T>* node){
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
		return node;
	  }

    //find Function
	void find(T key){
		Node<T>* temp = find(key,this->root);
		if(temp){
			splay(temp);
		}
	}
	Node<T>* find(T key,Node<T>* &node){
		if(node==nullptr){return nullptr;}
		
		else{
			if(key>node->m_data){
				find(key,node->m_right);
			}else if(key<node->m_data){
				find(key,node->m_left);
			}
			else if(key==node->m_data){
				std::cout<<"Found\n";
			}else{
				std::cout<<"Not Found \n";
			}
		}
	
		return node;
	}


//Maximum

Node<T>* maximum(Node<T>* node){
	while(node->m_right!=nullptr){
		node= node->m_right;
	}
	return node;
}

//Minimum
Node<T>* minimum(Node<T>* node){
	while(node->m_left!=nullptr){
		node=node->m_left;
	}
	return node;
}

//Join Operation
Node<T>* join(Node<T>* nodeA, Node<T>* nodeB){
	if(nodeA==nullptr){
		return nodeB;
	}
	if(nodeB==nullptr){
		return nodeA;
	}
	Node<T>* max= maximum(nodeB);
	if(max){
		splay(max);
	}
	nodeA->m_right=nodeB;
	nodeB->m_parent=nodeA;
	return nodeA;
}

//split OPeration{Split tree into nodeB and nodeC}
void split(Node<T>* &nodeA,Node<T>* &nodeB, Node<T>* &nodeC){
	splay(nodeA);
	if(nodeA->m_right){
		nodeB=nodeA->m_right;
		nodeB->m_parent=nullptr;
	}else{
		nodeB=nullptr;
	}
	nodeC= nodeA;
	nodeC->m_right=nullptr;
	nodeA=nullptr;
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
void deletenode(T data){
	deleteNodeHelper(data,this->root);
}
void deleteNodeHelper(T data,Node<T>* node) {
    Node<T>* x=nullptr;
		while(node!=nullptr){
		    if(data==node->m_data){
		        x=node;
		        break;
		    }
		    else if(data<node->m_data){
		        node=node->m_left;
		    }else if(data>node->m_data){
		        node=node->m_right;
		    }
		}
		if(x==nullptr){
		    std::cout<<"Not Present ";
		}
		this->root=splay(x);
		if(!root->m_left){
		    Node<T>* temp= this->root;
		    this->root= root->m_right;
		    delete temp;
		}else{
		    Node<T>* temp= this->root;
		    Node<T>* max_left= maximum(root->m_left);
		    root=splay(max_left);
		    root->m_right=temp->m_right;
		    
		    		delete temp;
		}

		
			}
};