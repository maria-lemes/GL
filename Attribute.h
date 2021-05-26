/*************************************************************************
                              Attribute -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By
    e-mail               :
*************************************************************************/

#if ! defined ( Attribute_H )
#define Attribute_H

#include <iostream>
using namespace std;


class Attribute
{
    public:

        Attribute(string id, string ut, string descrip);

        Attribute(const Attribute & oneAttribute);

        string getAttributeID(){
            return attributeID;
        }
        
        string getUnit(){
            return unit;
        }

        string getDescription(){
            return description;
        }

        virtual ~Attribute();

    private:
            string attributeID;
            string unit;
            string description;


};

#endif //Attribute_H
