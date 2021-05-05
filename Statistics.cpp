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
                push_back(*it);
            }
        }
    }

    if(measurements.empty())
    {
        
    }
}

void Statistics::calculateSimilarity(String sensorID, Date date)
{
    vector<Measurement> allMeasurements;
    unordered_map<>

}
