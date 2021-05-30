
#if ! defined ( Read_H )
#define Read_H


#include <vector>
#include <list>
#include <string>
#include <iostream>
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
void readSensor(string nom);
void readMeasurement(string nom);
void readCleaner(string nom);
void readUser(string nom);
void readAttribute(string nom);
void readProvider(string nom);
list<Sensor> getSensorList();
list<Measurement> getMeasurementList();
list<Cleaner> getCleanerList();
list<PrivateIndividual> getPrivateIndividualList();
list<Provider> getProviderList();
list<Attribute> getAttributeList();

//anciennement dans Statistics
int calculateAirQuality(float latitude, float longitude, int radius, Date date);
list<string> calculateSimilarity(string sensorID, Date StartDate, Date endDate);
bool sensorSanityCheck(Sensor sensor, Date date, int threshold, int nbDays, int coeff);

double calculateDistance(Sensor s1, Sensor s2);
list<Sensor> getNeighbors(Sensor sensor, double radius);
};


#endif // Read_H
