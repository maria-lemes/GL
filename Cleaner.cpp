//
//  Cleaner.cpp
//
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

#include <stdio.h>
#include <iostream>
#include "Cleaner.h"
#include "Date.h"
using namespace std;


    Cleaner::Cleaner(string id, double lat, double lon, Date startTime , Date stopTime){
        cleanerID = id;
        latitude = lat;
        longitude = lon;
        start = *(new Date(startTime));
        stop = *(new Date(stopTime));
    }

    Cleaner:: Cleaner(const Cleaner & oneCleaner){
        cleanerID = oneCleaner.cleanerID;
        latitude = oneCleaner.latitude;
        longitude = oneCleaner.longitude;
        start = oneCleaner.start;
        stop = oneCleaner.stop;
    }

    double Cleaner::getLatitude() const{
        return latitude;
    }

    string Cleaner:: getCleanerID() const{
        return cleanerID;
    }
    double Cleaner::getLongitude() const{
        return longitude;
    }

    Date Cleaner::getStart() const{
        return start;
    }

    Date Cleaner::getStop() const{
        return stop;
    }
