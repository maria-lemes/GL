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

    int calculateAirQuality(latitude, longitude, radius, myDate);

    List<Sensors> calculateSimilarity(sensorID, startDate, endDate);

    bool sensorSanityCheck(sensorID, myDate, threshold, nbDays, coeff);

    virtual ~ Controller();

};

#endif
