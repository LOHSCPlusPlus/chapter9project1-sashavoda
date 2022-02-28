#include <iostream>
#include <fstream>
using namespace std;

struct Car{
  enum {MAX_CHAR_LEN=100};
  char carName[MAX_CHAR_LEN];
  double MPG;
  int Cylinders;
  double Displacement;
  double Horsepower;
  double Weight;
  double Acceleration;
  int Model;
  char Origin[MAX_CHAR_LEN];
  bool ValidEntry;
  Car();
};

Car::Car(){
  for(int index = 0; index < MAX_CHAR_LEN; index++){}
  ValidEntry = false;
  MPG = 0.0;
  Cylinders = 0;
  Displacement = 0.0;
  Horsepower = 0.0;
  Weight = 0.0;
  Acceleration = 0.0;
  Model = 0;
  for(int i = 0; i < MAX_CHAR_LEN; i++){}
}

const int MAX_CARS = 500;
Car readCar(ifstream &inFile){
  Car car;
  inFile.get(car.carName, Car::MAX_CHAR_LEN,';');
  inFile.ignore(100,';');

  inFile >> car.MPG;
  inFile.ignore(100,';');
  
  inFile >> car.Cylinders;
  inFile.ignore(100,';');

  inFile >> car.Displacement;
  inFile.ignore(100,';');

  inFile >> car.Horsepower;
  inFile.ignore(100,';');

  inFile >> car.Weight;
  inFile.ignore(100,';');

  inFile >> car.Acceleration;
  inFile.ignore(100,';');

  inFile >> car.Model;
  inFile.ignore(100,';');

  inFile >> car.Origin;


    car.ValidEntry = !inFile.eof();
    return car;
}
// int readCarData reads the data from cars.txt.
int readCarData(Car car[]){
    ifstream carFile("cars.txt");
    int numCars = 0;
  while(carFile.peek() != EOF && numCars < MAX_CARS  ){
   car[numCars] =  readCar(carFile);
   numCars++;
  }
  return numCars; 
}
//void printCar prints the information for a single car.
// void printCars prints the information for all of the cars.
void printCar(Car car);
void printCars(Car car[]){
  for(int index = 0; index < MAX_CARS; index++){
    Car oneCar = car[index];
  
  if(oneCar.ValidEntry == true){
    printCar(oneCar);
  }
  }
}

void printCar(Car car){
  cout << car.carName << ";";
  cout << car.MPG << ";";
  cout << car.Cylinders << ";";
  cout << car.Displacement << ";";
  cout << car.Horsepower << ";";
  cout << car.Weight << ";";
  cout << car.Acceleration << ";";
  cout << car.Model << ";";
  cout << car.Origin << ";";
}
// int readInt reads the user input and validates it to make sure the code doesn't crash when it's run.
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
// void removeCar removes a car from the list.
void removeCar(Car car[]){
  int numRemove = -1;
  while((numRemove < 0) || (numRemove > 500)){
  numRemove = readInt("Enter a number between 0 and 500: ");
  }
  car[numRemove].ValidEntry = false;
}

//void addCar adds a car to the list.
void addCar(Car car[]){
  for(int index = 0; index < MAX_CARS; index++){
  if(car[index].ValidEntry == false){
    cout << "Enter a car name: ";
    cin >> car[index].carName;
    
   car[index].MPG = readInt("Enter mpg: ");
   car[index].Cylinders = readInt("Enter number of cylinders: ");
    car[index].Displacement = readInt("Enter amount of displacement: ");
    car[index].Horsepower = readInt("Enter amount of horsepower: ");
    car[index].Weight = readInt("Enter amount of weight: ");
    car[index].Acceleration = readInt("Enter amount of acceleration: ");
    car[index].Model = readInt("Enter model: ");
    cout << "Enter the car's origin: ";
    cin >> car[index].Origin;
    car[index].ValidEntry = true; 
    break;
  }
  }
}

// void displayMenu displays the options the user can input.
void displayMenu(Car car[]){
  string option;
  while(option != "q"){
cout << "Press 'l', to list,'r' or 'a' to add or remove a car or 'q' to quit: ";
cin >> option;
  
if(option == "r"){
  removeCar(car);
}
if(option == "a"){
  addCar(car);
}
if(option == "l"){
  printCars(car);
}
}
}
// int main calls the functions into the code.
int main(){
  Car cars[MAX_CARS];
    int num = readCarData(cars);
    cout << "Nums: " << num << endl;

  displayMenu(cars);
}
