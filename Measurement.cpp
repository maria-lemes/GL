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
        timestamp = oneMeasurement.time;
    }

    string Measurements::getSensorID(){
        return sensorID;
    }

    string Measurements::getAttribute(){
        return attribute;
    }

    double Measurements::getValue(){
        return value;
    }

    date Measurements::getTimestamp(){
        return timestamp;
    }
