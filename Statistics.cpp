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
#include <cmath>

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

/*TODO:
**Il faut définir si les données des mésures seront recuperées de la base lors
du lancement du programme ou à la demande. On suppose que le vecteur
allMeasurements contient déjà toutes les données.

**Il faut définir si cette mérhode rétournera un vecteur avec les Sensors, ou
un vecteur avec les Ids des senseurs (méthode implementée retournant les ids).

--
*/
vector<String> Statistics::calculateSimilarity(String sensorID, Date date)
{

  vector<Measurement> allMeasurements;
  //Key : SensorID. Value : Sensor's measurements in the specified period list
  unordered_map<String,vector<double>> otherSensorsMeasurements;
  //Measurements from the sensor whose id is passed in parameter
  vector<double> mySensorMeasurements;
  vector<String> similarSensors;

  /*
  We search in all measurements for those produced in the period of time
  passed in parameter. When found, we add it to its sensor measurement vector
  in our measurements map.
  */
  for (Measurement m : allMeasurements)
  {
    if (m.getDate() == date)
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
  for (pair<String,vector<double>> m : otherSensorsMeasurements)
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
