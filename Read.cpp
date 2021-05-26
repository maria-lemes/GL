/*************************************************************************
                              Read -  description
                             -------------------
    début                : 12/2020
    copyright            : (C) 2020 par B.Pluvinet et M.Moutot
    e-mail               : berenice.pluvinet@insa-lyon.fr ; matthieu.moutot@insa-lyon.fr
*************************************************************************/
#include <iostream>
#include <cstring>
#include <fstream>
#include <list>
#include "Read.h"
using namespace std;


void Read :: readSensor(string nom){
    ifstream monFlux;
    monFlux.open(nom.c_str());
    string sensorID;
    string latitude;
    string longitude;
    string inutile;
    std::list <Sensor> sensorList;
    if (monFlux){
        while (monFlux){
            getline(monFlux, sensorID, ';');
            getline(monFlux,latitude, ';');
            getline(monFlux,longitude, ';');
            Sensor * temporary = new  Sensor (sensorID,stod(latitude),stod(longitude));
            sensorList.push_back(*temporary);
         }
    }else {
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
    std:list <Measurement> measurementList;
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
    std::list <Cleaner> cleanerList;
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
        if (monFlux){
            while (monFlux){
                getline(monFlux, userID, ';');
                getline(monFlux,sensorID, ';');
                // a creer une user class
                User  * temporary = new User(userID, sensorID, 0);
                userList.push_back(temporary); 
            }
        }else {
            cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
        }
    }

    void Read :: readProvider(string nom){
        ifstream monFlux(nom.c_str());
        string providerID;
        string cleanerID;
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
        if (monFlux){
            while (monFlux){
                getline(monFlux, attributeID, ';');
                getline(monFlux,unit, ';');
                getline(monFlux,description, ';');
                Attribute *  temporary = new Attribute(attributeID, unit, description);
                attributeList.push_back(temporary); 
            }
        }else {
            cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
        }
    }

    std::list<Sensor> Read::getSensorList(){
        return sensorList;
    }

    
    std::list<Measurement> Read::getMeasurementList(){
        return measurementList;
    }
    
    std::list<Cleaner> Read::getCleanerList(){
        return cleanerList;
    }

    
    std::list<User> Read::getUserList(){
        return userList;
    }

    
    std::list<Provider> Read::getSensorList(){
        return sensorList;
    }
