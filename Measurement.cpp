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

    Measurement::Measurement(string sID, string att, double val, struct date time){
        sensorID = sID;
        attribute = att;
        value = val;
        date = time;
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

    string Measurement::getAttribute(){
        return attribute;
    }

    double Measurement::getValue(){
        return value;
    }

    struct date Measurement::getDate(){
        return date;
    }
