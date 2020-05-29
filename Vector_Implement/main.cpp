#include<iostream>
#include "vec_class.h"
using namespace std;

int main(){
   vec_class<int> v1(5);
	cout<<v1.size();
	
	cout<<v1.back();
	cout<<v1.begin();

	v1.insertbefore(3,4);
	cout<<v1[3];
	return 0;
}
