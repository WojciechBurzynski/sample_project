#include "classes.cpp"

#ifndef STD_HEADER  
#define STD_HEADER

#include <string>
#include <iostream> 
#include <string> 
#include <algorithm>

#endif

int main(){

try {
    Device dev1; 
    dev1.printDataAboutDevice();

    Bulb bulb1;
    bulb1.printDataAboutDevice();
 
    //Bulb Bulb2 (bulb1);

    MovingRobot robot1; 
    robot1.printDataAboutDevice();



    // wrzucić funkcję obliczającą np całkowity pobór mocy iterowanie po vektorze, sprawdzanie co pobiera najwięcej, a co najmniej 
    // dać jakąś lambdę z if 


    }
catch (std::string exception){
std::cout << exception;
};



return 0;
};
