#include "classes.cpp"

#ifndef STD_HEADER  
#define STD_HEADER

#include <string>
#include <iostream> 
#include <algorithm>
#include <vector>
#include <string.h>

#endif

int main(){

try {

    std::vector<Device> AllDevices;
    
    Device dev1; 
    dev1.setPowerConsumption(4, "Watt");
    dev1.printDataAboutDevice();
    AllDevices.push_back(dev1);

    Bulb bulb1;
    bulb1.setPowerConsumption(4, "Watt");
    bulb1.printDataAboutDevice();
    AllDevices.push_back(bulb1);
 
    Bulb bulb2 (bulb1);
    bulb2.setPowerConsumption(8,"Watt");
    bulb2.printDataAboutDevice();
    AllDevices.push_back(bulb2);

    MovingRobot robot1; 
    bulb2.setPowerConsumption(15,"Kilowatt");
    robot1.printDataAboutDevice();
    AllDevices.push_back(robot1);

    Fridge fridge1; 
    fridge1.printDataAboutDevice(); 
    AllDevices.push_back(fridge1);

    int sum = 0;

    for (std::vector<Device>::iterator it1 = AllDevices.begin(); it1 != AllDevices.end(); it1++){
        if (it1->getConsumptionUnit() == "Watt"){
            sum += it1->getPowerConsumption();}
        else if (it1->getConsumptionUnit() == "<please set unit>"){
            std::cout << " no possibility to calculate as some units are not set" << std::endl;
            sum = -1;}
        else {
            sum += it1->getPowerConsumption()*1000;};           
        };

    if (sum == -1) {}
    else std::cout << "sum of power consumptions of your devices is " << sum << " Watt" << std::endl; 

}
catch (std::string exception){
std::cout << exception;
};

return 0;
};
