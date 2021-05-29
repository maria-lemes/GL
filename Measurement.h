/*************************************************************************
                              Measurement -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By
    e-mail               :
*************************************************************************/

#if ! defined ( Measurement_H )
#define Measurement_H

#include <iostream>
#include "Date.h"
using namespace std;


class Measurement
{
    public:

        Measurement(string sID, string att, double val, Date time);

        Measurement(const Measurement & oneMeasurement);

        string getSensorID();

        string getAttribute();

        double getValue();

        Date getDate();

        virtual ~Measurement();

    private:
            string sensorID;
            string attribute;
            float value;
            Date date;

};

#endif // Measurement_H
