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
#include "User.h"

PrivateIndividual::PrivateIndividual(string uID, string sID, double points){
  userID = uID;
  sensorID = sID;
  pointsAwarded = points;
}

PrivateIndividual::PrivateIndividual(const PrivateIndividual & oneIndividual){
  userID = oneIndividual.userID;
  sensorID = oneIndividual.sensorID;
  pointsAwarded = oneIndividual.pointsAwarded;
}

string PrivateIndividual::getUserID() const{
  return userID;
}

string PrivateIndividual::getSensorID() const{
  return sensorID;
}

int PrivateIndividual::getPointsAwarded() const{
  return pointsAwarded;
}

PrivateIndividual::~PrivateIndividual(){}
