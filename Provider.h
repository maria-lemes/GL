
#if ! defined ( Provider_H )
#define Provider_H

#include <iostream>
#include "User.h"
using namespace std;

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
