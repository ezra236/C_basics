#include<iostream>
#include<vector>

using namespace std;

void sort(vector<int> &array, int &number) {
	
	for(int i = 0; i < number -1; i++) {
		
		int max_index = i;
		
		for(int j = i +1; j<number; j++) {
			if(array[j] > array[max_index]) {
				max_index = j;
			}
		}
		
		if( max_index != i) {
			int temp;
			temp = array[i];
			array[i]= array[max_index];
			array[max_index] = temp;
		}
	}
	
}

vector<int> merge(const vector<int> array1, const vector<int>array2) {
	vector<int> merged;
	
	for(int num: array1) {
		merged.push_back(num);
	}
	
	for(int num:array2) {
		merged.push_back(num);
	}
	
	return merged;
}

int main () {
	
	int number;
	
	cout<<"Enter the number of Elements for the first array:"<<endl;
	cin>>number;
	
	vector<int> dynamic(number);
	
	for(int i = 0; i < number; i++) {
		
		int value;
		
		cout<<"Enter the value at index "<<i<<endl;
		cin>> value;
		
		dynamic[i] = value;
	}
	
	sort(dynamic, number);
	
	
	int number2;
	
	cout<<"Enter the number of Elements for the second array:"<<endl;
	cin>>number2;
	
	vector<int> dynamic2(number2);
	
	for(int i = 0; i < number; i++) {
		
		int value2;
		
		cout<<"Enter the value at index "<<i<<endl;
		cin>> value2;
		
		dynamic2[i] = value2;
	}
	
	sort(dynamic2, number2);
	
	cout<< "The First sorted Array:"<<endl;
	
	for(int i = 0; i < number; i++) {
		cout<<"Elements:"<< dynamic[i] <<endl;
	}
	
	cout<< "The Second sorted Array:"<<endl;
	for(int i = 0; i < number2; i++) {
		cout<<"Elements:"<< dynamic2[i] <<endl;
	}
	
	
	vector<int> combined = merge(dynamic, dynamic2);
	
	for (int i = 0; i <combined.size(); i++) {
		cout<<"The merged array after sorting "<<combined[i]<<endl;
	}
	
	return 0;
}
