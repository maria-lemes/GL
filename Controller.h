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

#include "Sensors.h"
#include <string>
#include <list>
using namespace std;

class Controller
{
    public:

    int calculateAirQuality(float latitude, float longitude, int radius, date date);

    List<Sensors> calculateSimilarity(string sensorID, date startDate, date endDate);

    bool sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff);

    virtual ~ Controller();

};

#endif
