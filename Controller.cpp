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
#include <string>
#include <list>
#include <vector>
using namespace std;


    int::Controller calculateAirQuality(double latitude, double longitude, int radius, date myDate){
         Read.calculateAirQuality(latitude, longitude, radius, date);
    }

    vector<string>::Controller calculateSimilarity(string sensorID, date startDate,  date endDate){
            Read.calculateSimilarity(sensorID, startDate, endDate);
    }