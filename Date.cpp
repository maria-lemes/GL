#include <stdio.h>
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date (int oneYear, int oneMonth, int oneDay, int oneHour, int oneMinute, int oneSecond)
{
  setYear(oneYear);
  setMonth(oneMonth);
  setDay(oneDay);
  setHour(oneHour);
  setMinute(oneMinute);
  setSecond(oneSecond);
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
int Date::getYear() const {return year;}
int Date::getMonth() const {return month;}
int Date::getDay() const {return day;}
int Date::getHour() const {return hour;}
int Date::getMinute() const {return minute;}
int Date::getSecond() const {return second;}

//Setters
void Date::setYear(int oneYear) {
  if (oneYear < 0) {year = 1900;}
  else {year = oneYear;}
}
void Date::setMonth(int oneMonth) {
  if (oneMonth < 1) {month = 1;}
  else if (oneMonth > 12) {month = 12;}
  else {month = oneMonth;}
}
void Date::setDay(int oneDay) {
  if (oneDay < 1) {day = 1;}
  else if (oneDay > 31) {day = 31;}
  else {day = oneDay;}
}
void Date::setHour(int oneHour) {
  if (oneHour < 0) {hour = 0;}
  else if (oneHour > 23) {hour = 23;}
  else {hour = oneHour;}
}
void Date::setMinute(int oneMinute) {
  if (oneMinute < 0) {minute = 0;}
  else if (oneMinute > 59) {minute = 59;}
  else {minute = oneMinute;}
}

void Date::setSecond(int oneSecond) {
  if (oneSecond < 0) {second = 0;}
  else if (oneSecond > 59) {second = 59;}
  else {second = oneSecond;}
}

bool Date::operator<(const Date & d1)
{
  if (getYear() < d1.getYear())
  {
    return true;
  } else if (getYear() > d1.getYear())
  {
    return false;
  } else {
    if (getMonth() < d1.getMonth())
    {
      return true;
    } else if (getMonth() > d1.getMonth())
    {
      return false;
    }
    else{
      if (getDay() < d1.getDay())
      {
        return true;
      } else if (getDay() > d1.getDay())
      {
        return false;
      }
      else{
        if (getHour() < d1.getHour())
        {
          return true;
        } else if (getHour() > d1.getHour())
        {
          return false;
        }
        else{
          if (getMinute() < d1.getMinute())
          {
            return true;
          } else if (getMinute() > d1.getMinute())
          {
            return false;
          }
          else{
            if (getSecond() < d1.getSecond())
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
  return getYear()==d1.getYear() && getMonth()==d1.getMonth()
  && getDay() == d1.getDay() && getHour() == d1.getHour() &&
  getMinute() == d1.getMinute() && getSecond() == d1.getSecond();
}

bool Date::operator<=(const Date & d1){
  return((*this) < d1 || (*this) == d1);
}

bool Date::operator>=(const Date & d1){
  return(!((*this) < d1) || (*this) == d1);
}

ostream& operator<<(ostream& os, const Date& dt) {
  os << dt.getDay() << '/' << dt.getMonth() << '/' << dt.getYear() << " " <<
  dt.getHour() << ":" << dt.getMinute() << ":" << dt.getSecond();
  return os;
}
