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

<<<<<<< HEAD
#include "Read.h"
#include "Measurement.h"
=======
#include <Read.h>
#include <Measurements.h>
>>>>>>> c2ca33d6ccd8a5d0552d93d6ab72f2f521460a09
#include <string>
using namespace std;

class Statistics
{
public:
    int calculateAirQuality(float latitude, float longitude, int radius, date date);
    void calculateSimilarity(string sensorID, date date);
};

#endif
