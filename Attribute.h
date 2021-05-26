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

        string getAttributeID();
<<<<<<< HEAD
        string getUnit();

=======

        string getUnit();

>>>>>>> 553cb66c993ff4edbe6c7f490685c40e5274e5d1
        string getDescription();

        virtual ~Attribute();

    private:
            string attributeID;
            string unit;
            string description;


};

#endif //Attribute_H
