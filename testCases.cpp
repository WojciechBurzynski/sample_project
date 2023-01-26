#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "classes.cpp"

#ifndef STD_HEADER  
#define STD_HEADER

#include <string>
#include <iostream> 
#include <string> 
#include <algorithm>

#endif

// Device test cases 

TEST_CASE("base constructor"){
    // Arrange 
    // Act
	Device Constructor;
	// Assert
	REQUIRE(&Constructor != NULL);
    REQUIRE(Constructor.getPowerConsumption() == 10);
};

TEST_CASE("constructor with arguments"){
	// Arrange 
    int Power = 30;
    std::string Unit = "KiloWatt"; 
    std::string place = "bathroom";
	// Act
	Device Constructor(Power, Unit, place);
	// Assert
	REQUIRE(&Constructor != NULL);
    REQUIRE(Constructor.getPowerConsumption() == Power); 
    REQUIRE(Constructor.getConsumptionUnit() == Unit); 
    REQUIRE(Constructor.getLocalisation() == place);   
};

//TEST_CASE("copy constructor"){
//	// Arrange 
//    Device device1; 
//    int Power = 123;
//    device1.setPowerConsumption(Power);
//    const Device device1const = std::as_const(device1);
//	// Act
//	Device device2(const Device &device1const);
//    const_cast<Device&>(device2);
//	// Assert
//	REQUIRE(&device2 != NULL);
//    REQUIRE(device2.getPowerConsumption() == 123); 
//};
///*

//~Device(){
//delete powerConsumption;
//};

// setters 

TEST_CASE("set1"){
	// Arrange 
    int Power = 100;
    std::string Unit = "sampletext"; 
	// Act
	Device device;
    device.setPowerConsumption(Power, Unit);
	// Assert
    REQUIRE(device.getConsumptionUnit() == Unit);   
};

TEST_CASE("set2"){
	// Arrange 
    std::string Unit = "sampletext2"; 
	// Act
	Device device;
    device.setPowerConsumption(Unit);
	// Assert
    REQUIRE(device.getConsumptionUnit() == Unit); 
    REQUIRE(device.getPowerConsumption() == 10);   
};

TEST_CASE("set3"){
	// Arrange 
    int Power = 88;
    std::string unit1 = "please set unit";
	// Act
	Device device;
    device.setPowerConsumption(Power);
	// Assert
    REQUIRE(device.getPowerConsumption() == Power);  
    REQUIRE(device.getConsumptionUnit() == unit1); 
};

TEST_CASE("set4"){
	// Arrange 
    std::string Place;
	// Act
	Device device;
    device.setLocalisation(Place);
	// Assert
    REQUIRE(device.getLocalisation() == Place);
};

TEST_CASE("set5"){
	// Arrange 
    int Power = 100;
    std::string Unit = "sampletext"; 
	// Act
	Device device;
    device.setPowerConsumption(Power, Unit);
	// Assert
    REQUIRE(device.getConsumptionUnit() == Unit);   
};

/*
void setPowerConsumption(int Power, std::string Unit){
*powerConsumption = Power;
std::string unit1 = "Watt"; 
std::string unit2 = "Kilowatt"; 
if (Unit !=unit1 && Unit != unit2) {std:: cout << "unit must be in " << unit1 << " or " << unit2 << std::endl;}
else consumptionUnit = Unit;
};*/