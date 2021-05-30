//
//  Sensor.cpp
//  
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

#include <stdio.h>
#include "Sensor.h"

#include <iostream>
using namespace std;

Sensor::Sensor(string id, double lat, double lon){
    sensorID = id;
    latitude = lat;
    longitude = lon;
}

Sensor::Sensor(const Sensor & oneSensor){
    sensorID = oneSensor.sensorID;
    latitude = oneSensor.latitude;
    longitude = oneSensor.longitude;
}

string Sensor::getSensorID(){
    return sensorID;
}

double Sensor::getLatitude(){
    return latitude;
}

double Sensor::getLongitude(){
    return longitude;
}
