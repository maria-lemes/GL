/*************************************************************************
                              Statistics.h -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ; mettez vos emails
*************************************************************************/
#if ! defined ( Statistics_H )
#define Statistics_H

#include <Read.h>
#include <string>
using namespace std;

class Statistics
{
public:
    int calculateAirQuality(float latitude, float longitude, int radius, Date date);
    void calculateSimilarity(String sensorID, Date date);
};

#endif
