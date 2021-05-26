/*************************************************************************
                              PrivateIndividual -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/

#if ! defined ( PrivateIndiv_H )
#define PrivateIndiv_H

#include <iostream>
using namespace std;


class PrivateIndividual
{
    public:
    
        PrivateIndividual(string sID, double points);
    
        PrivateIndividual(const PrivateIndividual & oneIndividual);
    
        string getSensorID();
    
        int getPointsAwarded();
    
       virtual ~PrivateIndividual();
    
    private:
            string sensorID;
            int pointsAwarded;
            

};

#endif // Provider_H
