#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "classes.cpp"

#ifndef STD_HEADER  
#define STD_HEADER

#include <string>
#include <iostream> 
#include <algorithm>
#include <vector>
#include <string.h>

#endif

// DEVICE test cases 

TEST_CASE("default constructor Device"){
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
    std::string Unit = "Kilowatt"; 
    std::string place = "bathroom";
	// Act
	Device Constructor(Power, Unit, place);
	// Assert
	REQUIRE(&Constructor != NULL);
    REQUIRE(Constructor.getPowerConsumption() == Power); 
    REQUIRE(Constructor.getConsumptionUnit() == Unit); 
    REQUIRE(Constructor.getLocalisation() == place);   
};

TEST_CASE("copy constructor"){
	// Arrange 
    Device deviceFirst; 
    int Power = 123;
    std::string unit = "Watt";
    deviceFirst.setPowerConsumption(Power, unit);
	// Act
	Device deviceSec(deviceFirst);
	// Assert
	REQUIRE(&deviceSec != NULL);
    REQUIRE(deviceSec.getPowerConsumption() == 123); 
};

// setters 

TEST_CASE("set power consumption with correct unit-should set"){
	// Arrange 
    int Power = 100;
    std::string Unit = "Watt"; 
	// Act
	Device device;
    device.setPowerConsumption(Power, Unit);
	// Assert
    REQUIRE(device.getConsumptionUnit() == Unit);  
    REQUIRE(device.getPowerConsumption() == 100); 
};

TEST_CASE("set power consumption with wrong unit-should fail to set"){
	// Arrange 
    int Power = 100;
    std::string Unit = "sampletext"; 
    std::string wrongUnit = "wrong Unit";
	// Act
	Device device;
    device.setPowerConsumption(Power, Unit);
	// Assert
    REQUIRE(device.getConsumptionUnit() == wrongUnit);  
    REQUIRE(device.getPowerConsumption() == 100); 
};

TEST_CASE("power consumption unit set - just unit with default value of power cons"){
	// Arrange 
    std::string Unit = "Watt"; 
	// Act
	Device device;
    device.setPowerConsumptionUnit(Unit);
	// Assert
    REQUIRE(device.getConsumptionUnit() == Unit); 
    REQUIRE(device.getPowerConsumption() == 10);   
};

TEST_CASE("set localistion"){
	// Arrange 
    std::string Place;
	// Act
	Device device;
    device.setLocalisation(Place);
	// Assert
    REQUIRE(device.getLocalisation() == Place);
};

// BULB test cases

TEST_CASE("default constructor Bulb"){
    // Arrange 
    std::string Unit = "Watt"; 
    // Act
	Bulb Constructor;
	// Assert
	REQUIRE(&Constructor != NULL);
    REQUIRE(Constructor.getConsumptionUnit() == Unit);
};


TEST_CASE("bulb type"){
    // Arrange 
    std::string type1 = "halogen";
    // Act
	Bulb Constructor;
    Constructor.setType(type1);
	// Assert
    REQUIRE(Constructor.getType() == type1);
};

// other test cases for fridge, moving robot and other classes to be written in next release

TEST_CASE("default constructor Fridge"){
    // Arrange 
    std::string unit = "Kilowatt";
    // Act
	Fridge Constructor;
	// Assert
	REQUIRE(&Constructor != NULL);
    REQUIRE(Constructor.getCapacity() == 0);
    REQUIRE(Constructor.getConsumptionUnit() == unit);
};

TEST_CASE("setter capacity"){
    // Arrange 
    int capa = 20;
    // Act
	Fridge Constructor;
    Constructor.setCapacity(capa);
	// Assert
    REQUIRE(Constructor.getCapacity() == 20);
};