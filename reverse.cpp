#include<iostream>
#include<vector>

using namespace std;

vector<int> reverse(vector<int> *modifiedArray) {

	vector<int> dynamic;
	
	for(int i = (*modifiedArray).size()-1; i >= 0; i--) {
		dynamic.push_back((*modifiedArray)[i]);
	}
	
	return dynamic;
}

int main() {
	
	int number;
	
	cout<<"Enter the number of elements needed:";
	cin>>number;
	
	vector<int> dynamicArray(number);
	
	for(int i = 0; i<number; i++) {
		
		int value;
		cout<<"Enter the value for index "<<i<<endl;
		cin>> value;
		
		dynamicArray[i] = value;
	}
	
	vector<int> reversedArray = reverse(&dynamicArray);
	
	for (int j = 0; j < reversedArray.size(); j++) {
		cout<< "The Modified Array:"<< reversedArray[j]<<endl;
	}
	
	return 0;
}
