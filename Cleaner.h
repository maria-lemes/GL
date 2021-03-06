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
#include "Measurement.h"
#include "Date.h"
using namespace std;


class Cleaner
{
    public:

        Cleaner(string id, double lat, double lon, Date startTime , Date stopTime);

        Cleaner(const Cleaner & oneCleaner);

        string getCleanerID() const;

        double getLatitude() const;

        double getLongitude() const;

        Date getStart() const;

        Date getStop() const;

    private:
            string cleanerID;
            double latitude;
            double longitude;
            Date start;
            Date stop;
};

#endif // Cleaner_H
