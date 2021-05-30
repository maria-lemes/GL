
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
            string userID;
            int pointsAwarded;


};

#endif // Provider_H
