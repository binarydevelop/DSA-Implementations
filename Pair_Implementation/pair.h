#include <utility>
#ifndef PAIR_H
#define PAIR_H

template<class T, class K>
struct Pair{
    private:
    T m_first;
    K m_second;
    public:
  Pair(T first, K second):m_first(first),m_second(second){}
  Pair()=default;
  
  T getfirst(){return m_first;}
  K getsecond(){return m_second;}
  Pair& operator=(const Pair& p){
    this->m_first=p.m_first;
    this->m_second=p.m_second;
    return *this;
  }

  void swap(Pair& p2 ){
       T temp_first=m_first;
       T temp_second=m_second;
       m_first=p2.m_first;
       m_second=p2.m_second;
       p2.m_first=temp_first;
       p2.m_second=temp_second;
  }


};

#endif