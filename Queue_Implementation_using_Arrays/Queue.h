#include<iostream>
template<class T>
class Queue{
     private:
        int capacity;
        int size;
        int top;
        int rear;
        T* array;
     public:
     Queue()=default;
     Queue(int siz){
         if(siz>0){
         top=-1;
         rear=-1;
         capacity=siz;
         size=0;
         array= new T[capacity];
         }
     }
     void enqueue(T value){
         
         if(rear==capacity-1){
             
            return ;}
         else
         if(rear==-1){
             ++rear;
//find the value of rear here
             ++top;
             array[rear]=value;
             ++size;}
         else{
                ++rear;
                array[rear]=value;
                ++size;
         } 
     }
   
    void displayqueue(){
        for(int i=top;i<=rear;i++){
           
            std::cout<<array[i]<<" ";
        }
    }
     
     void dequeue(){
         if(top==-1){return ;}
         else{
             --size;
             top+=1;}
     }
     int getsize(){return this->size;}
     int getcapacity(){return this->capacity;}
};