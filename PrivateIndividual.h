/*************************************************************************
                              PrivateIndividual -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/

#if ! defined ( PrivateIndividual_H )
#define PrivateIndividual_H

#include <iostream>
#include "User.h"
using namespace std;


class PrivateIndividual : public User
{
    public:
    
        PrivateIndividual(string uID, string sID, double points);
    
        PrivateIndividual(const PrivateIndividual & oneIndividual);

        string getUserID();
    
        string getSensorID();
    
        int getPointsAwarded();
    
       virtual ~PrivateIndividual();
    
    private:
            string sensorID;
            int pointsAwarded;
            

};

#endif // Provider_H
