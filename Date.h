/*************************************************************************
                              Attribute -  description
                             -------------------
    début                : 05/2021
    copyright            : (C) By
    e-mail               :
*************************************************************************/
#if ! defined ( Date_H )
#define Date_H

#include <iostream>
using namespace std;

class Date
{
    public:
      Date (int oneYear=0 , int oneMonth =0, int oneDay=0 , int oneHour=0 , int oneMinute = 0 , int oneSecond = 0);
      Date (const Date &oneDate);
      int getYear() const;
      int getMonth() const;
      int getDay() const;
      int getHour() const;
      int getMinute() const;
      int getSecond() const;
      void setYear(int aYear);
      void setMonth(int aMonth);
      void setDay(int aDay);
      void setHour(int anHour);
      void setMinute(int aMinute);
      void setSecond(int aSecond);

      bool operator<(const Date& d1);
      bool operator>(const Date& d1);
      bool operator==(const Date& d1);
      bool operator<=(const Date & d1);
      bool operator>=(const Date & d1);
      friend ostream& operator<<(ostream& os, const Date& dt);


    private:
      int year;
      int month;
      int day;
      int hour;
      int minute;
      int second;
};
#endif //Attribute_H
