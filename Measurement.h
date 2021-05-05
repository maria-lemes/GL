/*************************************************************************
                              Measurement -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/

#if ! defined ( Measurement_H )
#define Measurement_H

#include <iostream>
using namespace std;


struct date{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
}


class Measurement
{
    public:
    
        Measurement(string sId, string att, double val, date time);
        
        Measurement(const Measurement & oneMeasurement);
        
        string getSensorID(){
            return sensorID;
        }
        
        string getAttribute(){
            return attribute;
        }
        
        double getValue(){
            return value;
        }
    
        date getTimestamp(){
            return timestamp;
        }

        virtual ~Measurement();
    
    private:
            string sensorID;
            string attribute;
            double value;
            date timestamp;

};

#endif // Measurement_H
