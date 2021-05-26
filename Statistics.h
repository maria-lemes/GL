/*************************************************************************
                              Statistics.h -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ;
    gustavo.giunco-bertoldi@insa-lyon.fr ; mettez vous mails
*************************************************************************/
#if ! defined ( Statistics_H )
#define Statistics_H

#include "Read.h"
#include "Measurement.h"
#include <string>
using namespace std;

class Statistics
{
public:
    int calculateAirQuality(float latitude, float longitude, int radius, date date);
    vector<String> calculateSimilarity(string sensorID, date startDate, date endDate);
};

#endif
