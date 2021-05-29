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
#include "Read.h"
#include <string>
#include <list>
#include <vector>
using namespace std;

Read * read = new Read();

    int Controller::calculateAirQuality(float latitude, float longitude, int radius, date date){
            return read->calculateAirQuality(latitude, longitude, radius, date);
    }

    vector<string> Controller::calculateSimilarity(string sensorID, date startDate, date endDate){
            return read->calculateSimilarity(sensorID, startDate, endDate);
    }

    bool Controller::sensorSanityCheck(Sensor sensor, date myDate, int threshold, int nbDays, int coeff){
            return read->sensorSanityCheck(sensor, myDate, threshold, nbDays, coeff);
    }
