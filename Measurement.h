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
using namespace std;

struct _date{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

    inline bool operator==(_date b)
    {
      return year==b.year && month==b.month && day==b.day && hour==b.hour &&
      minute==b.minute && second==b.second;
    }

    inline bool operator<(_date b)
    {
      return false;
    } else {
      if (month < b.month)
      {
        return true;
      } else if (month > b.month)
      {
        return false;
      }
      else{
        if (day < b.day)
        {
          return true;
        } else if (day > b.day)
        {
          return false;
        }
        else{
          if (hour < b.hour)
          {
            return true;
          } else if (hour > b.hour)
          {
            return false;
          }
          else{
            if (minute < b.minute)
            {
              return true;
            } else if (minute > b.minute)
            {
              return false;
            }
            else{
              if (second < b.second)
              {
                return true;
              } else if (second > b.second)
              {
                return false;
              }
              else{
                return false;
              }
            }
          }
        }
      }
    }
}
*/

class Measurement
{
    public:

        Measurement(string sID, string att, double val, date time);

        Measurement(const Measurement & oneMeasurement);

        string getSensorID();

        string getAttribute();

        double getValue();

        struct date getDate();

        virtual ~Measurement();

    private:
            string sensorID;
            string attribute;
            float value;
            struct date date;

};

#endif // Measurement_H
