


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

//We need an Vehicle abstract class

class Vehicle{

protected:
  std::string licensePlate;
  bool isParked;
  int size;
  int location[2];

public:
  
  //This pure virtual function will make this class an abstract class
  //Therefore no constructor or destructor is needed
  virtual void toString() = 0;
};






//We will have three classes(Truck,Car,Motorcycle) that inheret from the Vehicle class


class Truck : public Vehicle{
public:
	//Custom Constructor
	Truck(std::string plate){
	  this->licensePlate = plate;
	  this->isParked = 0;
	  this->size = 5;

	  this->location[0] = -1;
	  this->location[1] = -1;
	}

	~Truck(){
	  std::cout << "\nDeleted Truck : " << licensePlate; 
	}



	void toString(){
	  std::cout << "This is a Truck : " << licensePlate 
		 	<< " with size : " << size
		      	<< "Is it parked : " << isParked
			<< " , Location : " << location[0] << ","<< location[1]
			<< "\n\n";
	}

};


class Car : public Vehicle{

public:
	//Custom Constructor
	Car(std::string plate){
	  this->licensePlate = plate;
	  this->isParked = 0;
	  this->size = 3;
	  this->location[0] = -1;
	  this->location[1] = -1;
	}

	~Car(){
	  std::cout << "\nDeleted Car : " << licensePlate; 
	}



	void toString(){
	  std::cout << "This is a Car : " << licensePlate 
		 	<< " with size : " << size
		      	<< "Is it parked : " << isParked
			<< " , Location : " << location[0] << ","<< location[1]
			<< "\n\n";
	}

};


class Motorcycle : public Vehicle{

public:
	//Custom Constructor
	Motorcycle(std::string plate){
	  this->licensePlate = plate;
	  this->isParked = 0;
	  this->size = 1;
	  this->location[0] = -1;
	  this->location[1] = -1;
	}

	~Motorcycle(){
	  std::cout << "\nDeleted Motorcycle : " << licensePlate; 
	}



	void toString(){
	  std::cout << "This is a Motorcycle : " << licensePlate 
		 	<< " with size : " << size
		      	<< "Is it parked : " << isParked
			<< " , Location : " << location[0] << "," << location[1]
			<< "\n\n";
	}

};


//The main class will be: class ParkingLot

class ParkingLot{
private:
	
	//We will have 5 floor,
	//On every floor, we will 20 available space
	//A total of 100 available spaces
	
	Vehicle* arr[5][20];

	bool isEmpty;
	bool isFull;

	int availableSpots;

public:
	ParkingLot(){
	  
	  clearParkingLot(this->arr);

	  this->isEmpty = 1;
	  this->isFull = 0;
	  this->availableSpots = 100; 
	}
	~ParkingLot(){
	  //We need to delete all the Vehicles that appear in our parking lot
	}


	void printParkingLot();
	int getNumOfAvailableSpots();

	void clearParkingLot(Vehicle* arr[5][20]);	

};




int main(){



  ParkingLot theLot;

  std::cout << "HELLO \n\n\n";


  return 0;
}



void ParkingLot::clearParkingLot(Vehicle* arr[5][20]){

	std::cout << "\nClearing the parking lot\n";

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 20; j++ ){
			arr[i][j] = nullptr;
		}
	}

	
}
