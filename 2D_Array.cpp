#include<iostream>

using namespace std;

int main() {
	
	int rows;
	int cols;
	
	cout<< "Enter the number of rows:";
	cin>>rows;
	
	cout<< "Enter the number of columns:";
	cin>>cols;
	
	int**array = new int *[rows];
	
	for(int i=0; i<rows; i++) {
		array[i] = new int[cols];
	}
	
	int value=1;
	for(int i=0; i< rows;i++) {
		for(int j=0; j<cols; j++) {
			array[i][j] = value++;
		}
	}
	
	
	// Print the 2D array
    cout << "\nThe 2D array is:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
    
    delete[] array;
	
}
