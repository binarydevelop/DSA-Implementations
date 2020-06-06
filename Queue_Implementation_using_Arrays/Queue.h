#include<iostream>
template<class T>
class Queue{
     private:
        int length;
        int top;
        int rear;
        T* array;
     public:
     Queue()=default;
     Queue(int siz){
         if(siz>0){
         top=-1;
         rear=-1;
         array= new T[siz];
         }
     }
     void enqueue(T value){
         if(rear==length-1){
            return ;}else
         if(rear==-1){
             ++rear;
//find the value of rear here
             ++top;
             array[rear]=value;
             length+=1;}
         else{
                ++rear;
                array[rear]=value;
                length+=1;
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
             --length;
             top+=1;}
     }
     int getsize(){return this->length;}
};