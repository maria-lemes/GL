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
using namespace std;


class PrivateIndividual
{
    public:
    
        PrivateIndividual(string id, double points);
    
        PrivateIndividual(const PrivateIndividual & oneIndividual);
    
        string getSensorID(){
            return sensorID;
        }
    
        int getPointsAwarded(){
            return pointsAwarded;
        }
    
       virtual ~PrivateIndividual();
    
    private:
            string sensorID;
            int pointsAwarded;
            

};

#endif // Provider_H
