#ifndef STD_HEADER  
#define STD_HEADER

#include <string>
#include <iostream> 
#include <string> 
#include <algorithm>

#endif

class Device{
private:

//int* pointerAssignment(){
//try{int *powerConsumption = new int;}
//  catch (std::bad_alloc & exception) {std::cerr << "powerConsumption memory allocation error - null pointer!!!!" << exception.what();
//  };
//return powerConsumption;
//};

//int* pointerAssignment(){
//try{int *powerConsumption = new int; 
//    if (*powerConsumption == 0) throw "powerConsumption memory allocation error - null pointer!!!!";}
//  //catch (std::bad_alloc & exception) {std::cerr << "powerConsumption memory allocation error - null pointer!!!!" << exception.what();
//  };
//return powerConsumption;
//};

//
int *powerConsumption = new int;

//int* powerConsumption = pointerAssignment(); 

std::string consumptionUnit = "please set unit"; 
std::string localisation = "please set localistion"; 

public:
//constructors, destructor
//konstruktor bezparamterowy. Przypisuje standardową wartość 10.
// he rule of 3/5/0 f? 

Device(){
    
*powerConsumption = 10;  
}; 

Device(const Device &otherDevice){
this->powerConsumption = new int;
};

Device(int Power, std::string Unit, std::string place){
 *powerConsumption = Power;
 consumptionUnit = Unit;
 localisation = place;
};

~Device(){
delete powerConsumption;
};
// functions

void printDataAboutDevice(){
    std::cout << "Information about this device:" << std::endl;
    std::cout << "Power consumption: " << getPowerConsumption() << getConsumptionUnit();
};

// getters, setters

void setPowerConsumption(int Power, std::string Unit){
*powerConsumption = Power;
std::string unit1 = "Watt"; 
std::string unit2 = "Kilowatt"; 
if (Unit !=unit1 && Unit != unit2) {std:: cout << "unit must be in " << unit1 << " or " << unit2 << std::endl;}
else consumptionUnit = Unit;
};

virtual void setPowerConsumption(std::string Unit){
std::string unit1 = "Watt"; 
std::string unit2 = "Kilowatt"; 
if (Unit !=unit1 && Unit != unit2) {std:: cout << "unit must be in " << unit1 << " or " << unit2 << std::endl;}
else consumptionUnit = Unit;
};

virtual void setLocalisation(std::string Place){
localisation = Place;
};

virtual void setPowerConsumption(int Power){
*powerConsumption = Power;
};

std::string getConsumptionUnit(){
return consumptionUnit; 
};

int getPowerConsumption(){
return *powerConsumption;
};

auto getLocalisation(){
    return localisation;
};

};

class Bulb: public virtual Device{
private:
std::string unit = "Watt";
void setPowUnit(std::string unit){
    Device::setPowerConsumption(unit);
    };
    
std::string BulbType = "please set bulb type";

public: 
Bulb(){
std::cout << "Please specify bulb type (halogen, traditional, LED)"<< std::endl; 
};

void setType(std::string type){
    std::string type1 = "halogen";
    std::string type2 = "traditional";
    std::string type3 = "LED";
if (type == type1 || type == type2 ||type == type3){
BulbType = type;
}
else std::cout << "wrong type, please use one of available";
};

std::string getType(){
    return BulbType;
};

void printDataAboutDevice(){
    std::cout << "Power consumption: " << getPowerConsumption() << getConsumptionUnit() << std::endl; 
    std::cout << "Bulb type: " << getType();
};

};

class Fridge: public virtual Device{
// Fridge capacity is determined automatically based on readings from fridge tracker: 
// once a week planned meals scheadule is set by user on fridge tracker. 
// Products are automatically delivered by autonomous shopping robot based on these redings. 
// When robot fills fridge with products it scanns barcodes in oreder to compare needed vs available. 

private:
std::string unit = "Kilowatt";
void setPowUnit(std::string unit){
    Device::setPowerConsumption(unit);
    };
    
int freeCapacity = 0; 

public: 
void setCapacity(int freeCap){
freeCapacity = freeCap;
};

int getCapacity(){
    return freeCapacity;
};

};

class MovingRobot: public virtual Device{

// w niej można zaimplementować filtr kalmana, który później będzie dziedziczyć zarówno ksiarka jak i robot do rozładunku kosza 
//i robot do zakupów, ewntualnie odkurzacz 
// autonomous lawn mower using kalman filter for location 

private: 
std::string unit = "Kilowatt";
void setPowUnit(std::string unit){
    Device::setPowerConsumption(unit);
    };
int BatteryStatus = 0;  //electric lawn mower is assumed 
std::string RobotStatus = NULL; //on/pause/off

int engine = 0; 
int sensors = 0; 

public: 
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

void printDataAboutDevice(){
    std::cout << "Power consumption: " << getPowerConsumption() << getConsumptionUnit();
};
};



class LawnMower: public virtual Device, public virtual MovingRobot{
// when basket is full basket robot swiches baskets for empty one  

private: 
int BasketCapacity = 0; //automatically readed from weight sensor in basket 

public: 
void setCapacity(int capacity){
BasketCapacity = capacity; // basket capacity sensor works in infinite loop calling this methood with 1s delay on each iteration for status update 
};

int getBasketCapacity(){
    return BasketCapacity; // basket robot works in infinite loop calling this methood with 1s delay on each iteration for status update 
}; 
};
