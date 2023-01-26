#include "classes.cpp"

#ifndef STD_HEADER  
#define STD_HEADER

#include <string>
#include <iostream> 
#include <string> 
#include <algorithm>

#endif

int main(){

Bulb bulb1;

std::cout << "Power consumption of this device is "<< bulb1.getPowerConsumption() << std::endl;
bulb1.setPowerConsumption(30);
std::cout << (bulb1.getPowerConsumption())<< std::endl;

// wrzucić funkcję obliczającą np całkowity pobór mocy iterowanie po vektorze, sprawdzanie co pobiera najwięcej, a co najmniej 
// dać jakąś lambdę z if 


//catch (auto Exception){
// std::cout << Exception << std::endl;
//}

return 0;
};
