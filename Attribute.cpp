//
//  Attribute.cpp
//  
//
//  Created by Maria Eduarda Zen Lemes on 05/05/2021.
//

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

    string Attribute::getAttributeID(){
        return attributeID;
    }

    string Attribute::getUnit(){
        return unit;
    }

    string Attribute::getDescription(){
        return description;
    }
