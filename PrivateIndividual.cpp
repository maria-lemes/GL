//
//  PrivateIndividual.cpp
//  
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

#include <stdio.h>
#include <iostream>
using namespace std;

#include "PrivateIndividual.h"

    PrivateIndividual::PrivateIndividual(string sID, double points){
        sensorID = sID;
        pointsAwarded = points;
    }

    PrivateIndividual::PrivateIndividual(const PrivateIndividual & oneIndividual){
        sensorID = oneIndividual.sensorID;
        pointsAwarded = oneIndividual.pointsAwarded;
    }

    string PrivateIndividual::getSensorID(){
        return sensorID;
    }

    int PrivateIndividual::getPointsAwarded(){
        return pointsAwarded;
    }