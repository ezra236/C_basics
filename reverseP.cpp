#include<iostream>
#include<vector>

using namespace std;

void reverse(vector<int> *array) {
	
	int *start = array->data();
	int *end = array->data() + array->size() - 1;
	
	while(start<end) {
		int temp;
		temp = *start;
		*start = *end;
		*end = temp;
		
		end--;
		start++;
	}
	
}

int main() {
	
	int number;
	
	cout<<"Enter the number of elements:";
	cin>> number;
	
	vector<int> dynamic(number);
	
	for(int i = 0; i<number; i++) {
		int value;
		
		cout<< "Enter the value at index "<<i<<endl;
		cin>>value;
		
		dynamic[i] = value;
	}
	
	reverse(&dynamic);
	
	for(int j = 0; j < number; j++) {
		cout<<"The Modified Array:"<<endl;
	    cout<<dynamic[j] <<endl;	
	}
	
	return 0;
}
