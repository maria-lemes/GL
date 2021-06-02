#if ! defined ( User_H )
#define User_H

#include <iostream>
using namespace std;


class User
{
    public:
         virtual string getUserID() const = 0;

    protected:
        string userID;

};
#endif
