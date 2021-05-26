/*************************************************************************
                              PrivateIndividual -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/

#if ! defined ( Provider_H )
#define Provider_H

#include <iostream>
#include "User.h"
using namespace std;


class PrivateIndividual : public User
{
    public:
    
        PrivateIndividual(string sID, double points);
    
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
