#include "SensorInheritance.h"
#include <unordered_map>

std::unordered_map<std::string, std::unique_ptr<Sensor>> Sensor::createSensorMap()
{
    std::unordered_map<std::string, std::unique_ptr<Sensor>> sensorMap;

    sensorMap["TemperatureSensor1"] = std::make_unique<TemperatureSensor>(24.5f);
    sensorMap["PressureSensor1"] = std::make_unique<TemperatureSensor>(101.3f);

    return sensorMap;
}