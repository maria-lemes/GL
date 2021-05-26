/*************************************************************************
                              Provider -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/


#include <iostream>
using namespace std;

#if ! defined ( Provider_H )
#define Provider_H

class Provider
{
public:
    
    Provider(string pID, string cID);
    
    Provider(const Provider & oneProvider);
    
    string getProviderID();
    string getCleanerID();
    
    virtual ~Provider();
    
private:
    string providerID;
    string cleanerID;
    

};

#endif // Provider_H
