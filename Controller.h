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
      
    Controller(const char * sensorPath = stdSensorPath, const char * measurementPath = stdMeasurementPath, const char * cleanerPath = stdCleanerPath, const char * userPath = stdUserPath, const char * providerPath = stdProviderPath, const char * attributesPath = stdAttributesPath);

    int calculateAirQuality(float latitude, float longitude, int radius, Date startDate, Date endDate, int timeChoice);

    multimap<double,pair<string,pair<double,double>>>&  calculateSimilarity(string sensorID, Date startDate, Date endDate);

    bool sensorSanityCheck(string sensorID, Date date, int radius, float threshold);

private:
    Read * read;


};

#endif
