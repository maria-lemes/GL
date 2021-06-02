/*************************************************************************
                              Attribute -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By
    e-mail               :
*************************************************************************/
#include <stdio.h>
#include <iostream>
#include "Attribute.h"

using namespace std;

    Attribute::Attribute(string id, string ut, string descrip){
        attributeID = id;
        unit= ut;
        description = descrip;
    }

    Attribute::Attribute(const Attribute & oneAttribute){
        attributeID = oneAttribute.attributeID;
        unit= oneAttribute.unit;
        description = oneAttribute.description;
    }

    string Attribute::getAttributeID() const{
        return attributeID;
    }

    string Attribute::getUnit() const{
        return unit;
    }

    string Attribute::getDescription() const{
        return description;
    }
