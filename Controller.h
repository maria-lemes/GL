/*************************************************************************
                              Controller.h -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ;
    gustavo.giunco-bertoldi@insa-lyon.fr ; maria.zenlemes@insa-lyon.fr
*************************************************************************/
#if ! defined ( Controller_H )
#define Controller_H

#include "Sensor.h"
#include <string>
#include <list>
using namespace std;

class Controller
{
    public:
    
    Read read;
    int calculateAirQuality(double latitude, double longitude, int radius, date myDate);

    std::list<Sensor> calculateSimilarity(string sensorID, date startDate, date endDate);

    bool sensorSanityCheck(string sensorID, date myDate, string threshold, int nbDays, double coeff);

    virtual ~ Controller();

};

#endif
