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
#include "Measurement.h"
#include "Date.h"
#include <string>
#include <list>
using namespace std;

class Controller
{
    public:

    int calculateAirQuality(float latitude, float longitude, int radius, Date date);

    list<string> calculateSimilarity(string sensorID, Date startDate, Date endDate);

    bool sensorSanityCheck(Sensor sensor, Date date, int threshold, int nbDays, int coeff);

    virtual ~ Controller();

};

#endif
