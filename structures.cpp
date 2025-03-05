#include<iostream>

using namespace std;

struct Rectangle {
	
	int width;
	int length;
	
	
	int area() {
		return width * length;
	}
	
	int perimeter() {
		return (width + length) * 2;
	}
};

int main() {
	
	Rectangle rect;
	
	cout<< "Enter the length: ";
	cin>>rect.length;
	
	cout<< "Enter the width: ";
	cin>>rect.width;
	
	cout<<"The area of the rectangle is: "<< rect.area() <<endl;
	cout<<"The perimeter of the rectangle is: "<<rect.perimeter() <<endl;
	
	return 0;
	 
}
