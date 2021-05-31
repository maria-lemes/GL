//
//  Provider.cpp
//
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

#include <stdio.h>
#include "Provider.h"
#include "User.h"

#include <iostream>
using namespace std;

    Provider::Provider(string pID, string cID){
        userID = pID;
        cleanerID = cID;
    }

    Provider::Provider(const Provider & oneProvider){
        userID = oneProvider.userID;
        cleanerID = oneProvider.cleanerID;
    }

    string Provider::getUserID(){
        return userID;
    }

    string Provider::getCleanerID(){
        return cleanerID;
    }

    Provider::~Provider(){}
