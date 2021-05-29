
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
std::list<Sensor> sensorList;
std::list<Measurement> measurementList;
std::list<Cleaner> cleanerList;
std::list<Provider> providerList;
std::list<Attribute> attributeList;
std::list<User> userList;


public:
void readSensor(std::string nom);
void readMeasurement(std::string nom);
void readCleaner(std::string nom);
void readUser(std::string nom);
void readAttribute(std::string nom);
void readProvider(std::string nom);
std::list<Sensor> getSensorList();
std::list<Measurement> getMeasurementList();
std::list<Cleaner> getCleanerList();
std::list<User> getUserList();
std::list<Provider> getProviderList();
std::list<Attribute> getAttributeList();

//anciennement dans Statistics
int calculateAirQuality(float latitude, float longitude, int radius, date date);
vector<string> calculateSimilarity(string sensorID, date startDate, date endDate);
bool sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff);

double calculateDistance(Sensor s1, Sensor s2);
vector<Sensor> getNeighbors(Sensor sensor, double radius);
};


#endif // Read_H
