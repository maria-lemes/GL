/*************************************************************************
                              Read.h -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ; mettez vos emails
*************************************************************************/

#if ! defined ( Read_H )
#define Read_H
#include <list>
#include <string> 


class Read
{

private:
/*std::list <Sensors> sensorList;
std::list <Measurements> measurementList;
std::list <Cleaner> cleanerList;
std::list <Provider> providerList;
std::list <Attributes> attributeList;
std::list <Attributes> userList;
*/

public:
void readSensor(std::string nom);
void readMeasurement(std::string nom);
void readCleaner(std::string nom);
void readUser(std::string nom);
void readAttribute(std::string nom);
void readProvider(std::string nom);
List<Sensor> getSensorList();
List<Measurements> getMeasurementList();
List<Cleaner> getCleanerList();
List<User> getUserList();
List <Provider> getProviderList();
List <Attributes> getAttributesList();


};


#endif // Read_H
