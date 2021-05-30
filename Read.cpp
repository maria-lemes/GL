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
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <climits>
#include "Read.h"
#include "Date.h"
using namespace std;

//Data paths
const char * sensorPath = "./data/sensors.csv";
const char * measurementPath = "./data/measurements.csv";
const char * cleanerPath = "./data/cleaners.csv";
const char * userPath = "./data/users.csv";
const char * providerPath = "./data/providers.csv";
const char * attributesPath = "./data/attributes.csv";


Read::Read()
{
  readSensor();
  readMeasurement();
  readCleaner();
  readUser();
  readAttribute();
  readProvider();
}

void Read::readSensor(){
  ifstream monFlux;
  monFlux.open(sensorPath);
  string sensorID;
  string latitude;
  string longitude;
  string inutile;
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

void Read :: readMeasurement(){
  ifstream monFlux;
  monFlux.open(measurementPath);
  string year;
  string month;
  string day;
  string hour;
  string minute;
  string second;
  string sensorID;
  string attribute;
  string value;
  if (monFlux){
    while (monFlux){
      getline(monFlux, year,'-');
      getline(monFlux, month,'-');
      getline(monFlux, day,' ');
      getline(monFlux, hour,':');
      getline(monFlux, minute,':');
      getline(monFlux, second,';');
      getline(monFlux, sensorID, ';');
      getline(monFlux, attribute, ';');
      getline(monFlux, value,';');
      //monFlux.ignore();

      try {
        Date * tmp = new Date(stoi(year),stoi(month),stoi(day),stoi(hour),
        stoi(minute), stoi(second));
        cout << *tmp;
        measurementList.push_back(*(new Measurement(sensorID,attribute,
          stod(value), *tmp)));
      } catch (const exception &e) {
          //Bad formated line - go to next
          monFlux.ignore();
      }

      }
    }else {
      cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
    }

  }

  void Read :: readCleaner(){
    ifstream monFlux(cleanerPath);
    string cleanerID;
    string latitude;
    string longitude;
    string timestart;
    string timestop;
    Date start;
    Date stop;
    if (monFlux){
      while (monFlux){
        getline(monFlux, cleanerID, ';');
        getline(monFlux,latitude, ';');
        getline(monFlux,longitude, ';');
        getline(monFlux,timestart,';');
        getline(monFlux,timestop,';');

        try {
          start = *(new Date(stoi(timestart.substr(0,4)),stoi(timestart.substr(5,2)),
          stoi(timestart.substr(8,2)),stoi(timestart.substr(11,2)),
          stoi(timestart.substr(14,2)),stoi(timestart.substr(16,2))));

          stop = *(new Date(stoi(timestop.substr(0,4)),stoi(timestop.substr(5,2)),
          stoi(timestop.substr(8,2)),stoi(timestop.substr(11,2)),
          stoi(timestop.substr(14,2)),stoi(timestop.substr(16,2))));

          Cleaner * temporary = new Cleaner (cleanerID, stod(latitude), stod(longitude), start,stop);
          cleanerList.push_back(*temporary);
        } catch (const exception &e) {
            //Bad formated line - go to next
            monFlux.ignore();
        }
      }
    }else {
      cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
    }
  }

  void Read :: readUser(){
    ifstream monFlux(userPath);
    string userID;
    string sensorID;
    int pointsAwarded;
    list <PrivateIndividual> privateIndividualList = getPrivateIndividualList();
    if (monFlux){
      while (monFlux){
        getline(monFlux, userID, ';');
        getline(monFlux,sensorID, ';');

        try {
          PrivateIndividual * temporary = new PrivateIndividual(userID, sensorID, 0);
          privateIndividualList.push_back(*temporary);
        }
        catch (const exception &e) {
            //Bad formated line - go to next
            monFlux.ignore();
        }
      }
    }else {
      cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
  }

  void Read :: readProvider(){
    ifstream monFlux(providerPath);
    string providerID;
    string cleanerID;
    if (monFlux){
      while (monFlux){
        getline(monFlux, providerID, ';');
        getline(monFlux,cleanerID, ';');
        try {
          Provider * temporary = new Provider(providerID, cleanerID);
          providerList.push_back(*temporary);
        }
        catch (const exception &e) {
            //Bad formated line - go to next
            monFlux.ignore();
        }
      }
    }else {
      cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
  }

  void Read :: readAttribute(){
    ifstream monFlux(attributesPath);
    string attributeID;
    string unit;
    string description;
    if (monFlux){
      while (monFlux){
        getline(monFlux, attributeID, ';');
        getline(monFlux,unit, ';');
        getline(monFlux,description, ';');
        try {
          Attribute *  temporary = new Attribute(attributeID, unit, description);
          attributeList.push_back(*temporary);
        }
        catch (const exception &e) {
            //Bad formated line - go to next
            monFlux.ignore();
        }

      }
    }else {
      cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
    }
  }

  list<Measurement> Read::getMeasurementsFromSensor(string sensorID) const
  {
    list<Measurement> myMeasurements;

    for (Measurement m : measurementList)
    {
      if (m.getSensorID()==sensorID)
      {
        myMeasurements.push_back(m);
      }
    }

    return myMeasurements;
  }

  list<Sensor> Read::getSensorList() const{
    return sensorList;
  }

  list <Provider> Read:: getProviderList() const {
    return providerList;
  }


  list<Measurement> Read::getMeasurementList() const{
    return measurementList;
  }

  list<Cleaner> Read::getCleanerList() const{
    return cleanerList;
  }

  list<Attribute> Read::getAttributeList() const{
    return attributeList;
  }

  list<PrivateIndividual> Read ::getPrivateIndividualList() const{
    return privateIndividualList;
  }


  // --------------------ancien statistics


  int Read::calculateAirQuality(float latitude, float longitude, int radius, Date date)
  {
    list<Measurement> measurements;
    list<Sensor> sensors;

    if(sensors.empty())
    {
      for(auto it = getSensorList().begin(); it != getSensorList().end(); it++)
      {
        if( (it->getLatitude() < latitude+radius) && (it->getLongitude() < longitude+radius) )
        {
          sensors.push_back(*it);
        }
      }
    }

    //Lambda to use in find_if
    auto it = getMeasurementList().begin();
    const auto fun = [&](Sensor &s) -> bool {return (s.getSensorID() == it->getSensorID());};
    if(measurements.empty())
    {
      for(; it != getMeasurementList().end(); it++)
      {
        if((find_if(sensors.begin(), sensors.end(), fun) != sensors.end()) && (it->getDate() == date))
        {
          measurements.push_back(*it);
        }
      }
    }

    float sumNO2, sumSO2, sumO3, sumPM10;
    float avgNO2, avgSO2, avgO3, avgPM10;
    int nb = sensors.size();

    for(auto it = measurements.begin(); it != measurements.end(); it++)
    {
      if(it->getAttribute() == NO2)
      {
        sumNO2 += it->getValue();
      }
      if(it->getAttribute() == SO2)
      {
        sumSO2 += it->getValue();
      }
      if(it->getAttribute() == O3)
      {
        sumO3 += it->getValue();
      }
      if(it->getAttribute() == PM10)
      {
        sumPM10 += it->getValue();
      }
    }

    avgNO2 = sumNO2 / nb;
    avgSO2 = sumSO2 / nb;
    avgO3 = sumO3 / nb;
    avgPM10 = sumPM10 / nb;

    int tabSO2 [10] = {40, 80, 120, 160, 200, 250, 300, 400, 500, INT_MAX};
    int tabNO2 [10] = {30, 55, 85, 110, 135, 165, 200, 275, 400, INT_MAX};
    int tabO3 [10]  = {30, 55, 80, 105, 130, 150, 180, 210, 240, INT_MAX};
    int tabPM10 [10]= {7, 14, 21, 28, 35, 42, 50, 65, 80, INT_MAX};

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
    while(avgO3 > tabNO2[indexO3]){
      indexO3++;
    }
    while(avgPM10 > tabPM10[indexPM10]){
      indexPM10++;
    }
    int tab[4] = {indexNO2, indexSO2, indexO3, indexPM10};
    int indexFinal = *(max_element(tab,tab+4));

    return indexFinal;
  }

  int Read::calculateSensorCoefficient(list<double> mySensorMeasurements)
  {
    return 0;
  }

  list<Sensor> Read::findNeighbors(string sensorID, int radius)
  {
    list<Sensor> neighbors;
    return neighbors;
  }

  /*TODO:
  **Définir si les données des mésures seront recuperées de la base lors
  du lancement du programme ou à la demande. On suppose que le vecteur
  allMeasurements contient déjà toutes les données.

  **Définir si cette mérhode rétournera un vecteur avec les Sensors, ou
  un vecteur avec les Ids des Sensors (méthode implementée retourne les ids).

  **Définir le format de la date
  */
  list<string> Read::calculateSimilarity(string sensorID, Date startDate, Date endDate)
  {

    list<Measurement> allMeasurements = getMeasurementList();

    //Key : SensorID. Value : Sensor's measurements in the specified period list
    unordered_map<string,list<double>> otherSensorsMeasurements;

    //Measurements from the sensor whose id is passed in parameter
    list<double> mySensorMeasurements;

    list<string> similarSensors;

    /*
    We search in all measurements for those produced in the period of time
    passed in parameter. When found, we add it to its sensor measurement vector
    in our measurements map.
    */

    for (Measurement m : allMeasurements)
    {

      if (m.getDate()>=startDate && m.getDate() <= endDate)
      {
        if (m.getSensorID() == sensorID)
        {
          mySensorMeasurements.push_back(m.getValue());
        }
        else
        {
          auto sensor = otherSensorsMeasurements.find(m.getSensorID());

          //Sensor id not in the map yet
          if (sensor == otherSensorsMeasurements.end())
          {
            list<double> mList;
            mList.push_back(m.getValue());
            otherSensorsMeasurements.insert(make_pair(m.getSensorID(),mList));
          }
          else //Sensor's id found, add measurement value to its vector
          {
            sensor -> second.push_back(m.getValue());
          }
        }
      }
    }

    //Similarity coefficient from the sensor passed in parameter
    double mySensorCoef = calculateSensorCoefficient(mySensorMeasurements);
    double simTolerance = 3; //EXAMPLE

    /*
    For each sensor and its measurements included in the specified period of
    time passed in parameter, we calculate its similarity coefficient, if
    it's included in the difined tolerance interval, the sensor is added
    to the similar sensors list.
    */
    for (pair<string,list<double>> m : otherSensorsMeasurements)
    {
      int coef = calculateSensorCoefficient(m.second);

      //Verify if sensors are similar
      if (abs(mySensorCoef - coef) <= simTolerance)
      {
        //Push similar sensor's id to the list
        similarSensors.push_back(m.first);
      }
    }
    return similarSensors;
  }

  bool Read::sensorSanityCheck(string sensorID, Date date, int threshold, int nbDays, int coeff){
    list<Measurement> localMeasurements;
    list<Measurement> timeMeasurements;
    list<Sensor> neighbors;

    float currentValNO2, currentValSO2, currentValO3, currentValPM10;
    float scoreLocation, scoreTime;

    neighbors = findNeighbors(sensorID, 5); //5km arbitraire fichier

    //add every measurement that is from the same date & from a neighboring sensor
    //Lambda to use in find_if
    auto it =  measurementList.begin();
    const auto fun = [&](Sensor &s) -> bool {return (s.getSensorID() == it->getSensorID());};
    for(; it != measurementList.end(); ++it)
    {
      if((find_if(neighbors.begin(), neighbors.end(), fun) != neighbors.end()) && (it -> getDate() == date))
      {
        localMeasurements.push_back(*it);
      }
      // get the current values of the suspicious sensor
      if(it -> getSensorID() == sensorID && it -> getDate() == date){
        if(it -> getAttribute() == NO2){
          currentValNO2 = it -> getValue();
        }
        if(it -> getAttribute() == SO2){
          currentValSO2 = it -> getValue();
        }
        if(it -> getAttribute() == O3){
          currentValO3 = it -> getValue();
        }
        if(it -> getAttribute() == PM10){
          currentValPM10 = it -> getValue();
        }
      }
    }

    float sumNO2 = 0, sumSO2 = 0, sumO3 = 0, sumPM10 = 0;
    float avgNO2 = 0, avgSO2 = 0, avgO3 = 0, avgPM10 = 0;

    for(Measurement m : localMeasurements){
      switch (m.getAttribute()) {
        case NO2:
        sumNO2 += m.getValue();
        break;
        case SO2:
        sumSO2 += m.getValue();
        break;
        case O3:
        sumO3 += m.getValue();
        break;
        case PM10:
        sumPM10 += m.getValue();
        break;
      }
    }
    avgNO2 = sumNO2 / neighbors.size();
    avgSO2 = sumSO2 / neighbors.size();
    avgO3 = sumO3 / neighbors.size();
    avgPM10 = sumPM10 / neighbors.size();

    // trouver system qui aille bien pour le score

  }
