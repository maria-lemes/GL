/*************************************************************************
                              Read.cpp -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) 2021
    e-mail               : matthieu.moutot@insa-lyon.fr ;
    gustavo.giunco-bertoldi@insa-lyon.fr ;
*************************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include "Read.h"
using namespace std;


void Read::readSensor(string nom){
    ifstream monFlux;
    monFlux.open(nom.c_str());
    string sensorID;
    string latitude;
    string longitude;
    string inutile;
    list <Sensor> sensorList = getSensorList();
    if (monFlux){
        while (monFlux){
            getline(monFlux, sensorID, ';');
            getline(monFlux,latitude, ';');
            getline(monFlux,longitude, ';');
            Sensor *  temporary = new Sensor (sensorID,stod(latitude),stod(longitude));
            sensorList.push_back(*temporary);
         }
    }  else {
        cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
    }
}

void Read :: readMeasurement(string nom){
    ifstream monFlux(nom.c_str());
    string timestamp;
    date date;
    string sensorID;
    string attribute;
    string value;
    list <Measurement> measurementList = getMeasurementList();
    if (monFlux){
        while (monFlux){
            getline(monFlux, timestamp, ';');
            getline(monFlux,sensorID, ';');
            getline(monFlux,attribute, ';');
            getline(monFlux,value,';');
            date.year = stoi(timestamp.substr(0,4));
            date.month = stoi(timestamp.substr(5,2));
            date.day = stoi(timestamp.substr(8,2));
            date.hour = stoi(timestamp.substr(11,2));
            date.minute = stoi(timestamp.substr(14,2));
            date.second = stoi(timestamp.substr(16,2));
            Measurement * temporary = new Measurement (sensorID, attribute, stod(value), date);
            measurementList.push_back(*temporary);
         }
    }else {
        cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
    }

}

void Read :: readCleaner(string nom){
    ifstream monFlux(nom.c_str());
    string cleanerID;
    string latitude;
    string longitude;
    string timestart;
    string timestop;
    date start;
    date stop;
    list <Cleaner> cleanerList = getCleanerList();
    if (monFlux){
        while (monFlux){
            getline(monFlux, cleanerID, ';');
            getline(monFlux,latitude, ';');
            getline(monFlux,longitude, ';');
            getline(monFlux,timestart,';');
            getline(monFlux,timestop,';');
            start.year = stoi(timestart.substr(0,4));
            start.month = stoi(timestart.substr(5,2));
            start.day = stoi(timestart.substr(8,2));
            start.hour = stoi(timestart.substr(11,2));
            start.minute = stoi(timestart.substr(14,2));
            start.second = stoi(timestart.substr(16,2));

            stop.year = stoi(timestop.substr(0,4));
            stop.month = stoi(timestop.substr(5,2));
            stop.day = stoi(timestop.substr(8,2));
            stop.hour = stoi(timestop.substr(11,2));
            stop.minute = stoi(timestop.substr(14,2));
            stop.second = stoi(timestop.substr(16,2));
            Cleaner * temporary = new Cleaner (cleanerID, stod(latitude), stod(longitude), start,stop);
            cleanerList.push_back(*temporary);
         }
    }else {
        cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
    }
}

    void Read :: readUser(string nom){
        ifstream monFlux(nom.c_str());
        string userID;
        string sensorID;
        int pointsAwarded;
        list <PrivateIndividual> privateIndividualList = getPrivateIndividualList();
        if (monFlux){
            while (monFlux){
                getline(monFlux, userID, ';');
                getline(monFlux,sensorID, ';');
                // a creer une user class
                PrivateIndividual * temporary = new PrivateIndividual(userID, sensorID, 0);
                privateIndividualList.push_back(*temporary);
            }
        }else {
            cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
        }
    }

    void Read :: readProvider(string nom){
        ifstream monFlux(nom.c_str());
        string providerID;
        string cleanerID;
        list <Provider> providerList = getProviderList();
        if (monFlux){
            while (monFlux){
                getline(monFlux, providerID, ';');
                getline(monFlux,cleanerID, ';');
                Provider * temporary = new Provider(providerID, cleanerID);
                providerList.push_back(*temporary);
            }
        }else {
            cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
        }
    }

    void Read :: readAttribute(string nom){
        ifstream monFlux(nom.c_str());
        string attributeID;
        string unit;
        string description;
        list <Attribute> attributeList = getAttributeList();
        if (monFlux){
            while (monFlux){
                getline(monFlux, attributeID, ';');
                getline(monFlux,unit, ';');
                getline(monFlux,description, ';');
                Attribute *  temporary = new Attribute(attributeID, unit, description);
                attributeList.push_back(*temporary);
            }
        }else {
            cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
        }
    }

    list<Sensor> Read::getSensorList(){
        return sensorList;
    }


    list<Measurement> Read::getMeasurementList(){
        return measurementList;
    }

    list<Cleaner> Read::getCleanerList(){
        return cleanerList;
    }


    list<PrivateIndividual> Read::getPrivateIndividualList(){
        return privateIndividualList;
    }

    list<Provider> Read::getProviderList(){
        return providerList;
    }

    list<Sensor> Read::getSensorList(){
        return sensorList;
    }


    list<Attribute> Read::getAttributeList(){
        return attributeList;
    }   

// --------------------ancien statistics


int Read::calculateAirQuality(float latitude, float longitude, int radius, date date)
{
    vector<Measurement> measurements;
    vector<Sensor> sensors;

    if(sensors.empty())
    {
        for(auto it = Read::getSensorList().begin(); it != Read::getSensorList().end(); it++)
        {
            if( (it->getLatitude() < latitude+radius) && (it->getLongitude() < longitude+radius) )
            {
                sensors.push_back(*it);
            }
        }
    }

    if(measurements.empty())
    {
        for(auto it = Read::getMeasurementList().begin(); it != getMeasurementList().end(); it++)
        {
            if((find(sensors.begin(), sensors.end(), it.getSensorID()) != sensors.end()) && (it.getDate() == date))
            {
                measurements.push_back(*it);
            }
        }
    }

    float sumNO2, sumSO2, sum03, sumPM10;
    float avgNO2, avgSO2, avg03, avgPM10;
    nb = sensors.size();

    for(auto it = measurements.begin(); it != measurements.end(); it++)x
    {
        if(it.getAttribute().compare("NO2") == 0)
        {
            sumNO2 += it->value;
        }
        if(it.getAttribute().compare("SO2") == 0)
        {
            sumNO2 += it->value;
        }
        if(it.getAttribute().compare("O3") == 0)
        {
            sumNO2 += it->value;
        }
        if(it.getAttribute().compare("PM10") == 0)
        {
            sumNO2 += it->value;
        }
    }

    avgNO2 = sumNO2 / nb;
    avgSO2 = sumSO2 / nb;
    avg03 = sumO3 / nb;
    avgPM10 = sumPM10 / nb;

    int [10] tabSO2 = {40, 80, 120, 160, 200, 250, 300, 400, 500, INT_MAX};
    int [10] tabNO2 = {30, 55, 85, 110, 135, 165, 200, 275, 400, INT_MAX};
    int [10] tabO3 = {30, 55, 80, 105, 130, 150, 180, 210, 240, INT_MAX};
    int [10] tabPM10 = {7, 14, 21, 28, 35, 42, 50, 65, 80, INT_MAX};

    int indexNO2 = 0;
    int indexSO2 = 0;
    int indexO3 = 0;
    int indexPM10 = 0;

    while(avgNO2 > tabNO2[indexNO2]){
        indexNO2++;
    }
    while(avgSO2 > tabNO2[indexSO2]){
        indexSO2++;
    }
    while(avg03 > tabNO2[index03]){
        index03++;
    }
    while(avgPM10 > tabPM10[indexPM10]){
        indexPM10++;
    }
    int tab[4] = {indexNO2, indexSO2, index03, indexPM10};
    int indexFinal = max_element(tab, tab+4);

    return(indexFinal);
}

/*TODO:
**Définir si les données des mésures seront recuperées de la base lors
du lancement du programme ou à la demande. On suppose que le vecteur
allMeasurements contient déjà toutes les données.

**Définir si cette mérhode rétournera un vecteur avec les Sensors, ou
un vecteur avec les Ids des Sensors (méthode implementée retourne les ids).

**Définir le format de la date
*/
vector<string> Read::calculateSimilarity(string sensorID, date startDate, date endDate)
{

  vector<Measurement> allMeasurements;
  //Key : SensorID. Value : Sensor's measurements in the specified period list
  unordered_map<string,vector<double>> otherSensorsMeasurements;
  //Measurements from the sensor whose id is passed in parameter
  vector<double> mySensorMeasurements;
  vector<string> similarSensors;

  /*
  We search in all measurements for those produced in the period of time
  passed in parameter. When found, we add it to its sensor measurement vector
  in our measurements map.
  */
  for (Measurement m : allMeasurements)
  {
    if (m.getDate() >= startDate && m.getDate() <= endDate)
    {
      //Sensor is the one passed in parameter
      if (m.getSensorId() == sensorID)
      {
        mySensorMeasurements.push_back(m.getValue());
      }
      else
      {
        auto sensor = otherSensorsMeasurements.find(m.getSensorId());

        //Sensor id not in the map yet
        if (sensor == measurement.end())
        {
          vector<double> mvec;
          mvec.push_back(m.getValue());
          otherSensorsMeasurements.insert(make_pair(m.getSensorId(),mvec));
        }
        else //Sensor's id found, add measurement value to its vector
        {
          (*sensor).second.push_back(m.getValue());
        }
      }
    }
  }

  //Similarity coefficient from the sensor passed in parameter
  double simCoef = calculateSensorCoefficient(mySensorMeasurements);
  double simTolerance = 3; //EXAMPLE

  /*
  For each sensor and its measurements included in the specified period of
  time passed in parameter, we calculate its similarity coefficient, if
  it's included in the difined tolerance interval, the sensor is added
  to the similar sensors list.
  */
  for (pair<string,vector<double>> m : otherSensorsMeasurements)
  {
    coef = calculateSensorCoefficient(m.second);

    //Verify if sensors are similar
    if (abs(simCoef - coef) <= simTolerance)
    {
      //Push of the similar sensor id to the list
      similarSensors.push_back(m.first);
    }
  }
  return similarSensors;
}

bool Read::sensorSanityCheck(Sensor sensor, date date, int threshold, int nbDays, int coeff){
    List<Measurement> localMeasurements;
    List<Measurement> timeMeasurements;
    List<Sensors> neighbors;

    float currentValNO2, currentValSPO2, currentValO3, currentValPM10;
    float scoreLocation, scoreTime;

    neighbors = findNeighbors(s, 5); //5km arbitraire fichier

    //add every measurement that is from the same date & from a neighboring sensor
    for(auto it = Read::getMeasurementsList().begin(); it != getMeasurementsList().end(); it++)
    {
        if((find(neighbors.begin(), neighbors.end(), it.getSensorID()) != neighbors.end()) && (it.getDate() == date))
        {
            localMeasurements.push_back(*it);
        }
        // get the current values of the suspicious sensor
        if(it.getSensorID() == sensor.getSensorID() && it.getDate() == date){
            if(it.getAttribute() == NO2){
                currentValNO2 == it.getValue();
            }
            if(it.getAttribute() == SO2){
                currentValSO2 == it.getValue();
            }
            if(it.getAttribute() == O3){
                currentValO3 == it.getValue();
            }
            if(it.getAttribute() == PM10){
                currentValPM10 == it.getValue();
            }
        }
    }

    float sumNO2 = sumSO2 = sumO3 = sumPM10 = 0;
    float avgNO2 = avgSO2 = avgO3 = avgPM10 = 0;

    for(Measurement m : localMeasurements){
        switch (m.getAttribute()) {
            case NO2: sumNO2 += m.getValue();
                break;
            case SO2: sumSO2 += m.getValue();
                break;
            case O3: sumO3 += m.getValue();
                break;
            case PM10: sumPM10 += m.getValue();
                break;
        }
    }
    avgNO2 = sumNO2 / neighbors.length();
    avgSO2 = sumSO2 / neighbors.length();
    avgO3 = sumO3 / neighbors.length();
    avgPM10 = sumPM10 / neighbors.length();

    // trouver system qui aille bien pour le score 

    }




}
