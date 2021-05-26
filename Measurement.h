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
struct date{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;



    inline bool operator==(date b)
    {
      return year==b.year && month==b.month && day==b.day && hour==b.hour &&
      minute==b.minute && second==b.second;
    }

    inline bool operator<(date b)
    {
      if (year < b.year)
      {
        return true;
      } else if (year > b.year)
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
  }

  
class Measurement
{
    public:

        Measurement(string sID, string att, double val, date time);

        Measurement(const Measurement & oneMeasurement);

        string getSensorID();

        string getAttribute();

        string getAttribute();

        double getValue();

        date getTimestamp();

        virtual ~Measurement();

    private:
            string sensorID;
            string attribute;
            double value;
            date timestamp;

};

#endif // Measurement_H