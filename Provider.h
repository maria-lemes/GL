/*************************************************************************
                              Provider -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/


#include <iostream>
#include "User.h"
using namespace std;

#if ! defined ( Provider_H )
#define Provider_H

class Provider : public User
{
public:
    
    Provider(string pID, string cID);
    
    Provider(const Provider & oneProvider);
    
    string getUserID();
    string getCleanerID();
    
    virtual ~Provider();
    
private:
    string cleanerID;
    

};

#endif // Provider_H
