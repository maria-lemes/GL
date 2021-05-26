/*************************************************************************
                              Cleaner -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/

#if ! defined ( Cleaner_H )
#define Cleaner_H

#include <iostream>
using namespace std;

struct date{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};


class Cleaner
{
    public:
    
        Cleaner(string id, double lat, double lon, date startTime , date stopTime);
    
        Cleaner(const Cleaner & oneCleaner);
        
        string getCleanerID();
        
        double getLatitude();
        
        double getLongitude();
    
        date getStart();
        
        date getStop();
    
        virtual ~Cleaner();

    private:
            string cleanerID;
            double latitude;
            double longitude;
            date start;
            date stop;
};

#endif // Cleaner_H
