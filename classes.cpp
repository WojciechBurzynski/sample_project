#ifndef STD_HEADER  
#define STD_HEADER

#include <string>
#include <iostream> 
#include <algorithm>
#include <vector>
#include <string.h>

#endif

class Exception{
private: 
int ExceptionNumber = 0; 

public: 
void setExceptionNumber(int number){
ExceptionNumber = number;
std::string exception = " ";

// nullpointer exception 
if (number = 1) {
    exception = "memory allocation error - null pointer exception!!!!";
    throw exception;}
};
};

class Device{
private:

int* pointerAssignment(){
    int *powerConsumption = new int;
    if (powerConsumption == 0) {
        Exception ex1; 
        ex1.setExceptionNumber(1) ;
        return powerConsumption;}
    else 
    return powerConsumption;
};

int *powerConsumption = pointerAssignment();

std::string consumptionUnit = "<please set unit>"; 
std::string localisation = "<please set localistion>"; 

public:
// constructors, destructor
// as there is a constructor and destructor specified then the rule of 3/5/0 applies
// destructor and copy constructor are specified. 
// copy assignment operator, move constructor, move assignment operator should be specified in next classs release

Device(){
//base constructor sets value 10 for powert consuption. This is just for example     
*powerConsumption = 10; 
}; 

// copy constructor
Device(const Device & otherDevice){
this->powerConsumption = pointerAssignment();
memcpy(this->powerConsumption, otherDevice.powerConsumption, sizeof(otherDevice.powerConsumption));
this->consumptionUnit = otherDevice.consumptionUnit;
this->localisation = otherDevice.localisation;
};

Device(int Power, std::string Unit, std::string place){
    *powerConsumption = Power;
    localisation = place;

    std::string unit1 = "Watt"; 
    std::string unit2 = "Kilowatt"; 
    std::string unit3 = "<please set unit>";
    if (Unit !=unit1 && Unit != unit2 && Unit != unit3) {
        std:: cout << "unit must be in " << unit1 << " or " << unit2 << std::endl;
        consumptionUnit = "wrong Unit";}
    else consumptionUnit = Unit;
};

virtual ~Device(){
delete powerConsumption;
};

// function

void printDataAboutDevice(){
    std::cout << "Information about this device:" << std::endl << std::endl;
    std::cout << "Power consumption: " << this->getPowerConsumption() << " " << this->getConsumptionUnit() << " " << std::endl;;
    std::cout << "localisation: " << this->getLocalisation() << std::endl << std::endl;
};

// getters, setters

void setPowerConsumption(int Power, std::string Unit){
*powerConsumption = Power;
std::string unit1 = "Watt"; 
std::string unit2 = "Kilowatt"; 
std::string unit3 = "<please set unit>";
if (Unit !=unit1 && Unit != unit2 && Unit != unit3) {
    std:: cout << "unit must be in " << unit1 << " or " << unit2 << std::endl;
    consumptionUnit = "wrong Unit";}
else consumptionUnit = Unit;
};

void setPowerConsumptionUnit(std::string Unit){
std::string unit1 = "Watt"; 
std::string unit2 = "Kilowatt"; 
std::string unit3 = "<please set unit>";
if (Unit !=unit1 && Unit != unit2 && Unit != unit3) {
    std:: cout << "unit must be in " << unit1 << " or " << unit2 << std::endl;
    consumptionUnit = "wrong Unit";}
else consumptionUnit = Unit;
};

void setLocalisation(std::string Place){
localisation = Place;
};

std::string getConsumptionUnit(){
return consumptionUnit; 
};

int getPowerConsumption(){
return *powerConsumption;
};

std::string getLocalisation(){
    return localisation;
};
};

class Bulb: public virtual Device{

private:
std::string BulbType = "<Please specify bulb type (halogen, traditional, LED>";

public: 
Bulb(){
std::string unit = "Watt";
this->setPowerConsumptionUnit(unit);
};

//setters getters
void setType(std::string type){
    std::string type1 = "halogen";
    std::string type2 = "traditional";
    std::string type3 = "LED";
if (type == type1 || type == type2 ||type == type3){
BulbType = type;
}
else std::cout << "<wrong type, please use one of available>";
};

std::string getType(){
    return BulbType;
};

// function

void printDataAboutDevice(){
    std::cout << "Information about this bulb:" << std::endl << std::endl;
    std::cout << "Power consumption: " << this->getPowerConsumption() << " " << this->getConsumptionUnit() << " " << std::endl;;
    std::cout << "localisation: " << this->getLocalisation() << std::endl;
    std::cout << "Bulb type: " << this->getType() << std::endl << std::endl;
};
};

class Fridge: public virtual Device{
// Fridge capacity is determined automatically based on readings from fridge tracker: 
// once a week planned meals scheadule is set by user on fridge tracker. 
// Products are automatically delivered by shopping robot based on these redings. 
// When robot fills fridge with products it scanns barcodes in oreder to compare needed vs available. 

private:
int freeCapacity = 0; 

public: 
Fridge(){
std::string unit = "Kilowatt";
this->setPowerConsumptionUnit(unit);
};

void setCapacity(int freeCap){
freeCapacity = freeCap;
};

int getCapacity(){
    return freeCapacity;
};

// function

void printDataAboutDevice(){
    std::cout << "Information about this Fridge:" << std::endl << std::endl;
    std::cout << "Power consumption: " << this->getPowerConsumption() << " " << this->getConsumptionUnit() << " " << std::endl;;
    std::cout << "localisation: " << this->getLocalisation() << std::endl;
    std::cout << "Fridge current capacity: " << this->getCapacity() << std::endl << std::endl;
};

};

class MovingRobot: public virtual Device{

// w niej można zaimplementować filtr kalmana, który później będzie dziedziczyć zarówno kosiarka 
//jak i robot do rozładunku kosza 
//i robot do zakupów, ewntualnie odkurzacz 
// to be done in next release

private: 
int BatteryStatus = 0;  //electric lawn mower is assumed 
std::string RobotStatus = " "; //on/pause/off

int engine = 0; 
int sensors = 0; 

public: 
MovingRobot(){
std::string unit = "Kilowatt";
this->setPowerConsumptionUnit(unit);
};

void setBatteryStatus(int status){
BatteryStatus = status; // battery sensor works in infinite loop calling this methood with 1s delay on each iteration for status update    
};

void setRobotStatus (std::string status){
RobotStatus = status;
if (RobotStatus == "on") {engine=1; sensors=1;};
if (RobotStatus == "off") {engine=0; sensors=0;}
else {engine=0; sensors=1;}; 
};

int getBatteryStatus(){
    return BatteryStatus; // basket robot also swiches batteries and takes used one for recharge in charging station
}; 
std::string getRobotStatus(){
    return RobotStatus;
}; 

// function

void printDataAboutDevice(){
    std::cout << "Information about this moving robot:" << std::endl << std::endl;
    std::cout << "Power consumption: " << this->getPowerConsumption() << " " << this->getConsumptionUnit() << " " << std::endl;;
    std::cout << "localisation: " << this->getLocalisation() << std::endl;
    std::cout << "Battery: " << this->getBatteryStatus() << std::endl;
    std::cout << "robot status: " << this->getRobotStatus() << std::endl << std::endl;
};
};


class LawnMower: public virtual Device, public virtual MovingRobot{
// when basket is full basket robot swiches baskets for empty one  

private: 
int BasketCapacity = 0; //automatically set by weight sensor in basket 

public: 
void setCapacity(int capacity){
BasketCapacity = capacity; // basket capacity sensor works in infinite loop calling this methood with 1s delay on each iteration for status update 
};

int getBasketCapacity(){
    return BasketCapacity; // basket robot works in infinite loop calling this methood with 1s delay on each iteration for status update 
}; 
};

