
#if ! defined ( Read_H )
#define Read_H

#include <list>
#include <string>
#include "Attribute.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "PrivateIndividual.h"
#include "Provider.h"
#include "Sensor.h"
#include "Statistics.h"
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
int calculateAirQuality(float latitude, float longitude, int radius, Date date);
vector<string> calculateSimilarity(String sensorID, Date date);
bool sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff);

};


#endif // Read_H
