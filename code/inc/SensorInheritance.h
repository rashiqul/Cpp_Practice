#ifndef SENSORINHERITANCE_H
#define SENSORINHERITANCE_H

#include <iostream>
#include <vector>
#include <memory>

class Sensor 
{
    private:
    
    public:
        // Default Constructor
        Sensor();
        
        // Destructor
        virtual ~Sensor();

        // Read sensor data, virtual function
        virtual float readValue() const = 0;
};

// Derived class for Temperature Sensor
class TemperatureSensor : public Sensor 
{
    private:
        float temperature;

    public:
        // Default Constructor
        TemperatureSensor(float temp);

        // Destructor
        ~TemperatureSensor() override;

        // Read temperature data
        float readValue() const override;
};

// Derived class for Temperature Sensor
class PressureSensor : public Sensor 
{
    private:
        float pressure;
    
    public:
        // Default Constructor
        PressureSensor(float press);

        // Destructor
        ~PressureSensor() override;

        // Read temperature data
        float readValue() const override;
};

#endif // FIXEDARRAY_H