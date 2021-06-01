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
#include "Read.h"
#include <string>
#include <list>
#include <vector>
#include <map>
using namespace std;

Read read;

    int Controller::calculateAirQuality(float latitude, float longitude, int radius, Date sDate, Date eDate, int timeChoice){
            return read.calculateAirQuality(latitude, longitude, radius, sDate, eDate, timeChoice);
    }

    multimap<double,string> Controller::calculateSimilarity(string sensorID, Date startDate, Date endDate){
            return read.calculateSimilarity(sensorID, startDate, endDate);
    }

    bool Controller::sensorSanityCheck(string sensorID, Date myDate, float threshold){
            return read.sensorSanityCheck(sensorID, myDate, threshold);
    }
