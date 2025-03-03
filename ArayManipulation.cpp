#include<iostream>
#include<vector>

using namespace std;


vector<int> manipulate (int& n) {
	vector<int> dynamic(n);
	
	
	for(int i = 0 ; i < n ; i++) {
		
		float value;
		
		cout<<"Enter the value for the " <<i<< " index of your array:"<<endl;
		cin>> value;
		
		dynamic[i] = value;
	}
	
	return dynamic;
}


void print (const vector<int>* power) {
	
	for(int i = 0; i < (*power).size(); i++)
	{
		cout<<"THE Array elements " << (*power)[i] <<endl;
	}
}

void reverse (const vector<int> * pvec) {
	
	for(int i = (*pvec).size() - 1; i>=0; i--) {
		cout << "The Reversed Array:" << (*pvec)[i] <<endl;
	}
}

void sorted (vector<int>* rev) {
	
	for(int i= 0; i < (*rev).size()-1; i++) {
		
		int max_index = i;
		
		for(int j= i + 1 ; j < (*rev).size(); j++) {
			if ((*rev)[j] > (*rev)[max_index]) {
				
				max_index = j;
			}
		}
		
		if(max_index != i) {
			int temp = (*rev)[i];
			(*rev)[i] = (*rev)[max_index];
			(*rev)[max_index] = temp;
		}
	}
	
	for (int i = 0; i < (*rev).size(); i++) {
		cout<<"Sorted Array: "<< (*rev)[i] << endl; 
	}
}


int main () {
	
	int number;
	
	cout<<"Enter the number of elements for your dynamic array:" <<endl;
	cin>> number;
	
	vector<int> modifiedArray = manipulate(number);
	
	print(&modifiedArray);
	
	reverse(&modifiedArray);
	
	sorted(&modifiedArray);
	
	return 0;
}
