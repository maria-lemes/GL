
#if ! defined ( Read_H )
#define Read_H


#include <vector>
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
vector<Sensor> sensorList;
vector<Measurement> measurementList;
vector<Cleaner> cleanerList;
vector<Provider> providerList;
vector<Attribute> attributeList;
vector<User*> userList;


public:
void readSensor(string nom);
void readMeasurement(string nom);
void readCleaner(string nom);
void readUser(string nom);
void readAttribute(string nom);
void readProvider(string nom);
vector<Sensor> getSensorList();
vector<Measurement> getMeasurementList();
vector<Cleaner> getCleanerList();
vector<User*> getUserList();
vector<Provider> getProviderList();
vector<Attribute> getAttributeList();

//anciennement dans Statistics
int calculateAirQuality(float latitude, float longitude, int radius, date date);
vector<string> calculateSimilarity(string sensorID, date StartDate, date endDate);
bool sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff);

double calculateDistance(Sensor s1, Sensor s2);
vector<Sensor> getNeighbors(Sensor sensor, double radius);
};


#endif // Read_H
