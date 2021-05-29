
#if ! defined ( Read_H )
#define Read_H

#include <list>
#include <string>
#include <iostream>
#include "Attribute.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "PrivateIndividual.h"
#include "Provider.h"
#include "Sensor.h"
using namespace std;

class Read
{

private:
list<Sensor> sensorList;
list<Measurement> measurementList;
list<Cleaner> cleanerList;
list<Provider> providerList;
list<Attribute> attributeList;
list<User*> userList;


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
list<User*> getUserList();
list<Provider> getProviderList();
list<Attribute> getAttributeList();

//anciennement dans Statistics
int calculateAirQuality(float latitude, float longitude, int radius, date date);
<<<<<<< HEAD
vector<string> calculateSimilarity(string sensorID, date startDate, date endDate);
=======
vector<string> calculateSimilarity(string sensorID, date StartDate, date endDate);
>>>>>>> db27e8498013f1d10b3b6176827688d0a26f8391
bool sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff);

double calculateDistance(Sensor s1, Sensor s2);
vector<Sensor> getNeighbors(Sensor sensor, double radius);
};


#endif // Read_H
