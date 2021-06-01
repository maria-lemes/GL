
#if ! defined ( Read_H )
#define Read_H


#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <map>
#include "Attribute.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "PrivateIndividual.h"
#include "Provider.h"
#include "Sensor.h"
#include "Date.h"
using namespace std;



class Read
{

private:
list<Sensor> sensorList;
list<Measurement> measurementList;
list<Cleaner> cleanerList;
list<Provider> providerList;
list<Attribute> attributeList;
list<PrivateIndividual> privateIndividualList;


public:
Read ();
void readSensor();
void readMeasurement();
void readCleaner();
void readUser();
void readAttribute();
void readProvider();
list<Sensor> getSensorList() const;
list<Measurement> getMeasurementList() const;
list<Cleaner> getCleanerList()const;
list<PrivateIndividual> getPrivateIndividualList() const;
list<Provider> getProviderList() const;
list<Attribute> getAttributeList() const;
Sensor * getSensorFromId(string sensorId) const;

//anciennement dans Statistics
int calculateAirQuality(float latitude, float longitude, int radius , Date date);
multimap<double,pair<string,pair<double,double> > > calculateSimilarity(string sensorID, Date StartDate, Date endDate);
bool sensorSanityCheck(string sensorID, Date date, float threshold);

//bool isInNeighbors(list<Sensor> neighbors, string sensorID);
list <Measurement> getMeasurementsFromSensor (string sensorID) const;
void calculateSensorCoefficient(list<Measurement> mySensorMeasurements, double * sums);
list <Sensor> findNeighbors(double lat1, double long1, double radius);
~Read();
};

#endif // Read_H
