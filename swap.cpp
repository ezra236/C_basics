#include<iostream>

using namespace std;


int swap (int *p, int*q) {
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
	
	cout<<"p(number1) changed to "<<*p <<endl;
	cout<< "q changed to "<<*q <<endl;
}

int main() {
	
	int number1;
	int number2;
	
	cout<< "Enter the First number:" << endl;
	cin>> number1;
	
	cout<< "Enter the Second number:" <<endl;
	cin>> number2;
	
	swap(&number1, &number2);
	
	return 0;
}
