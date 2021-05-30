//
//  Measurement.cpp
//
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

#include <stdio.h>
#include <iostream>
#include "Date.h"
#include "Measurement.h"

using namespace std;

    Measurement::Measurement(string sID, string att, double val, Date time){
        sensorID = sID;
        value = val;
        date = time;
        if (att == "NO2")
        {
          attribute = NO2;
        } else if (att == "SO2")
        {
          attribute = SO2;
        } else if (att == "O3")
        {
          attribute = O3;
        } else if (att == "PM10")
        {
          attribute = PM10;
        } else {
          attribute = NO2;
          cout << "Measurement creation error. Attribute \"" << att <<
          "\" invalid" << endl;
        }
    }

    Measurement::Measurement(const Measurement & oneMeasurement){
        sensorID = oneMeasurement.sensorID;
        attribute = oneMeasurement.attribute;
        value = oneMeasurement.value;
        date = oneMeasurement.date;
    }



    string Measurement::getSensorID(){
        return sensorID;
    }

    AttributeId Measurement::getAttribute(){
        return attribute;
    }

    double Measurement::getValue(){
        return value;
    }

    Date Measurement::getDate(){
        return date;
    }
