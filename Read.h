
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

//Standard data paths
 static const char * stdSensorPath = "./data/sensors.csv";
 static const char * stdMeasurementPath = "./data/measurements.csv";
 static const char * stdCleanerPath = "./data/cleaners.csv";
 static const char * stdUserPath = "./data/users.csv";
 static const char * stdProviderPath = "./data/providers.csv";
 static const char * stdAttributesPath = "./data/attributes.csv";

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
Read (const char * sensorPath = stdSensorPath, const char * measurementPath = stdMeasurementPath, const char * cleanerPath = stdCleanerPath, const char * userPath = stdUserPath, const char * providerPath = stdProviderPath, const char * attributesPath = stdAttributesPath);
void readSensor(string nom);
void readMeasurement(string nom);
void readCleaner(string nom);
void readUser(string nom);
void readAttribute(string nom);
void readProvider(string nom);
list<Sensor> getSensorList() const;
list<Measurement> getMeasurementList() const;
list<Cleaner> getCleanerList()const;
list<PrivateIndividual> getPrivateIndividualList() const;
list<Provider> getProviderList() const;
list<Attribute> getAttributeList() const;
Sensor * getSensorFromId(string sensorId) const;

int calculateAirQuality(double latitude, double longitude, double radius , Date date, Date endDate, int timeOption);
multimap<double,pair<string,pair<double,double>>>& calculateSimilarity(const string& sensorID, const Date& StartDate, const Date& endDate) const;
bool sensorSanityCheck(string sensorID, Date date, int radius, float threshold);

list <Measurement> getMeasurementsFromSensor (string sensorID) const;
void calculateSensorCoefficient(const list<Measurement> &mySensorMeasurements, double * sums) const;
list<Sensor> findNeighbors(double lat1, double long1, double radius) const;
~Read();
};

#endif // Read_H
