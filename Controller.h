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

    int calculateAirQuality(float latitude, float longitude, int radius, Date date);

    map<double,string> calculateSimilarity(string sensorID, Date startDate, Date endDate);

    bool sensorSanityCheck(string sensorID, Date date, float threshold);



};

#endif
