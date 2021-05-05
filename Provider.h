/*************************************************************************
                              Provider -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/

#if ! defined ( Provider_H )
#define Provider_H

#include <iostream>
using namespace std;


class Provider
{
    public:
    
        Provider(string pID, string cID);
    
        Provider(const Provider & oneProvider);
    
        string getProviderID(){
            return sensorID;
        }
    
        string getCleanerID(){
            return attribute;
        }
    
       virtual ~Provider();
    
    private:
            string providerID;
            string cleanerID;
            

};

#endif // Provider_H
