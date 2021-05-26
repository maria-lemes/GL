/*************************************************************************
                              Read -  description
                             -------------------
    début                : 12/2020
    copyright            : (C) 2020 par B.Pluvinet et M.Moutot
    e-mail               : berenice.pluvinet@insa-lyon.fr ; matthieu.moutot@insa-lyon.fr
*************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

class Read {
void Read :: readSensor(string nom){
    ifstream monFlux(nom.c_str());
    string sensorID;
    string latitude;
    string longitude;
    string inutile;
    if (monFlux){
        while (monFlux){
            getline(monFlux, sensorID, ";");
            getline(monFlux,latitude, ";");
            getline(monFlux,longitude, ";");
            Sensor temporary = new Sensor (sensorID,stod(latitude),stod(longitude));
            sensorList.add(temporary);
         }
    }else {
        cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
    }

}

void Read :: readMeasurement(string nom){
    ifstream monFlux(nom.c_str());
    string timestamp;
    Date date;
    string sensorID;
    string attribute;
    string value;
    if (monFlux){
        while (monFlux){
            getline(monFlux, timestamp, ";");
            getline(monFlux,sensorID, ";");
            getline(monFlux,attribute, ";");
            getline(monFlux,value,";");
            date.year = timestamp.subsstr(0,4);
            date.month = timestamp.substr(5,2);
            date.day = timestamp.substr(8,2);
            date.hour = timestamp.substr(11,2);
            date.minute = timestamp.substr(14,2);
            date.second = timestamp.substr(16,2);

           /* getline(timestamp,date.year,"-");
            getline(timestamp,date.month,"-");
            getline(timestamp,date.day," ");
            getline(timestamp,date.hour,":");
            getline(timestamp,date.minutes,":");
            getline(timestamp,date.seconds,"");*/
            Measurement temporary = new Measurement (date,sensorID,attribute,stod(value));
            measurementList.add(temporary);
         }
    }else {
        cout << "Erreur: Impossible d'ouvrir le fichier" << endl;
    }

}

void Read :: readCleaner(string nom){
    ifstream monFlux(nom.c_str());
    string cleanerID;
    double latitude;
    double longitude;
    string timestart;
    string stimestop;
    Date start;
    Date stop;
    if (monFlux){
        while (monFlux){
            getline(monFlux, cleanerID, ";");
            getline(monFlux,latitude, ";");
            getline(monFlux,longitude, ";");
            getline(monFlux,,";");
            getline(monFlux,value,";");
            date.year = timestamp.subsstr(0,4);
            date.month = timestamp.substr(5,2);
            date.day = timestamp.substr(8,2);
            date.hour = timestamp.substr(11,2);
            date.minute = timestamp.substr(14,2);
            date.second = timestamp.substr(16,2);

           /* getline(timestamp,date.year,"-");
            getline(timestamp,date.month,"-");
            getline(timestamp,date.day," ");
            getline(timestamp,date.hour,":");
            getline(timestamp,date.minutes,":");
            getline(timestamp,date.seconds,"");*/
            Measurement temporary = new Measurement (date,sensorID,attribute,stod(value));
            measurementList.add(temporary);
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
                getline(monFlux, userID, ";");
                getline(monFlux,sensorID, ";");
                User temporary = new User(userID, sensorID, 0);
                userList.add(temporary); 
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
                getline(monFlux, providerID, ";");
                getline(monFlux,cleanerID, ";");
                Provider temporary = new Provider(providerID, cleanerID);
                providerList.add(temporary); 
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
                getline(monFlux, attributeID, ";");
                getline(monFlux,unit, ";");
                getline(monFlux,description, ";");
                Attribute temporary = new Attribute(attributeID, unit, description);
                attributeList.add(temporary); 
            }
        }else {
            cout << "Erreur: Impossible d'ouvrir le fichier." << endl;
        }
    }
}
