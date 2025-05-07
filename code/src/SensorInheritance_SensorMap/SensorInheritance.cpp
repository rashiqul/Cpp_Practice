#include "SensorInheritance.h"

// Sensor base class constructor
Sensor::Sensor() 
{
    // Do nothing
}

// Sensor base class destructor
Sensor::~Sensor() 
{
    // Do nothing
}

// TemperatureSensor constructor
TemperatureSensor::TemperatureSensor(float temp) : temperature(temp) 
{
    temperature = temp;
}

// TemperatureSensor destructor
TemperatureSensor::~TemperatureSensor() 
{
    // Do nothing
}

// TemperatureSensor readValue method
float TemperatureSensor::readValue() const 
{
   return temperature;
}

// PressureSensor constructor
PressureSensor::PressureSensor(float press) : pressure(press) 
{
    pressure = press;
}

// PressureSensor destructor
PressureSensor::~PressureSensor() 
{
    // Do nothing
}

// PressureSensor readValue method
float PressureSensor::readValue() const 
{
    return pressure;
}