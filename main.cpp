
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <ctime>

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
  virtual void printPlate() = 0;
  
  
  int getSize(){
  	return size;
  }
  std::vector<int> getLocation(){
  	std::vector<int> myLocation  = {location[0], location[1]};
	return myLocation;
  }
  void setLocation(int i, int j){
  	this->location[0] = i;
	this->location[1] = j;
	return;
  }

  std::string getRandomPlate(){

	std::string plate = "";
  	for(int i = 0; i < 7; i++ )
  	{
		int val;
		//The only valid characters: [48,57] or [65,90]
		do{
		  val = (rand() % 43) + 48;
		}while( val>=58 && val <= 64);

		//We have a valid number, convert into a character and then add to plate
		char ch = (char) val;
		plate = plate + ch;	
		
	}
	return plate;
  
  }




};






//We will have three classes(Truck,Car,Motorcycle) that inheret from the Vehicle class


class Truck : public Vehicle{
public:
	//Custom Constructor
	Truck(){
	  this->licensePlate = getRandomPlate();
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
  
	void printPlate(){
	  std::cout << "Truck :\t\t" << licensePlate << "\n";
	}

};


class Car : public Vehicle{

public:
	//Custom Constructor
	Car(){
	  this->licensePlate = getRandomPlate();
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
	
	void printPlate(){
	  std::cout << "Car :\t\t" << licensePlate << "\n";
	}

};


class Motorcycle : public Vehicle{

public:
	//Custom Constructor
	Motorcycle(){
	  this->licensePlate = getRandomPlate();
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
	
	void printPlate(){
	  std::cout << "Motorcycle :\t" << licensePlate << "\n";
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
	int vehicleCounter;
public:
	ParkingLot(){
	  
	  clearParkingLot();

	  this->isEmpty = 1;
	  this->isFull = 0;
	  this->availableSpots = 100;
	  this->vehicleCounter = 0; 
	}
	~ParkingLot(){
	  //Deleting the parking lot
	}


	void clearParkingLot();	
	void printParkingLot();
	int getNumOfAvailableSpots();
	void tellMeTheAvailableSpots();
	bool canFit(int i, int j,int size);
	
	bool parkTheVehicle(Vehicle* vehicle);
};



//Main function prototypes
void populateVehicleVector(std::vector<Vehicle*>& myVehicleVect, int vehicleLimit);
void displayVehicleVector(std::vector<Vehicle*>& myVect);

int main(){

  //Required to generate random elements
  srand(time(NULL));




  ParkingLot theLot;

  //Lets build a vector of pointers to random vehicles
  int vehicleLimit;
  std::cout << "\n\nHow many random vehicles should we create: ";
  std::cin >> vehicleLimit;

  std::vector<Vehicle*> myVehicleVect;

  
  populateVehicleVector(myVehicleVect, vehicleLimit);

  //we currently have a vector of vehicle pointers

  //What are the vehicles that we created?
  displayVehicleVector(myVehicleVect);

  theLot.printParkingLot();
  theLot.tellMeTheAvailableSpots();

  std::cout << "\n\n";


  std::cout << "Placing all the vehicles into our parking lot\n";

  for(Vehicle* temp : myVehicleVect){
  	if(theLot.parkTheVehicle(temp)){
	  std::cout << "Inserted:\t"; 
	  temp->printPlate();
	}
	else{
	 std::cout << "Failed:\t\t"; 
	 temp->printPlate();
	}
	
  }
  std::cout <<"\n\n";
  theLot.printParkingLot();
  theLot.tellMeTheAvailableSpots();
  std::cout <<"\n\n";

  
  return 0;
}

  

void populateVehicleVector(std::vector<Vehicle*>& myVehicleVect, int vehicleLimit){

	  for(int i = 0; i < vehicleLimit; i++){
  	 	 
		  //Range : {1,2,3}
	 	 int randElement = (rand() % 3) + 1;	
  
 	 	  switch(randElement){
	  
		  	case 1:
				//Build a Motorcycle
				myVehicleVect.push_back(new Motorcycle());
				break;
			
			case 2:
				//Build a Car
				myVehicleVect.push_back(new Car());
				break;

			case 3:
				//Build a Truck
				myVehicleVect.push_back(new Truck());
				break;

	  
	  		default:
				break;
	  	
	  	}
  
  	}	
	return;
}


void displayVehicleVector(std::vector<Vehicle*>& myVect){
	
	std::cout << "We are printing all our vehicles:\n";	
	for(Vehicle* temp : myVect){
		temp->printPlate();
	}	
	return;
}




void ParkingLot::clearParkingLot(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 20; j++ ){
			this->arr[i][j] = nullptr;
		}
	}
	this->isEmpty = 1;
	this->vehicleCounter = 0;
	
}



void ParkingLot::printParkingLot(){

	std::cout << "\n\n Printing Parking Lot: \n";
	//Display the parking lot
	for(int  i = 0; i <5; i++ ){
	  std::cout << " ";
	  for(int j = 0; j < 20 ; j++ ){
	
	  		  
		if(arr[i][j]){
		  std::cout << arr[i][j]->getSize() << "  ";
		} 
		else{
		  std::cout << "0" << "  ";
		}
	  }
	  std::cout << "\n"; 
	}


}

int ParkingLot::getNumOfAvailableSpots(){
	return this->availableSpots; 
}

	
void ParkingLot::tellMeTheAvailableSpots(){

	std::cout << "\n\nAvailable Spots: " << availableSpots << "\n\n";
	
	std::vector< std::vector<int> > myVect(5);
	
	
	
	//Display the parking lot
	for(int  i = 0; i <5; i++ ){
	  for(int j = 0; j < 20 ; j++ ){
		if(arr[i][j] == nullptr){
		  myVect[i].push_back(j);	
		} 
	  }
	}
	

	for(int i = 0; i < 5; i++){
		int counter = 0;
		std::cout << "\nFLOOR "<< i << " :\n\t";
		
		for(int k : myVect[i]){
			
			
			std::cout << "["<< i << "," << k << "]\t";
			++counter;

			if(counter % 10 == 0){
			  std::cout << "\n";
		          std::cout << "\t";
			}
		}
	}
}


bool ParkingLot::parkTheVehicle(Vehicle* vehicle){

	//We need to take into account the size of the vehicle
	//and the avaiable spots in the parking lot
	
	int size = vehicle->getSize();

	if(size > availableSpots)
	{ 
		return 0;
	}

	//Only for the first case that the parking lot is empty
	if(isEmpty == 1){
		
		for(int i = 0; i < size; i++){
		  arr[0][i] = vehicle;
		  --availableSpots;
		}
		vehicle->setLocation(0,0);

		++vehicleCounter;

		isEmpty = 0;
		return 1;
	}


	//Now go park the car, find the first available location, and check if it fits.
	for(int i = 0; i<5; i++ ){
		for(int j = 0; j <= 20 - size; j++){
			
			if(arr[i][j] == nullptr){
			  	
				if( canFit(i,j,size) ){
					//Our vehicle fits on the following spots
					int limit = j+size;

					for(int m = j; m < limit ;m++){

						arr[i][m] = vehicle;

						--availableSpots;
					}
					vehicle->setLocation(i,j);

					++vehicleCounter;

					if(vehicleCounter == 0){
					  this->isFull == 1;
					}

					return 1;
				}
			}
		        
		
		}
	
	}
	//Our vehicle does not fit in the parking lot
	return 0;
}


bool ParkingLot::canFit(int i, int j,int size){
	
	int lastIndex = j+size -1;
	if(lastIndex >19){
		return 0;
	}
	
	
	//Check the 2D array, we need the following spots to be free
	for( int y = j ; y <= lastIndex; ++y){
		if(arr[i][y] != nullptr){
		  return 0;
		}
	}

	return 1;

}


