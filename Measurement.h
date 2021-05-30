/*************************************************************************
                              Measurement -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By
    e-mail               :
*************************************************************************/

#if ! defined ( Measurement_H )
#define Measurement_H

#include <iostream>
#include "Date.h"
using namespace std;

enum AttributeId {NO2, SO2, O3, PM10};
/*
  NO2: 0
  SO2: 1
  O3: 2
  PM10: 3
*/

class Measurement
{
    public:

        Measurement(string sID, string att, double val, Date time);

        Measurement(const Measurement & oneMeasurement);

        string getSensorID();

        AttributeId getAttribute();

        double getValue();

        Date getDate();


    private:
            string sensorID;
            AttributeId attribute;
            float value;
            Date date;

};

#endif // Measurement_H
