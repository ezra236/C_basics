#include<iostream>

using namespace std;

int main() {
	
	int array[] ={2,1,3,4,5,8,9,6};
	
	int size = sizeof(array)/sizeof(array[0]);
	
	int *start = array;
	int *end = array + size - 1;
	
	cout<< *start;
	cout<< *end <<endl;
	
	while(start<end) {
		int temp;
		temp = *start;
		*start = *end;
		*end = temp;
		
		end--;
		start++;
	}
	
	for (int i = 0; i<size; i++) {
		cout<< array[i] <<endl;
	}
}
