#include <iostream>
#include "User.h"
#include "Admin.h"
using namespace std;

 Admin::Admin(string uID){
    userID = uID;
 }

 Admin::Admin(const Admin & oneAdmin){
         userID = oneAdmin.userID;
 }


 string Admin::getUserID(){
      return userID;
 }
