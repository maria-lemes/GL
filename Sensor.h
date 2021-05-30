/*************************************************************************
                              Sensor -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By
    e-mail               :
*************************************************************************/

#if ! defined ( Sensor_H )
#define Sensor_H

#include <iostream>
using namespace std;


class Sensor
{

public:

    Sensor(string id, double lat, double lon);

    Sensor(const Sensor & oneSensor);

    string getSensorID();

    double getLatitude();

    double getLongitude();
  

private:
        string sensorID;
        double latitude;
        double longitude;

};

#endif // Sensor_H
