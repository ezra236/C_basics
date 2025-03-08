#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cctype>

using namespace std;

class Car {
	private:
		vector<string> car_ids;
		vector<int> rentalPrice;
		vector<bool> rent_status;
		bool rentalstatus;
		vector<float> cMileage;
		float currentMileage;
		vector<float> reg_number;
		float registrationNumber;
		vector<bool> gps_data;
		bool gpsTrackingEnabled = false;
		string car_id;
		float rental_price;
		float total = 0.0;
		
				
		void set() {
			
			cout<<"Enter the car ID:\t";
			cin>>car_id;
			car_ids.push_back(car_id);
			
			cout<<"\n";
			
			cout<<"Enter the rental price of the car:\t";
			cin>>rental_price;
			rentalPrice.push_back(rental_price);
			
			cout<<"\n";
			
			cout<<"Enter the milege for the car:\t";
			cin>>currentMileage;
			cMileage.push_back(currentMileage);
			
			cout<<"\n";
			
			cout<<"Enter the registration Number for the car:\t";
			cin>>registrationNumber;
			reg_number.push_back(registrationNumber);
			
			cout<<"\n";
			
			char las;
			
			cout<<"Enter the GPS data for the car: \n\n Enabled(Y) or Not Enabled(N):\t";
			cin>>las;
			
			gpsTrackingEnabled = ( las == 'Y' || las == 'y');
			gps_data.push_back(gpsTrackingEnabled);
			
			cout<<"\n";
			
			cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
			
			set2();	
		}
		
		void Important_Details() {
			
			for(int i = 0; i < car_ids.size(); i++) {
				cout<<"Car IDs:\t"<<car_ids[i] <<"Car Status:\t" << rent_status[i] <<"Car Mileage:\t"<< cMileage[i] <<"Registration Number:\t"<< reg_number[i] <<"GPS data:\t" <<gps_data[i];
			}
			
			Important();
			Important_detail();
		}
		
		
	protected:
		vector<string> car_names;
		string car_name;
		vector<int> manufactured;
		int manufactured_year;
		vector<float> engine;
		float engine_capacity;
		vector<string> service_date;
		string  lastserviceDate;
		
		
		void set2() {
			
			cout<<"Enter the car name:\t";
			cin>>car_name;
			car_names.push_back(car_name);
			
			cout<<"\n";
			
			cout<<"Enter the manufactured year:\t";
			cin>>manufactured_year;
			manufactured.push_back(manufactured_year);
			
			cout<<"\n";
			
			cout<<"Enter the engine capacity of the car:\t";
			cin>>engine_capacity;
			engine.push_back(engine_capacity);
			
			cout<<"\n";
			
			cout<<"Enter the last service date for the car:\t";
			cin>>lastserviceDate;
			service_date.push_back(lastserviceDate);
			
			cout<<"\n";
			
			cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------";
			
			set3();
		}
		
		
		void Important() {
			
			for(int i = 0; i< car_names.size(); i++) {
				cout<<"Car Name:\t"<<car_names[i] <<"Year Manufactured:\t"<<manufactured[i]<<"Engine Capacity:\t"<<engine[i]<<"Last Serviced:\t"<<service_date[i];
			}
		}
		
		
	public:
		vector<string> vehicle_type;
		string type_car;
		vector<string> vehicle_model;
		string model;
		vector<string> vehicle;
		string color;
		vector<string> vehicle_fuel;
		string fuel_type;
		vector<string> vehicle_transmission;
		string transmission;
		vector<int> vehicle_capacity;
		int sitting_capacity;
		
		friend class Calculate;
		friend class Admin;
		
	Car(int capacity, string car_transmission, string fuel, string car_color, string mod, string service, 
        float capacity_engine, int year, string name, string id, float price, bool status, 
        float mileage, float number, bool gps, string type_c)
    : sitting_capacity(capacity), transmission(car_transmission), fuel_type(fuel), color(car_color),
      model(mod), lastserviceDate(service), engine_capacity(capacity_engine), manufactured_year(year),
      car_name(name), rental_price(price), car_id(id), rentalstatus(status), currentMileage(mileage),
      registrationNumber(number), gpsTrackingEnabled(gps), type_car(type_c)
    {
        car_ids.push_back(car_id);
        rentalPrice.push_back(rental_price);
        rent_status.push_back(rentalstatus);
        cMileage.push_back(currentMileage);
        reg_number.push_back(registrationNumber);
        gps_data.push_back(gpsTrackingEnabled);
        
        car_names.push_back(car_name);
        manufactured.push_back(manufactured_year);
        engine.push_back(engine_capacity);
        service_date.push_back(lastserviceDate);
        
        vehicle_type.push_back(type_car);
        vehicle_model.push_back(model);
        vehicle.push_back(color);
        vehicle_fuel.push_back(fuel_type);
        vehicle_transmission.push_back(transmission);
        vehicle_capacity.push_back(sitting_capacity);
    }
    

		
	void set3() {
		
		cout<<"Enter the type of the vehicle:\t";
		cin>>type_car;
		vehicle_type.push_back(type_car);
		
		cout<<"Enter the model of the vehicle:\t";
		cin>>model;
		vehicle_model.push_back(model);
		
		cout<<"\n";
		
		cout<<"Enter the color of the vehicle:\t";
		cin>>color;
		vehicle.push_back(color);
		
		cout<<"\n";
		
		cout<<"Enter the fuel type of the vehicle:\t";
		cin>>fuel_type;
		vehicle_fuel.push_back(fuel_type);
		
		cout<<"\n";
		
		cout<<"Enter the transmission for the vehicle:\t";
		cin>>transmission;
		vehicle_transmission.push_back(transmission);
		
		cout<<"\n";
		
		cout<<"Enter the sitting capacity:\t";
		cin>>sitting_capacity;
		vehicle_capacity.push_back(sitting_capacity);
		
		cout<<"\n";
		
		cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	}
	
	
	void Important_detail() {
		
		for(int i = 0; i < vehicle_model.size(); i++) {
			cout<<"Car Model:\t"<<vehicle_model[i] <<"Car Fuel Type:\t"<<vehicle_fuel[i]<<"Vehicle Transmission:\t"<<vehicle_transmission[i]<<"Vehicle Capacity:\t"<<vehicle_capacity[i];
		}
		
	}
	
	void displaymore(int val) {
		cout<<"The Rental Price:\t"<< rentalPrice[val] <<endl;
	}
	
};


class Sedans: public Car {
		
	public:	
		
		void display(string choice) {
			
			transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
			
			vector<int> indices;
			
			for (size_t i = 0; i < vehicle_type.size(); i++) {
				
				string current = vehicle_type[i];
				
				transform(current.begin(), current.end(), current.begin(), ::tolower);
				
				if(current == choice) {
					indices.push_back(i);
				}
				
				cout<<"Choice:\t"<<choice<<endl;
				
				for(int idx: indices) {
					cout<<"The indexes:\t"<<indices[i];
				}
				
				for(int i = 0; i < indices.size(); i++) {
					
					int value = indices[i];
		
					cout<<"Type of Car:\t"<< vehicle_model[value] << "Model of the Car:\t"<<vehicle[value] <<"Color of the Car:\t"<< vehicle_fuel[value] <<"Transmission of the Car:\t" << vehicle_transmission[value] <<"Capacity of the Car:\t"<< vehicle_capacity[value]<<endl;
					
					displaymore(value);
					
					if(vehicle_model[value] == "sedans") {
						cout<<"------------------------------------------------------------------------------------------------------------------------------------";
						cout <<"Features of Sedans"<<endl;
						
						cout<<"Four-door designs\n comfortable seating\n smooth ride quality\n";
						
						cout<<"Usage:"<<endl;
						
						cout<<"daily commuting, business travel, and family use.";
						cout<<"\n";
						
					}
				}
				
			}
			
		}
		
		
};


class suvs: public Car {
	
	public:
		
		friend class customer;
		
		void display(string choice) {
			
			transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
			
			vector<int> indices;
			
			for (size_t i = 0; i < vehicle_type.size(); i++) {
				
				string current = vehicle_type[i];
				
				transform(current.begin(), current.end(), current.begin(), ::tolower);
				
				if(current == choice) {
					indices.push_back(i);
				}
				
				cout<<"Choice:\t"<<choice<<endl;
				
				for(int idx: indices) {
					cout<<"The indexes:\t"<<indices[i];
				}
				
				for(int i = 0; i < indices.size(); i++) {
					
					int value = indices[i];
		
					cout<<"Type of Car:\t"<< vehicle_model[value] << "Model of the Car:\t"<<vehicle[value] <<"Color of the Car:\t"<< vehicle_fuel[value] <<"Transmission of the Car:\t" << vehicle_transmission[value] <<"Capacity of the Car:\t"<< vehicle_capacity[value]<<endl;
					
					displaymore(value);
					
					if(vehicle_model[value] == "suvs") {
						cout<<"------------------------------------------------------------------------------------------------------------------------------------";
						cout <<"Features of SUVS"<<endl;
						
						cout<<"Higher ground clearance\n spacious interiors\n versatile performance\n";
						
						cout<<"Usage:"<<endl;
						
						cout<<"Great for families, outdoor adventures, and those who need extra cargo space.";
						cout<<"\n";
						
					}
					
				}
				
			}
			
		}
		
		
};



class Convertibles: public Car {
	
	public:
		
		friend class customer;
				
		void display(string choice) {
			
			transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
			
			vector<int> indices;
			
			for (size_t i = 0; i < vehicle_type.size(); i++) {
				
				string current = vehicle_type[i];
				
				transform(current.begin(), current.end(), current.begin(), ::tolower);
				
				if(current == choice) {
					indices.push_back(i);
				}
				
				cout<<"Choice:\t"<<choice<<endl;
				
				for(int idx: indices) {
					cout<<"The indexes:\t"<<indices[i];
				}
				
				for(int i = 0; i < indices.size(); i++) {
					
					int value = indices[i];
		
					cout<<"Type of Car:\t"<< vehicle_model[value] << "Model of the Car:\t"<<vehicle[value] <<"Color of the Car:\t"<< vehicle_fuel[value] <<"Transmission of the Car:\t" << vehicle_transmission[value] <<"Capacity of the Car:\t"<< vehicle_capacity[value]<<endl;
					
					displaymore(value);
					
					if(vehicle_model[value] == "convertibles") {
						cout<<"------------------------------------------------------------------------------------------------------------------------------------";
						cout <<"Features of Convertibles"<<endl;
						
						cout<<"Roofs that can retract or fold away\n providing an open-air driving experience\n";
						
						cout<<"Usage:"<<endl;
						
						cout<<"Popular among drivers who enjoy leisure drives in good weather.";
						cout<<"\n";
						
					}
					
				}
				
			}
			
		}
		
};



class Wagons: public Car {
	
	public:
		
		friend class customer;
				
		void display(string choice) {
			
			transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
			
			vector<int> indices;
			
			for (size_t i = 0; i < vehicle_type.size(); i++) {
				
				string current = vehicle_type[i];
				
				transform(current.begin(), current.end(), current.begin(), ::tolower);
				
				if(current == choice) {
					indices.push_back(i);
				}
				
				cout<<"Choice:\t"<<choice<<endl;
				
				for(int idx: indices) {
					cout<<"The indexes:\t"<<indices[i];
				}
				
				for(int i = 0; i < indices.size(); i++) {
					
					int value = indices[i];
		
					cout<<"Type of Car:\t"<< vehicle_model[value] << "Model of the Car:\t"<<vehicle[value] <<"Color of the Car:\t"<< vehicle_fuel[value] <<"Transmission of the Car:\t" << vehicle_transmission[value] <<"Capacity of the Car:\t"<< vehicle_capacity[value]<<endl;
					
					displaymore(value);
					
					if(vehicle_model[value] == "wagons") {
						cout<<"------------------------------------------------------------------------------------------------------------------------------------";
						cout <<"Features of Wagons"<<endl;
						
						cout<<"Extended rear cargo space while maintaining the comfort and driving dynamics of a sedan.";
						
						cout<<"Usage:"<<endl;
						
						cout<<"A blend of practicality and style, often chosen by families needing extra cargo room.";
						cout<<"\n";
						
					}
					
				}
				
			}
			
		}
		
};


class Trucks: public Car {
	
	public:
		
		friend class customer;
				
		void display(string choice) {
			
			transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
			
			vector<int> indices;
			
			for (size_t i = 0; i < vehicle_type.size(); i++) {
				
				string current = vehicle_type[i];
				
				transform(current.begin(), current.end(), current.begin(), ::tolower);
				
				if(current == choice) {
					indices.push_back(i);
				}
				
				cout<<"Choice:\t"<<choice<<endl;
				
				for(int idx: indices) {
					cout<<"The indexes:\t"<<indices[i];
				}
				
				for(int i = 0; i < indices.size(); i++) {
					
					int value = indices[i];
		
					cout<<"Type of Car:\t"<< vehicle_model[value] << "Model of the Car:\t"<<vehicle[value] <<"Color of the Car:\t"<< vehicle_fuel[value] <<"Transmission of the Car:\t" << vehicle_transmission[value] <<"Capacity of the Car:\t"<< vehicle_capacity[value]<<endl;
					
					displaymore(value);
					
					if(vehicle_model[value] == "trucks") {
						cout<<"------------------------------------------------------------------------------------------------------------------------------------";
						cout <<"Features of Trucks"<<endl;
						
						cout<<"Robust build with an open cargo bed\n Designed for towing and heavy-duty work";
						
						cout<<"Usage:"<<endl;
						
						cout<<"Ideal for both work and recreational activities, especially where hauling capacity is needed.";
						cout<<"\n";
						
					}
					
				}
				
			}
			
		}
		
		
};


class ElectricCars: public Car {
	
	public:
		
		friend class customer;
				
		void display(string choice) {
			
			transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
			
			vector<int> indices;
			
			for (size_t i = 0; i < vehicle_type.size(); i++) {
				
				string current = vehicle_type[i];
				
				transform(current.begin(), current.end(), current.begin(), ::tolower);
				
				if(current == choice) {
					indices.push_back(i);
				}
				
				cout<<"Choice:\t"<<choice<<endl;
				
				for(int idx: indices) {
					cout<<"The indexes:\t"<<indices[i];
				}
				
				for(int i = 0; i < indices.size(); i++) {
					
					int value = indices[i];
		
					cout<<"Type of Car:\t"<< vehicle_model[value] << "Model of the Car:\t"<<vehicle[value] <<"Color of the Car:\t"<< vehicle_fuel[value] <<"Transmission of the Car:\t" << vehicle_transmission[value] <<"Capacity of the Car:\t"<< vehicle_capacity[value]<<endl;
					
					displaymore(value);
					
					if(vehicle_model[value] == "electricals") {
						cout<<"------------------------------------------------------------------------------------------------------------------------------------";
						cout <<"Features of Electric Cars:"<<endl;
						
						cout<<"Powered by electric motors (with or without an internal combustion engine), these vehicles focus on efficiency and lower emissions.";
						
						cout<<"Usage:"<<endl;
						
						cout<<"Gaining popularity for eco-friendly driving and cost-effective operation, available in many of the above formats (sedan, SUV, etc.).";
						cout<<"\n";
						
					}
					
				}
				
			}
			
		}
		
};


class Calculate {		
		
	protected:
		
		void cal(Car & car) {
			
			int days;
			
			cout<<"How many days do you want to rent the car:\t";
			cin>>days;
			
			cout<<endl;
			
			string choice;
			
			cout<<"What type of car do you want:\t";
			cin>>choice;
			
			
            transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

            int firstOccurrenceIndex = -1;  // Use -1 as a flag for "not found"

            for (size_t i = 0; i < car.vehicle_type.size(); i++) {
                string current = car.vehicle_type[i];

                transform(current.begin(), current.end(), current.begin(), ::tolower);
    
                if (current == choice) {
                    firstOccurrenceIndex = i;
                    break;  // Stop after the first occurrence is found
                }
            }

            if (firstOccurrenceIndex != -1) {
                cout << "Choice:\t" << choice << endl;
                cout << "Type of Car:\t" << car.vehicle_model[firstOccurrenceIndex] 
                << "\tModel of the Car:\t" << car.vehicle[firstOccurrenceIndex]
                << "\tColor of the Car:\t" << car.vehicle_fuel[firstOccurrenceIndex]
                << "\tTransmission of the Car:\t" << car.vehicle_transmission[firstOccurrenceIndex]
                << "\tCapacity of the Car:\t" << car.vehicle_capacity[firstOccurrenceIndex] << endl;
         
                float total = car.rentalPrice[firstOccurrenceIndex];
                
                float totalprice = days * total;
                
                cout<<"The Total:\t"<<totalprice<<endl;
                cout<<"----------------------------------------------------------------------------------------------------------";
            
            }
            else {
                cout << "No matching vehicle type found." << endl;
            }

	
		}
	
};


class Admin {
	private:
		string password;
		
		void verify(Car & car) {
			
			cout<<"Enter the password:\t";
			cin>>password;
			
			if (password == "123") {
				
				car.set();
				
			} else {
				cout<<"Password Invalid!";
			}
		}
		
};


class customer {
	
	protected:
		
		void see(Sedans& sed, Trucks&truc, Convertibles&conv, Wagons& wag, suvs & suv, ElectricCars& elec) {
			
			cout<<"WELCOME TO THE VIEW SECTION";
			cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"THE AVAILABLE CAR TYPES:\n";
			cout<<"Suvs\n";
			cout<<"Convertibles\n";
			cout<<"Wagons\n";
			cout<<"Trucks\n";
			cout<<"Sedans\n";
			cout<<"Electric\n";
			
			char lat;
			
			cout<<"SEE MORE ABOUT EACH CAR? YES(Y) OR NO(N)";
			cin>> lat;
			
			if ( lat == 'Y' || lat == 'y') {
				
				enum CarType {
                    SEDANS,
                    SUVS,
                    CONVERTIBLES,
                    TRUCKS,
                    WAGONS,
                    ELECTRIC,
                    UNKNOWN
                };

                auto getCarType = [=](const std::string &name) -> CarType {
                    if (name == "sedans") return SEDANS;
                    else if (name == "suvs") return SUVS;
                    else if (name == "convertibles") return CONVERTIBLES;
                    else if (name == "trucks") return TRUCKS;
                    else if (name == "wagons") return WAGONS;
                    else if (name == "electric") return ELECTRIC;
                    else return UNKNOWN;
                };

                // Usage:
                string name;
                cout << "Enter the type of car:\t";
                cin >> name;
                transform(name.begin(), name.end(), name.begin(), ::tolower);

                CarType type = getCarType(name);

                switch (type) {
                    case SEDANS:
                        sed.display(name);
                        break;
                    case SUVS:
                        suv.display(name);
                        break;
                    case CONVERTIBLES:
                        conv.display(name);
                        break;
                    case TRUCKS:
                        truc.display(name);
                        break;
                    case WAGONS:
                        wag.display(name);
                        break;
                    case ELECTRIC:
                        elec.display(name);
                        break;
                    default:
                        cout << "Invalid Option!";
                        break;
                }
			}
		}
};
		
		 
class Policies {
		
	public:
		
		void policy() { 
		
		    cout << "Car Rental Policies:" << endl << endl;
    
            cout << "1. Driver Eligibility and Age Restrictions:" << endl;
            cout << "   Rental companies often require drivers to be at least 21 or 25 years old." << endl;
            cout << "   Younger drivers may incur additional surcharges, and sometimes an international" << endl;
            cout << "   driver's license is needed if you're renting in a foreign country." << endl << endl;
    
            cout << "2. Insurance and Liability Coverage:" << endl;
            cout << "   Car rental policies usually include requirements for insurance coverage." << endl;
            cout << "   Renters must either provide proof of their personal auto insurance that covers rentals" << endl;
            cout << "   or purchase the rental company's insurance, which may include collision damage waiver (CDW)," << endl;
            cout << "   liability, and theft protection." << endl << endl;
    
            cout << "3. Fuel Policy:" << endl;
            cout << "   Most companies operate on a \"full-to-full\" basis. This means you receive the car with a" << endl;
            cout << "   full tank of gas and must return it full; otherwise, refueling fees or higher fuel charges" << endl;
            cout << "   may apply. Some companies also offer prepaid fuel options." << endl << endl;
    
            cout << "4. Mileage Limits:" << endl;
            cout << "   Depending on the rental agreement, there might be a cap on the number of miles or kilometers" << endl;
            cout << "   you can drive. Exceeding these limits can result in extra charges. Some rentals offer unlimited" << endl;
            cout << "   mileage, so it's important to check the policy before you sign." << endl << endl;
    
            cout << "5. Late Return and Rental Extension Fees:" << endl;
            cout << "   If you return the vehicle later than agreed, rental companies may charge additional fees, often" << endl;
            cout << "   calculated hourly or as a full extra day. It's important to be aware of these policies and contact" << endl;
            cout << "   the company if you anticipate any delays." << endl;
		}
	    
};



int main() {
    string option;

    while (true) {
        cout << "WELCOME TO THE VEHICLE RENTAL SYSTEM\n";
        cout << "CHOOSE AN OPTION\n";
        cout << "CARS INFORMATION -> '0'\n";
        cout << "ADMIN LOGIN -> '1'\n";
        cout << "POLICIES -> '2'\n";
        cout << "HIRE -> '3'\n";
        cout << "EXIT -> 'e'\n";
        cout << "Enter your choice: ";
        cin >> option;
        
        if (option == "0") {
            cout << "\nDisplaying Cars Information...\n";
            customer satisfy;
            satisfy.see();
        }
        else if (option == "1") {
            cout << "\nAdmin Login Selected...\n";
            Admin admin;
            admin.verify();
        }
        else if (option == "2") {
            cout << "\nDisplaying Rental Policies...\n";
            Policies polic;
            polic.policy();
        }
        else if (option == "3") {
            cout << "\nStarting Hire Process...\n";
            Calculate calc;
            calc.cal();
        }
        else if (option == "e" || option == "E") {
            cout << "\nExiting the system. Goodbye!\n";
            break;  // Ext the loop
        else {
            cout << "\nInvalid option! Please try again.\n";
        }
        
        cout << "\n";  // Blank line for better readability
    }
    
}
    
    return 0;
    
}
