#include<iostream>

using namespace std;

inline void swap(int * p, int * q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
	
	cout<<"First number swapped to "<<*p<<endl;
	cout<<"Second number swapped to "<<*q<<endl;
}

int main() {
	
	int first;
	int second;
	
	cout<<"Enter the first number:";
	cin>>first;
	
	cout<<"Enter the second number:";
	cin>>second;
	
	swap(&first, &second);
	
	return 0;
}
