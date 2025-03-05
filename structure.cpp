#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Student_Info {
	
	string name;
	float id;
	int age;
};

struct Student_Results {
	
	float id;
	float grade;
	string unit;
};


int main() {
	
	int n;
	
	cout<<"Enter the number of students: ";
	cin>>n;
	
	vector<Student_Info> student_information(n);
	
	
	for(int i= 0; i<n; i++) {
		cout<<"Enter the name of the "<< i+1<<" Student: ";
	    cin>> student_information[i].name;
	
	    cout<<"Enter the id of the "<< i+1<<" student: ";
	    cin>>student_information[i].id;
	
	    cout<<"Enter the age of the "<< i+1<<" Student: ";
	    cin>>student_information[i].age;
	}
	
		
	    cout<< "The entered information:"<<endl;
	    
	for (int i = 0; i < n; i++) {
		cout<<"Name: "<<student_information[i].name <<endl;
		cout<<"ID: "<<student_information[i].id <<endl;
		cout<<"AGE: "<<student_information[i].name <<endl;
		cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
	}
	
	
	Student_Results *student_show = new Student_Results[n];
	
	for(int i = 0; i < n; i++) {
		cout<<"Enter the id of the "<< i+1<<" Student: ";
	    cin>>student_show[i].id;
	
	    cout<<"Enter the unit of the "<< i+1<<" student: ";
	    cin>>student_show[i].unit;
	
	    cout<<"Enter the age of the "<< i+1<<" Student: ";
	    cin>>student_show[i].grade;
	}
	
	
	cout<< "The entered information:"<<endl;
		    
	for (int i = 0; i < n; i++) {
		cout<<"ID: "<<student_show[i].id <<endl;
		cout<<"Unit: "<<student_show[i].unit <<endl;
		cout<<"Grade: "<<student_show[i].grade <<endl;
		cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
	}
	
	return 0;
}
