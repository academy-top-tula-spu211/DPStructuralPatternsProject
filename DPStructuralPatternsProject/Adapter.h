#pragma once
#include <iostream>

using namespace std;

class ISensorTarget
{
public:
	virtual float GetSensorData() = 0;
	virtual ~ISensorTarget() {}
};

class CelsiusSensor
{
public:
	float GetTemperature()
	{
		return 36.6;
	}
};

class FahrenheitSensor
{
public:
	float GetTemperatureFahrenheit()
	{
		return 25.5;
	}
};

class CelsiusSensorAdapter : public ISensorTarget
{
	CelsiusSensor* sensor;
public:
	CelsiusSensorAdapter(CelsiusSensor* sensor)
		: sensor{ sensor } {}
	float GetSensorData()
	{
		return sensor->GetTemperature();
	}
	~CelsiusSensorAdapter() { delete sensor; }
};

class FahrenheitSensorAdapter : public ISensorTarget
{
	FahrenheitSensor* sensor;
public:
	FahrenheitSensorAdapter(FahrenheitSensor* sensor)
		: sensor{ sensor } {}
	float GetSensorData()
	{
		return (sensor->GetTemperatureFahrenheit() - 32) * 5.0 / 9.0;
	}
	~FahrenheitSensorAdapter() { delete sensor; }
};


