#if ! defined ( Admin_H )
#define Admin_H

#include <iostream>
#include "User.h"
using namespace std;


class Admin : public User
{
    public:
        string getUserID();



};
#endif