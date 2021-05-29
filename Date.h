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
      Date (int oneYear, int oneMonth, int oneDay, int oneHour, int oneMinute, int oneSecond);
      Date (const Date &oneDate);
      int getYear();
      int getMonth();
      int getDay();
      int getHour();
      int getMinute();
      int getSecond();

      bool operator<(const Date & d1, const Date & d2);
      bool operator==(const Date & d1, const Date & d2);

      virtual ~PrivateIndividual();

    private:
      int year;
      int month;
      int day;
      int hour;
      int minute;
      int second;
};
#endif //Attribute_H
