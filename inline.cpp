#include<iostream>

using namespace std;

inline int square(int num) {
	return num*num;
}

int main () {
	
	int number;
	
	cout<<"Enter the number to be squared:";
	cin>> number;
	
	cout<<"The square of "<<number<<" is "<<square(number);
	
	return 0;
}
