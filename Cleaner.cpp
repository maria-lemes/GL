//
//  Cleaner.cpp
//  
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

#include <stdio.h>
#include <iostream>
#include "Cleaner.h"
using namespace std;


    Cleaner::Cleaner(string id, double lat, double lon, date startTime , date stopTime){
        cleanerID = id;
        latitude = lat;
        longitude = lon;
        start = startTime;
        stop = stopTime;
    }

    Cleaner:: Cleaner(const Cleaner & oneCleaner){
        cleanerID = oneCleaner.cleanerID;
        latitude = oneCleaner.latitude;
        longitude = oneCleaner.longitude;
        start = oneCleaner.start;
        stop = oneCleaner.stop;
    }

    double Cleaner::getLatitude(){
        return latitude;
    }
    
    double Cleaner::getLongitude(){
        return longitude;
    }

    date Cleaner::getStart(){
        return start;
    }
    
    date Cleaner::getStop(){
        return stop;
    }
