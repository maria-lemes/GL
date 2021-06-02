
#include <stdio.h>
#include <iostream>
#include "Date.h"
#include "Measurement.h"

using namespace std;

Measurement::Measurement(string sID, string att, double val, Date time){
  sensorID = sID;
  value = val;
  timestamp = time;
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
  timestamp = oneMeasurement.timestamp;
}



string Measurement::getSensorID() const{
  return sensorID;
}

AttributeId Measurement::getAttribute() const{
  return attribute;
}

double Measurement::getValue() const{
  return value;
}

Date Measurement::getDate() const{
  return timestamp;
}
