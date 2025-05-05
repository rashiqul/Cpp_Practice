#include <gtest/gtest.h>
#include "SensorInheritance.h"

// Test: Temperature Sensor set and get value
TEST(TemperatureSensorTest, SetAndGetValue) 
{
    // Arrange
    TemperatureSensor tempSensor(25.0f);
    
    // Act
    tempSensor.readValue();
    
    // Assert
    EXPECT_EQ(tempSensor.readValue(), 25.0f);
}

// Test: Pressure Sensor set and get value
TEST(PressureSensorTest, SetAndGetValue) 
{
    // Arrange
    PressureSensor pressSensor(101.3f);
    
    // Act
    pressSensor.readValue();
    
    // Assert
    EXPECT_EQ(pressSensor.readValue(), 101.3f);
}