/*************************************************************************
Read.cpp -  description
-------------------
début                : 05/2021
copyright            : (C) 2021
e-mail               : matthieu.moutot@insa-lyon.fr ;
gustavo.giunco-bertoldi@insa-lyon.fr ;
maria.zenlemes@insa-lyon.fr
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


Read::Read(const char * sensorPath, const char * measurementPath, const char * cleanerPath, const char * userPath, const char * providerPath, const char * attributesPath)
{
  readSensor(sensorPath);
  readMeasurement(measurementPath);
  readCleaner(cleanerPath);
  readUser(userPath);
  readAttribute(providerPath);
  readProvider(attributesPath);
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
void Read::readSensor(string nom){
  ifstream monFlux;
  monFlux.open(nom);
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
    cout << "Error: File could not be opened" << endl;
  }

}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readMeasurement(string nom){
  ifstream monFlux;
  monFlux.open(nom);
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
    cout << "Error: File could not be opened" << endl;
  }

}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readCleaner(string nom){
  ifstream monFlux(nom);
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
    cout << "Error: File could not be opened" << endl;
  }
}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readUser(string nom){
  ifstream monFlux(nom);
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
    cout << "Error: File could not be opened" << endl;
  }
}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readProvider(string nom){
  ifstream monFlux(nom);
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
    cout << "Error: File could not be opened" << endl;
  }
}

/*
This functions is used to read values from a csv file and save them in memory
*/
void Read :: readAttribute(string nom){
  ifstream monFlux(nom);
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
    cout << "Error: File could not be opened" << endl;
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
    if (m.getSensorID() == sensorID)
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

list<PrivateIndividual> Read::getPrivateIndividualList() const{
  return privateIndividualList;
}

Sensor * Read::getSensorFromId(string sensorId) const
{
  for (const Sensor &s : sensorList)
  {
    if (s.getSensorID() == sensorId)
    {
      return new Sensor(s);
    }
  }
  return nullptr;
}


//------------------------------------------------------------------------------
/*

*/
void Read::calculateSensorCoefficient(const list<Measurement> &mySensorMeasurements, double * sums) const
{
  for (int i = 0; i < 4; i++) sums[i] = 0.0;

  for (const Measurement &m : mySensorMeasurements)
  {
    sums[m.getAttribute()] += m.getValue();
  }

  for (int i = 0; i < 4; i++) sums[i] /= mySensorMeasurements.size();
}






//------------------------------------------------------------------------------
list<Sensor> Read::findNeighbors(double lat1, double long1, double radius) const
{

  list<Sensor> neighbors; //list of sensors included in the radius provided
  double oneDegree = (M_PI) / 180;
  double R = 6372.795477598;

  lat1 *=  oneDegree; //convert to radians
  long1 *= oneDegree;

  double lat2, long2;
  double ans = 0; //in km
  for(const Sensor &it : sensorList){
    lat2 = it.getLatitude() * oneDegree;
    long2 = it.getLongitude() * oneDegree;
    //ans = R * acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(long1-long2));
    float latSin = sin ((lat2 - lat1)/2);
    float lonSin = sin ((long2 - long1)/2);

    //ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt((latSin*latSin) + cos(lat1)*cos(lat2)*(lonSin*lonSin)));
    ans *= R; //radius of earth in km*/
    // this enables us to keep our sensor when the radius is at 0 (else it will tell us that there are no neighbouring sensors due to a bad approximation)
    if (ans < 0.1){
      ans = 0;
    }
    if(ans <= radius){
      neighbors.push_back(it);
    }
  }
  cout << "#nb of neighbors: " << neighbors.size() << endl;
  return neighbors;
}


//-------Functionality 1 ------------------------------------------------------
int Read::calculateAirQuality(double latitude, double longitude, double radius, Date date, Date endDate, int timeOption)
{
  list<Measurement> measurements;
  list<Sensor> neighbors = findNeighbors(latitude, longitude, radius);

  if(neighbors.empty()){
        return 10;
  }

  for (const Sensor &s : neighbors ){
    for (const Measurement &m : measurementList)
    {
      if(timeOption == 1){
        if(s.getSensorID() == m.getSensorID() && (m.getDate() == date)){
          measurements.push_back(m);
        }
      } else if(timeOption == 2)
      {
          if(s.getSensorID() == m.getSensorID() && (m.getDate() <= date) && (m.getDate() >= endDate)){
            measurements.push_back(m);
          }
      }
    }
  }


  double sumNO2 = 0.0;
  double sumSO2 = 0.0;
  double sumO3 = 0.0;
  double sumPM10 = 0.0;

  double avgNO2 = 0.0;
  double avgSO2 = 0.0;
  double avgO3 = 0.0;
  double avgPM10 = 0.0;

  for(const Measurement &m : measurements)
  {
    switch (m.getAttribute())
    {
      case NO2 :
        sumNO2 += m.getValue();
        break;
      case SO2 :
        sumSO2 += m.getValue();
        break;
      case O3 :
        sumO3 += m.getValue();
        break;
      case PM10 :
        sumPM10 += m.getValue();
        break;
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
multimap<double,pair<string,pair<double,double>>>& Read::calculateSimilarity(const string& sensorID, const Date& startDate, const Date& endDate) const
{
  unordered_map<string,list<Measurement>> otherSensorsMeasurements;
  //Measurements from the sensor whose id is passed in parameter
  list<Measurement> mySensorMeasurements;

  //Map contains similarity coef as key, and sensorId and coordinates as value
  multimap<double,pair<string,pair<double,double>>> * similarSensors = new multimap<double,pair<string,pair<double,double>>>();

  /*
  We search in all measurements for those produced in the period of time
  passed in parameter. When found, we add it to its sensor measurement vector
  in our measurements map.
  */
  for (const Measurement &m : measurementList)
  {

    if (m.getDate() >= startDate && m.getDate() <= endDate)
    {
      if (m.getSensorID() == sensorID)
      {
        mySensorMeasurements.push_back(m);
      }
      else
      {
        auto sensorIt = otherSensorsMeasurements.find(m.getSensorID());

        //Sensor id not in the map yet
        if (sensorIt == otherSensorsMeasurements.end())
        {
          list<Measurement> mList;
          mList.push_back(m);
          otherSensorsMeasurements.insert(make_pair(m.getSensorID(),mList));
        }
        else //Sensor's id found, add measurement value to its vector
        {
          sensorIt -> second.push_back(m);
        }
      }
    }
  }

  //Similarity coefficient from the sensor passed in parameter
  double myCoef [4];
  calculateSensorCoefficient(mySensorMeasurements, myCoef);

  /*
  For each sensor and its measurements included in the specified period of
  time passed in parameter, we calculate its similarity coefficient, if
  it's included in the difined tolerance interval, the sensor is added
  to the similar sensors list.
  */
  for (const auto &m : otherSensorsMeasurements)
  {
    double coef [4];
    calculateSensorCoefficient(m.second,coef);
    double similarity = 0;

    for (int i = 0; i < 4; i++)
    {
      similarity += abs(coef[i] - myCoef[i]);
    }

    Sensor * s = getSensorFromId(m.first);
    pair<double,double> coordinates(s -> getLatitude(), s -> getLongitude());
    pair<string,pair<double,double>> sensorData(s -> getSensorID(),coordinates);
    similarSensors -> insert(make_pair(similarity,sensorData));
    s -> ~Sensor();

  }

  return *similarSensors;
}


//-------Functionality 3: Check data validity-----------------------------------
bool Read::sensorSanityCheck(string sensorID, const Date date, int radius, float threshold){

  list<Measurement> localMeasurements;
  list<Measurement> timeMeasurements;
  list<Sensor> neighbors;

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

  // ------- LOCATION PART --------------------------------------------------------------------------------------------------

  //get lat and long from suspicious sensor
  double lat1, long1;
  for(Sensor s : sensorList){
    if(s.getSensorID() == sensorID){
      lat1 = s.getLatitude();
      long1 = s.getLongitude();
    }
  }

  neighbors = findNeighbors(lat1, long1, radius); //10km arbitraire fichier
  for(Sensor n : neighbors){
      cout << n.getSensorID() << endl;
  }

  auto it =  measurementList.begin();
  const auto fun = [&](Sensor &s) -> bool {return (s.getSensorID() == it->getSensorID());};
  for( ; it != measurementList.end(); ++it)
  {
    //add every measurement from a neighboring sensor at the same date
    if((find_if(neighbors.begin(), neighbors.end(), fun) != neighbors.end()) && (it -> getDate() == date))
    {
      localMeasurements.push_back(*it);
    }
    //get the current values of the suspicious sensor
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

  cout << "-------CurrentValues--------------" << endl;
  cout << "currentValNO2: " << currentValNO2 << endl;
  cout << "currentValSO2: " << currentValSO2 << endl;
  cout << "currentValO3: " << currentValO3 << endl;
  cout << "currentValPM10: " << currentValPM10 << endl;

  //calculate local average for every attribute
  for(const Measurement &m : localMeasurements){
      if(m.getSensorID() != sensorID){
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
  }
  avgNO2 = sumNO2 / ((localMeasurements.size()-1) / 4);
  avgSO2 = sumSO2 / ((localMeasurements.size()-1) / 4);
  avgO3 = sumO3 / ((localMeasurements.size()-1) / 4);
  avgPM10 = sumPM10 / ((localMeasurements.size()-1) / 4);

  //if current value not in the interval, score decreased
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

  cout << "--------ToString localMeasurements-------" << endl;

  for(Measurement m : localMeasurements){
     cout << m.getSensorID() << "; " << m.getAttribute() << "; " << m.getValue() << "; " << endl;
  }


  cout << "-------LOCATION-------------------" << endl;
  cout << "nb of measurements in locationM: " << localMeasurements.size() << endl;
  cout << "sum N02 location: " << sumNO2 << endl;
  cout << "avg N02 location: " << avgNO2 << endl;
  cout << "limite basse N02 loc: " << (1-threshold)*avgNO2 << endl;
  cout << "limite haute N02 loc: " << (1+threshold)*avgNO2 << endl;
  cout << "score location before 1/0: " << scoreLocation << endl;

  if(scoreLocation < 4){
    scoreLocation = 0;
  }else if(scoreLocation == 4){
    scoreLocation = 1;
  }else{
    cout << "Problem detected in scoreLocation" << endl;
  }


  // ------- TIME PART ----------------------------------------------------------------------------------------------------------

  //create list with all measurements from the sensor up to current date
  for(const Measurement &m : measurementList){
    if(m.getSensorID() == sensorID && m.getDate() <= date){ // toutes les données du sensor importées
      timeMeasurements.push_back(m);
    }
  }

  sumNO2 = sumSO2 = sumO3 = sumPM10 = 0; //reset sum
  avgNO2 = avgSO2 = avgO3 = avgPM10 = 0; //reset avg

  for(const Measurement &m : timeMeasurements){
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


  cout << "-------TIME-------------------" << endl;
  cout << "nb of measurements in timeM: " << timeMeasurements.size() << endl;
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
    cout << "Problem detected with scoreTime" << endl;
  }


  cout << "-------FINAL---------------------" << endl;
  cout << "score location final: " << scoreLocation << endl;
  cout << "score time final: " << scoreTime << endl;

  return min(scoreLocation, scoreTime);
}
