/*************************************************************************
                              Statistics.cpp -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ; mettez vos emails
*************************************************************************/
#include <Statistics.h>

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int Statistics::calculateAirQuality(float latitude, float longitude, int radius, Date date)
{
    Vector<Measurement> measurements;
    Vector<Sensor> sensors;

    if(sensors.empty())
    {
        for(auto it = Read::getSensorsList().begin(); it != Read::getSensorsList().end(); it++)
        {
            if( (it->getLatitude() < latitude+radius) && (it->getLongitude() < longitude+radius) )
            {
                sensors.push_back(*it);
            }
        }
    }

    if(measurements.empty())
    {
        for(auto it = Read.getMeasurementsList().begin(); it != getMeasurementsList().end(); it++)
        {
            if(find(sensors.begin(), sensors.end(), it->sensorID) != sensors.end())
            {
                measurements.push_back(*it);
            }
        }
    }

    float sumNO2, sumSO2, sum03, sumPM10;
    float avgNO2, avgSO2, avg03, avgPM10;
    nb = sensors.size();

    for(auto it = measurements.begin(); it != measurements.end(); it++)
    {
        if(it->Attribute.compare("NO2") == 0)
        {
            sumNO2 += it->value;
        }
        if(it->Attribute.compare("SO2") == 0)
        {
            sumNO2 += it->value;
        }
        if(it->Attribute.compare("O3") == 0)
        {
            sumNO2 += it->value;
        }
        if(it->Attribute.compare("PM10") == 0)
        {
            sumNO2 += it->value;
        }
    }

    avgNO2 = sumNO2 / nb;
    avgSO2 = sumSO2 / nb;
    avg03 = sumO3 / nb;
    avgPM10 = sumPM10 / nb;
}

void Statistics::calculateSimilarity(String sensorID, Date date)
{
    vector<Measurement> allMeasurements;
    unordered_map<>

}
