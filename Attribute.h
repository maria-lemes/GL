/*************************************************************************
                              Attribute -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By 
    e-mail               :
*************************************************************************/

#if ! defined ( Attribute_H )
#define Attribute_H


class Attribute
{
    public:
    
        Attribute(string id, string ut, string descrip);
        
        Attribute(const Attribute & oneAttribute);
        
        string getAttributeID(){
            return sensorID;
        }
        
        string getUnit(){
            return unit;
        }
        
        string getDescription(){
            return description;
        }

        virtual ~Attribute();

    private:
            string AttributeID;
            string unit;
            string description;


};

#endif //Attribute_H
