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
#include <map>
#include <cmath>
#include <limits>
#include <climits>
//#include <bits/stdc++.h>
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

Read :: ~Read () {
  //delete all the elements of the lists
  measurementList.clear();
  cleanerList.clear();
  providerList.clear();
  attributeList.clear();
  privateIndividualList.clear();
}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read::readSensor(){
  ifstream monFlux;
  monFlux.open(sensorPath);
  string sensorID;
  string latitude;
  string longitude;
  string inutile;
  if (monFlux){
    while (monFlux){
      getline(monFlux, sensorID,';');
      getline(monFlux,latitude,';');
      getline(monFlux,longitude,';');
      getline(monFlux,inutile,'\n');
      if (sensorID.length() > 0 && latitude.length() > 0 && longitude.length() > 0)
      {
        Sensor tmp(sensorID,stod(latitude),stod(longitude));
        sensorList.push_back(tmp);
      }
      sensorID.clear(); latitude.clear(); longitude.clear();
    }
  }  else {
    cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
  }
}

/*
This functions is used to read values from a csv file and save them in memory
*/
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
  string inutile;
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
      getline(monFlux,inutile,'\n');

      try {

        if (sensorID.length() == 0 || attribute.length() == 0) {throw exception();}
        int yy = stoi(year);
        int mm = stoi(month);
        int dd = stoi(day);
        int hh = stoi(hour);
        int min = stoi(minute);
        int ss = stoi(second);

        double val = stod(value);

        Date tmpDate(yy, mm, dd, hh, min, ss);
        Measurement tmp(sensorID, attribute, val, tmpDate);
        measurementList.push_back(tmp);

      } catch (const exception &e) {
        //Bad formated line - go to next
        monFlux.ignore();
      }

    }
  } else {
    cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
  }

}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readCleaner(){
  ifstream monFlux(cleanerPath);
  string cleanerID;
  string latitude;
  string longitude;
  string timestart;
  string timestop;
  string inutile;
  if (monFlux){
    while (monFlux){
      getline(monFlux,cleanerID, ';');
      getline(monFlux,latitude, ';');
      getline(monFlux,longitude, ';');
      getline(monFlux,timestart,';');
      getline(monFlux,timestop,';');
      getline(monFlux,inutile,'\n');

      try {
        //Other values' exceptions will be thrown in stoi and stod functions
        if (cleanerID.length() == 0) {throw exception();}

        //Start date
        int sYear = stoi(timestart.substr(0,4));
        int sMonth = stoi(timestart.substr(5,2));
        int sDay = stoi(timestart.substr(8,2));
        int sHour = stoi(timestart.substr(11,2));
        int sMinute = stoi(timestart.substr(14,2));
        int sSecond = stoi(timestart.substr(17,2));
        Date start(sYear, sMonth, sDay, sHour, sMinute, sSecond);

        //End date
        int eYear = stoi(timestop.substr(0,4));
        int eMonth = stoi(timestop.substr(5,2));
        int eDay = stoi(timestop.substr(8,2));
        int eHour = stoi(timestop.substr(11,2));
        int eMinute = stoi(timestop.substr(14,2));
        int eSecond = stoi(timestop.substr(17,2));
        Date stop(eYear, eMonth, eDay, eHour, eMinute, eSecond);

        double lat = stod(latitude);
        double lon = stod(longitude);

        Cleaner tmp(cleanerID,lat,lon,start,stop);
        cleanerList.push_back(tmp);

      } catch (const exception &e) {
        //Bad formated line - go to next
        monFlux.ignore();
      }
    }
  }else {
    cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
  }
}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readUser(){
  ifstream monFlux(userPath);
  string userID;
  string sensorID;
  string inutile;
  if (monFlux){
    while (monFlux){
      getline(monFlux, userID, ';');
      getline(monFlux,sensorID, ';');
      getline(monFlux, inutile,'\n');


      if (userID.length() > 0 && sensorID.length() > 0)
      {
        PrivateIndividual tmp(userID, sensorID, 0);
        privateIndividualList.push_back(tmp);
      }
      else
      {
        monFlux.ignore();
      }
    }
  }else {
    cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
  }
}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readProvider(){
  ifstream monFlux(providerPath);
  string providerID;
  string cleanerID;
  string inutile;
  if (monFlux){
    while (monFlux){
      getline(monFlux, providerID, ';');
      getline(monFlux,cleanerID, ';');
      getline(monFlux, inutile,'\n');

      if (providerID.length() > 0 && cleanerID.length() > 0)
      {
        Provider tmp(providerID, cleanerID);
        providerList.push_back(tmp);
      }
      else {
        //Bad formated line - go to next
        monFlux.ignore();
      }
    }
  }else {
    cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
  }
}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readAttribute(){
  ifstream monFlux(attributesPath);
  string attributeID;
  string unit;
  string description;
  string inutile;
  if (monFlux){
    while (monFlux){
      getline(monFlux, attributeID, ';');
      getline(monFlux,unit, ';');
      getline(monFlux,description, ';');
      getline(monFlux, inutile,'\n');

      if (attributeID.length() > 0 && unit.length() > 0 && description.length() > 0)
      {
        Attribute tmp(attributeID, unit, description);
        attributeList.push_back(tmp);
      } else {
        //Bad formated line - go to next
        monFlux.ignore();
      }
    }
  }else {
    cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
  }
}

/*
This function returns measurements from the sensor whose ID is passed in
parameter. Measurements are read from measurementList in memory.
*/
list<Measurement> Read::getMeasurementsFromSensor(string sensorID) const
{
  list<Measurement> myMeasurements;
  for (Measurement m : measurementList)
  {
    if (m.getSensorID() == ensorID)
    {
      myMeasurements.push_back(m);
    }
  }
  return myMeasurements;
}

/*
Getters
*/
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


//------------------------------------------------------------------------------
/*

*/
void Read::calculateSensorCoefficient(list<Measurement> mySensorMeasurements, double * sums)
{
  for (int i = 0; i < 4; i++) sums[i] = 0.0;

  for (Measurement m : mySensorMeasurements)
  {
    sums[m.getAttribute()] += m.getValue();
  }

  for (int i = 0; i < 4; i++) sums[i] /= mySensorMeasurements.size();
}



//------------------------------------------------------------------------------
list<Sensor> Read::findNeighbors(double lat1, double long1, double radius)
{
  list<Sensor> neighbors; //list of sensors included in the radius provided
  double oneDegree = (M_PI) / 180;

  lat1 *=  oneDegree; //convert to radians
  long1 *= oneDegree;

  double lat2, long2, dlat, dlong;
  double ans = 0; //in km
  for(Sensor it : sensorList){
    lat2 = it.getLatitude() * oneDegree;
    long2 = it.getLongitude() * oneDegree;

    dlat = lat2 - lat1;
    dlong = long2 - long1;

    ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt(ans));
    ans *= 6371; //radius of earth in km
    if(ans <= radius){
      neighbors.push_back(it);
    }
  }
  cout << "#nb of neighbors: " << neighbors.size() << endl;
  return neighbors;
}


//-------Functionality 1 ------------------------------------------------------
int Read::calculateAirQuality(float latitude, float longitude, int radius, Date date)
{
  list<Measurement> measurements;
  list<Sensor> neighbors = findNeighbors(latitude, longitude, radius);


  for(auto itM = measurementList.begin(); itM != measurementList.end(); ++itM)
  {
    if (itM -> getDate() == date)
    {
      for (Sensor s : neighbors)
      {
        if (s.getSensorID().compare(itM -> getSensorID()) == 0)
        {
          measurements.push_back(*itM);
        }
      }
    }
  }


  float sumNO2 = 0.0;
  float sumSO2 = 0.0;
  float sumO3 = 0.0;
  float sumPM10 = 0.0;

  float avgNO2 = 0.0;
  float avgSO2 = 0.0;
  float avgO3 = 0.0;
  float avgPM10 = 0.0;

  for(Measurement m : measurements)
  {
    if(m.getAttribute() == NO2)
    {
      sumNO2 += m.getValue();
    }
    if(m.getAttribute() == SO2)
    {
      sumNO2 += m.getValue();
    }
    if(m.getAttribute() == O3)
    {
      sumNO2 += m.getValue();
    }
    if(m.getAttribute() == PM10)
    {
      sumNO2 += m.getValue();
    }
  }

  avgNO2 = sumNO2 / neighbors.size();
  avgSO2 = sumSO2 / neighbors.size();
  avgO3 = sumO3 / neighbors.size();
  avgPM10 = sumPM10 / neighbors.size();

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
  while(avgSO2 > tabSO2[indexSO2]){
    indexSO2++;
  }
  while(avgO3 > tabO3[indexO3]){
    indexO3++;
  }
  while(avgPM10 > tabPM10[indexPM10]){
    indexPM10++;
  }
  int tab[4] = {indexNO2, indexSO2, indexO3, indexPM10};
  int indexFinal = *(max_element(tab,tab+4));

  return indexFinal;
}



//-------Functionality 2 ------------------------------------------------------

/*TODO:
**Définir si les données des mésures seront recuperées de la base lors
du lancement du programme ou à la demande. On suppose que le vecteur
allMeasurements contient déjà toutes les données.

**Définir si cette mérhode rétournera un vecteur avec les Sensors, ou
un vecteur avec les Ids des Sensors (méthode implementée retourne les ids).

**Définir le format de la date
*/
multimap<double,string> Read::calculateSimilarity(string sensorID, Date startDate, Date endDate)
{
  unordered_map<string,list<Measurement>> otherSensorsMeasurements;
  //Measurements from the sensor whose id is passed in parameter
  list<Measurement> mySensorMeasurements;
  multimap<double, string> similarSensors;

  /*
  We search in all measurements for those produced in the period of time
  passed in parameter. When found, we add it to its sensor measurement vector
  in our measurements map.
  */
  for (Measurement m : measurementList)
  {

    if (m.getDate() >= startDate && m.getDate() <= endDate)
    {
      if (m.getSensorID() == sensorID)
      {
        mySensorMeasurements.push_back(m);
      }
      else
      {
        auto sensor = otherSensorsMeasurements.find(m.getSensorID());

        //Sensor id not in the map yet
        if (sensor == otherSensorsMeasurements.end())
        {
          list<Measurement> mList;
          mList.push_back(m);
          otherSensorsMeasurements.insert(make_pair(m.getSensorID(),mList));
        }
        else //Sensor's id found, add measurement value to its vector
        {
          sensor -> second.push_back(m);
        }
      }
    }
  }

  //Similarity coefficient from the sensor passed in parameter
  double myCoef [4];
  calculateSensorCoefficient(mySensorMeasurements, myCoef);
  double simTolerance = 2.0; //EXAMPLE

  /*
  For each sensor and its measurements included in the specified period of
  time passed in parameter, we calculate its similarity coefficient, if
  it's included in the difined tolerance interval, the sensor is added
  to the similar sensors list.
  */
  for (pair<string,list<Measurement>> m : otherSensorsMeasurements)
  {
    double coef [4];
    calculateSensorCoefficient(m.second,coef);
    double similarity = 0;

    for (int i = 0; i < 4; i++)
    {
      similarity += abs(coef[i] - myCoef[i]);
    }

    similarSensors.insert(make_pair(similarity,m.first));

  }

  return similarSensors;
}


/*bool Read::isInNeighbors(list<Sensor> neighbors, string sensorID){
for(Sensor s : neighbors){
if(s.getSensorID() == sensorID){
return true;
}
}
return false;
}*/

//-------Functionality 3 ------------------------------------------------------
bool Read::sensorSanityCheck(string sensorID, const Date date, float threshold){
  list<Measurement> localMeasurements;
  list<Measurement> timeMeasurements;
  list<Sensor> neighbors;
  //list<string> neighborsID;

  float currentValNO2, currentValSO2, currentValO3, currentValPM10;

  float sumNO2 = 0;
  float sumSO2 = 0;
  float sumO3 = 0;
  float sumPM10 = 0;

  float avgNO2 = 0;
  float avgSO2 = 0;
  float avgO3 = 0;
  float avgPM10 = 0;

  int scoreLocation = 4;
  int scoreTime = 4;

  // ------- LOCATION PART -------

  //get lat and long from sensor
  double lat1, long1;
  for(Sensor s : sensorList){
    if(s.getSensorID() == sensorID){
      lat1 = s.getLatitude();
      long1 = s.getLongitude();
    }
  }

  neighbors = findNeighbors(lat1, long1, 100); //10km arbitraire fichier

  /*for(Sensor s : neighbors){
  neighborsID.push_back(s.getSensorID());
}

for(string s : neighborsID){
cout << s << endl;
}


VERSION 1
//add every measurement that is from the same date & from a neighboring sensor
auto it =  measurementList.begin();
const auto fun = [&](Sensor &s) -> bool {return (s.getSensorID() == it->getSensorID());};
for( ; it != measurementList.end(); ++it)
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
}*/

for(Measurement m : measurementList){
  for(Sensor s : neighbors){
    if( m.getSensorID() == s.getSensorID() && m.getDate() == date){
      localMeasurements.push_back(m);
    }
  }
  if(m.getSensorID() == sensorID && m.getDate() == date){
    if(m.getAttribute() == NO2){
      currentValNO2 = m.getValue();
    }
    if(m.getAttribute() == SO2){
      currentValSO2 = m.getValue();
    }
    if(m.getAttribute() == O3){
      currentValO3 = m.getValue();
    }
    if(m.getAttribute() == PM10){
      currentValPM10 = m.getValue();
    }
  }
}


cout << "--------------------------" << endl;
cout << "currentValNO2: " << currentValNO2 << endl;
cout << "currentValSO2: " << currentValSO2 << endl;
cout << "currentValO3: " << currentValO3 << endl;
cout << "currentValPM10: " << currentValPM10 << endl;

cout << endl;
cout << "nb of measurements in locationM: " << localMeasurements.size() << endl;
cout << "nb of measurements in measurementList: " << measurementList.size() << endl;

//calculate local average for every attribute
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

cout << "avg N02 location: " << avgNO2 << endl;

if(currentValO3 < (1-threshold)*avgO3 || currentValO3 > (1+threshold)*avgO3){
  scoreLocation--;
}
if(currentValNO2 < (1-threshold)*avgNO2 || currentValNO2 > (1+threshold)*avgNO2){
  scoreLocation--;
}
if(currentValSO2 < (1-threshold)*avgSO2 || currentValSO2 > (1+threshold)*avgSO2){
  scoreLocation--;
}
if(currentValPM10 < (1-threshold)*avgPM10 || currentValPM10 > (1+threshold)*avgPM10){
  scoreLocation--;
}
cout << "score location before 1/0: " << scoreLocation << endl;
if(scoreLocation < 4){
  scoreLocation = 0;
}else if(scoreLocation == 4){
  scoreLocation = 1;
}else{
  cout << "pb with scoreLocation" << endl;
}


// ------- TIME PART -------
//create list with all measurements from the sensor up to current date
for(Measurement m : measurementList){
  if(m.getSensorID() == sensorID && m.getDate() <= date){ // toutes les données du sensor importées
    timeMeasurements.push_back(m);
  }
}

cout << endl;
cout << "nb of measurements in timeM: " << timeMeasurements.size() << endl;

sumNO2 = sumSO2 = sumO3 = sumPM10 = 0; //reset sum
avgNO2 = avgSO2 = avgO3 = avgPM10 = 0; //reset avg

for(Measurement m : timeMeasurements){
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
avgNO2 = sumNO2 / (timeMeasurements.size() / 4);
avgSO2 = sumSO2 / (timeMeasurements.size() / 4);
avgO3 = sumO3 / (timeMeasurements.size() / 4);
avgPM10 = sumPM10 / (timeMeasurements.size() / 4);

cout << "sum N02 time: " << sumNO2 << endl;
cout << "avg N02 time: " << avgNO2 << endl;
cout << "limite basse N02 time: " << (1-threshold)*avgNO2 << endl;
cout << "limite haute N02 time: " << (1+threshold)*avgNO2 << endl;

if(currentValO3 < (1-threshold)*avgO3 || currentValO3 > (1+threshold)*avgO3){
  scoreTime--;
}
if(currentValNO2 < (1-threshold)*avgNO2 || currentValNO2 > (1+threshold)*avgNO2){
  scoreTime--;
}
if(currentValSO2 < (1-threshold)*avgSO2 || currentValSO2 > (1+threshold)*avgSO2){
  scoreTime--;
}
if(currentValPM10 < (1-threshold)*avgPM10 || currentValPM10 > (1+threshold)*avgPM10){
  scoreTime--;
}
cout << "score time before 1/0: " << scoreTime << endl;
if(scoreTime < 4){
  scoreTime = 0;
}else if(scoreTime == 4){
  scoreTime = 1;
}else{
  cout << "pb with scoreTime" << endl;
}

cout << endl;
cout << "score location final: " << scoreLocation << endl;
cout << "score time final: " << scoreTime << endl;

return min(scoreLocation, scoreTime);
}
