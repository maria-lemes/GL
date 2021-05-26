//
//  Measurement.cpp
//  
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

#include <stdio.h>
#include <iostream>
#include "Measurement.h"

using namespace std;

    Measurement::Measurement(string sID, string att, double val, date time){
        sensorID = sID;
        attribute = att;
        value = val;
        timestamp = time;
    }

    Measurement::Measurement(const Measurement & oneMeasurement){
        sensorID = oneMeasurement.sensorID;
        attribute = oneMeasurement.attribute;
        value = oneMeasurement.value;
        timestamp = oneMeasurement.timestamp;
    }

    string Measurement::getSensorID(){
        return sensorID;
    }

    string Measurement::getAttribute(){
        return attribute;
    }

    double Measurement::getValue(){
        return value;
    }

    date Measurement::getTimestamp(){
        return timestamp;
    }
