/*************************************************************************
                              Controller.cpp -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ;
    gustavo.giunco-bertoldi@insa-lyon.fr ; mettez vous mails
*************************************************************************/
#include "Controller.h"

#include <iostream>

#include "Sensor.h"
#include "Measurement.h"
#include <string>
#include <list>
#include <vector>
using namespace std;

Read read = new Read();

    int::Controller calculateAirQuality(float latitude, float longitude, int radius, date date){
            read.calculateAirQuality(latitude, longitude, radius, date);
    }

    vector<string>::Controller calculateSimilarity(string sensorID, date startDate, date endDate){
            read.calculateSimilarity(sensorID, startDate, endDate);
    }

    bool::Controller sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff){
            read.sensorSanityCheck(sensorID, myDate, threshold, nbDays, coeff);
    }

