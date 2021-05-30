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
#include "Read.h"
#include "Date.h"
#include <string>
#include <list>
using namespace std;

class Controller
{
    public:
    
    Read read;
    int calculateAirQuality(double latitude, double longitude, int radius, Date myDate);

    int calculateAirQuality(float latitude, float longitude, int radius, Date date);

    list<string> calculateSimilarity(string sensorID, Date startDate, Date endDate);

    bool sensorSanityCheck(string sensorID, Date date, int threshold, int nbDays, int coeff);


};

#endif
