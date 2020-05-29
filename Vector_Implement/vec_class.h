#include<iostream>
#include<initializer_list>
using namespace std;
template<class T>
class vec_class{
	private:
		int m_length;
		T* m_data;
	public:
		//Default Constructor
		vec_class()=default;
		
		//Parametrized Constructor
		vec_class(int length):m_length(length){
				if(length>0){
					m_data=new T[length]{};
				    }
		}
		vec_class(const std::intializer_list<T> &list):vec_class(static_cast<T>(list.size())){
			int count=0;
			for(int i=0;i<list.size();i++){
				m_data[i]=list[i];
			}
		}
			//Destructor
			~vec_class(){
				delete[]m_data;
			}
			
	    //Erase Function
		void erase(){
			delete[]m_data;
			m_length =0;
		}
		
		//Empty Function
		bool isempty(){
			return m_length==0;
		}
		
		//size Function
	    int size(){
		return m_length;
		}
		
		//clear Function
		void clear(){
			delete[]m_data;
		}
		
		//[] overload to Access index
		T& operator[](int index){
			if(index>=0 && index<=m_length){
		}
		return m_data[index];
		}
		//swap Funtion
		void swap(vec_class& v){
			this->m_length={v.m_length};
			for(int i=0;i<m_length;i++){
				this->m_data[i]=v.m_data[i];
			}
		}
		
		//back Function 
		T back(){
			return m_data[m_length];
		}
		
		//begin Function
		T begin(){
			return m_data[0];
		}
		
		//resize Function
		void resize(int newlength){
			if(newlength>m_length){
				T* data=new T[newlength];
				for(int i=0;i<m_length;i++){
					data[i]=m_data[i];
				}
				delete[]m_data;
				m_data=data;
				m_length=newlength;
			}else if(newlength==0){
				erase();
			}
		}
		
		//insertBefore Function
		void insertbefore(int index,int value){
			if(index<=m_length && index>0 ){
				
				T* data= new T[m_length +1];
				for(int i=0;i<index;i++){
					data[i]=m_data[i];
					
				}
				data[index]=value;
				for(int j=index;j<m_length+1;j++){
					data[j+1]=m_data[j];
				}
				delete[] m_data;
				m_data=data;
				++m_length;
			}
		}
		
		//remove Function
		void remove(int index){
			if(index<m_length&& index>=0){
				T* data= new int[m_length-1];
				for(int i=0;i<index;i++){
					data[i]=m_data[i];
				}
				for(int j=index;j<index+1;j++){
					data[j]=m_data[index-1];
				}
				delete[]m_data;
				data=m_data;
				--m_length;
			}
		}
};


