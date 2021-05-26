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
<<<<<<< HEAD
    int calculateAirQuality(float latitude, float longitude, int radius, Date date);
    void calculateSimilarity(String sensorID, Date date);
    bool sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff);
=======
    int calculateAirQuality(float latitude, float longitude, int radius, date date);
    vector<string> calculateSimilarity(string sensorID, date startDate, date endDate);
>>>>>>> f398294bfc1b027a9e7946dd5287a25aa24e005a
};

#endif
