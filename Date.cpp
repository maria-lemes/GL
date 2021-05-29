#include <stdio.h>
#include <iostream>
#include "Date.h"
using namespace std;

    Date::Date (int oneYear, int oneMonth, int oneDay, int oneHour, int oneMinute, int oneSecond)
    {
      year = oneYear;
      month = oneMonth;
      day = oneDay;
      hour = oneHour;
      minute = oneMinute;
      second = oneSecond;
    }

    Date::Date (const Date &oneDate)
    {
      year = oneDate.getYear();
      month = oneDate.getMonth();
      day = oneDate.getDay();
      hour = oneDate.getHour();
      minute = oneDate.getMinute();
      second = oneDate.getSecond();
    }

    //Getters
    int Date::getYear() {return year;}
    int Date::getMonth() {return month;}
    int Date::getDay() {return day;}
    int Date::getHour() {return hour;}
    int Date::getMinute() {return minute;}
    int Date::getSecond() {return second;}

    //Setters
    void Date::setYear(int aYear) {year = aYear;}
    void Date::setMonth(int aMonth) {month = aMonth;}
    void Date::setDay(int aDay) {day = aDay;}
    void Date::setHour(int anHour) {hour = anHour;}
    void Date::setMinute(int aMinute) {minute = aMinute;}
    void Date::setSecond(int aSecond) {second = aSecond;}

    bool Date::operator<(const Date & d1)
    {
      if (this.getYear() < d.getYear())
      {
        return true;
      } else if (this.getYear() d.getYear())
      {
        return false;
      } else {
        if (this.getMonth() < d1.getMonth())
        {
          return true;
        } else if (this.getMonth() > d1.getMonth())
        {
          return false;
        }
        else{
          if (this.getDay() < d1.getDay())
          {
            return true;
          } else if (this.getDay() > d1.getDay())
          {
            return false;
          }
          else{
            if (this.getHour() < d1.getHour())
            {
              return true;
            } else if (this.getHour() > d1.getHour())
            {
              return false;
            }
            else{
              if (this.getminute() < d1.getMinute())
              {
                return true;
              } else if (this.getMinute() > d1.getMinute())
              {
                return false;
              }
              else{
                if (this.getSecond() < d1.getSecond())
                {
                  return true;
                } else
                {
                  return false;
                }
              }
            }
          }
        }
      }
    }

    bool Date::operator==(const Date & d1)
    {
      return this.getYear()==d1.getYear() && this.getMonth()==d1.getmonth()
      && this.getDay() == d1.getDay() && this.getHour() == d1.getHour() &&
      this.getMinute() == d1.getMinute() && this.getSecond() == d1.getSecond();
    }
