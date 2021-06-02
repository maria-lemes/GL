/*************************************************************************
Controller.cpp -  description
-------------------
début                : 05/2021
copyright            : (C) 2021
e-mail               : matthieu.moutot@insa-lyon.fr ;
gustavo.giunco-bertoldi@insa-lyon.fr ; mettez vous mails
*************************************************************************/
#include "Controller.h"
#include "Read.h"
#include <iostream>
#include "Sensor.h"
#include "Measurement.h"
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;


Controller::Controller(){
    this->read = new Read() ;
}

Controller::Controller(const char * sensorPath = stdSensorPath, const char * measurementPath = stdMeasurementPath, const char * cleanerPath = stdCleanerPath, const char * userPath = stdUserPath, const char * providerPath = stdProviderPath, const char * attributesPath = stdAttributesPath){
    this->read = new Read(sensorPath, measurementsPath, cleanerPath, userPath, providerPath, attributesPath);
}

int Controller::calculateAirQuality(float latitude, float longitude, int radius, Date date, Date endDate, int timeOption){
  return read->calculateAirQuality(latitude, longitude, radius, date, endDate, timeOption);
}

multimap<double,pair<string,pair<double,double>>>& Controller::calculateSimilarity(string sensorID, Date startDate, Date endDate){
  return read->calculateSimilarity(sensorID, startDate, endDate);
}

bool Controller::sensorSanityCheck(string sensorID, Date myDate, int radius, float threshold){
  return read->sensorSanityCheck(sensorID, myDate, radius, threshold);
}
