/*************************************************************************
                              Statistics.cpp -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ;
    gustavo.giunco-bertoldi@insa-lyon.fr ; mettez vous mails
*************************************************************************/
#include <Statistics.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

int Statistics::calculateAirQuality(float latitude, float longitude, int radius, date date)
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
        for(auto it = Read::getMeasurementsList().begin(); it != getMeasurementsList().end(); it++)
        {
            if((find(sensors.begin(), sensors.end(), it->sensorID) != sensors.end()) && (it->date == date))
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

    int [10] tabSO2 = {40, 80, 120, 160, 200, 250, 300, 400, 500, INT_MAX};
    int [10] tabNO2 = {30, 55, 85, 110, 135, 165, 200, 275, 400, INT_MAX};
    int [10] tabO3 = {30, 55, 80, 105, 130, 150, 180, 210, 240, INT_MAX};
    int [10] tabPM10 = {7, 14, 21, 28, 35, 42, 50, 65, 80, INT_MAX};

    int indexNO2 = 0;
    int indexSO2 = 0;
    int indexO3 = 0;
    int indexPM10 = 0;

    while(avgNO2 > tabNO2[indexNO2]){
        indexNO2++;
    }
    while(avgSO2 > tabNO2[indexSO2]){
        indexSO2++;
    }
    while(avg03 > tabNO2[index03]){
        index03++;
    }
    while(avgPM10 > tabPM10[indexPM10]){
        indexPM10++;
    }
    int tab[4] = {indexNO2, indexSO2, index03, indexPM10};
    int indexFinal = max_element(tab, tab+4);

    return(indexFinal);
}

/*TODO:
**Définir si les données des mésures seront recuperées de la base lors
du lancement du programme ou à la demande. On suppose que le vecteur
allMeasurements contient déjà toutes les données.

**Définir si cette mérhode rétournera un vecteur avec les Sensors, ou
un vecteur avec les Ids des Sensors (méthode implementée retourne les ids).

**Définir le format de la date
*/
vector<string> Statistics::calculateSimilarity(string sensorID, date startDate, date endDate)
{

  vector<Measurement> allMeasurements;
  //Key : SensorID. Value : Sensor's measurements in the specified period list
  unordered_map<string,vector<double>> otherSensorsMeasurements;
  //Measurements from the sensor whose id is passed in parameter
  vector<double> mySensorMeasurements;
  vector<string> similarSensors;

  /*
  We search in all measurements for those produced in the period of time
  passed in parameter. When found, we add it to its sensor measurement vector
  in our measurements map.
  */
  for (Measurement m : allMeasurements)
  {
    if (m.getDate() >= startDate && m.getDate() <= endDate)
    {
      //Sensor is the one passed in parameter
      if (m.getSensorId() == sensorID)
      {
        mySensorMeasurements.push_back(m.getValue());
      }
      else
      {
        auto sensor = otherSensorsMeasurements.find(m.getSensorId());

        //Sensor id not in the map yet
        if (sensor == measurement.end())
        {
          vector<double> mvec;
          mvec.push_back(m.getValue());
          otherSensorsMeasurements.insert(make_pair(m.getSensorId(),mvec));
        }
        else //Sensor's id found, add measurement value to its vector
        {
          (*sensor).second.push_back(m.getValue());
        }
      }
    }
  }

  //Similarity coefficient from the sensor passed in parameter
  double simCoef = calculateSensorCoefficient(mySensorMeasurements);
  double simTolerance = 3; //EXAMPLE

  /*
  For each sensor and its measurements included in the specified period of
  time passed in parameter, we calculate its similarity coefficient, if
  it's included in the difined tolerance interval, the sensor is added
  to the similar sensors list.
  */
  for (pair<string,vector<double>> m : otherSensorsMeasurements)
  {
    coef = calculateSensorCoefficient(m.second);

    //Verify if sensors are similar
    if (abs(simCoef - coef) <= simTolerance)
    {
      //Push of the similar sensor id to the list
      similarSensors.push_back(m.first);
    }
  }

  return similarSensors;
}
