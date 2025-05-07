#include <gtest/gtest.h>
#include <memory>
#include "SensorInheritance.h"

// Test:: SensorMap creation
TEST(SensorMapTest, CreateSensorMap) 
{
    // Arrange and Act
    auto sensorMap = Sensor::createSensorMap();
    
    // Assert
    // Check if the map contains the expected sensors
    EXPECT_EQ(sensorMap.size(), 2);

    // Check if the map contains the expected sensors
    EXPECT_NE(sensorMap.find("TemperatureSensor1"), sensorMap.end());
    EXPECT_NE(sensorMap.find("PressureSensor1"), sensorMap.end());

    // Check if the values are correct
    EXPECT_EQ(sensorMap["TemperatureSensor1"]->readValue(), 24.5f);
    EXPECT_EQ(sensorMap["PressureSensor1"]->readValue(), 101.3f);
}

// Test:: SensorMap creation with pointer
TEST(SensorMapTest, CreateSensorMapWithPointer)
{
    // Arramge and Act
    std::unique_ptr<Sensor> tempSensor = std::make_unique<TemperatureSensor>(24.5f);
    std::unique_ptr<Sensor> pressSensor = std::make_unique<PressureSensor>(101.3f);

    // Assert
    EXPECT_EQ(tempSensor->readValue(), 24.5f);
    EXPECT_EQ(pressSensor->readValue(), 101.3f);
}