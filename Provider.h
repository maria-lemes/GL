
#if ! defined ( Provider_H )
#define Provider_H

#include <iostream>
using namespace std;

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
