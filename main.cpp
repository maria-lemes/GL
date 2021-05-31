#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Read.h"
#include "Controller.h"
#include "Admin.h"
#include "Date.h"
using namespace std;


Controller * controller = new Controller();

int selectGov()
{
  string sensorID;
  Date * myDate;
  string dateInput;
  string timeInput;

  string userID;
  cout << "Please provide your UserID :" << endl;
  cin >> userID;
  Admin * ad = new Admin(userID);

  menu:
  int choice;
  cout << "===== Government Agency =====" << endl;
  cout << "1- Analyze the quality of air" << endl;
  cout << "2- Calculate sensors similarity" << endl;
  cout << "3- Check sensors data" << endl;
  cout << "0- Return to main menu" << endl;
  cin >> choice;

  switch(choice)
  {
    case 0:
      return 1;
    case 1: {
      cout << "===== Analyze the quality of air =====" << endl;
      cout << "Calculate the mean of the quality of air in a circular area" << endl << endl;

      float latitude;
      float longitude;
      int radius;
      int timeChoice;


      cout << "Please enter the latitude of the location :" << endl;
      cin >> latitude;

      cout << "Please enter the longitude of the location :" << endl;
      cin >> longitude;

      cout << "Please enter the radius to define the circular area (with the chosen location as center) :" << endl;
      cin >> radius;

      cout << "Would you like to obtain the results for a given moment or a specified period of time?" << endl;
      cout << "1- Given moment" << endl;
      cout << "2- Period of time" << endl;


     while(1){

      cin >>timeChoice;
      if(timeChoice == 1){
      cout << "Please input the date of measurement (yyyy-mm-dd) :" << endl;
      cin >> dateInput;
      int year = stoi(dateInput.substr(0,4));
      int month = stoi(dateInput.substr(5,2));
      int day = stoi(dateInput.substr(8,2));

      cout << "Please input the time of measurement (hh:mm:ss) :" << endl;
      cin >> timeInput;
      int hour = stoi(timeInput.substr(0,2));
      int minute = stoi(timeInput.substr(3,2));
      int second = stoi(timeInput.substr(6,2));

      myDate = new Date(year,month,day,hour,minute,second);
      int index = controller->calculateAirQuality(latitude, longitude, radius, *myDate);
      cout << "The air quality is: " <<  index << endl;

      delete myDate;
      return 0;

      } else if (timeChoice == 2){

      cout << "Please input the starting date of measurement (yyyy-mm-dd) :" << endl;
      cin >> dateInput;
      int year = stoi(dateInput.substr(0,4));
      int month = stoi(dateInput.substr(5,2));
      int day = stoi(dateInput.substr(8,2));

      cout << "Please input the starting time of measurement (hh:mm:ss) :" << endl;
      cin >> timeInput;
      int hour = stoi(timeInput.substr(0,2));
      int minute = stoi(timeInput.substr(3,2));
      int second = stoi(timeInput.substr(6,2));

      Date * myStartDate = new Date(year,month,day,hour,minute,second);


      cout << "Please input the ending date of measurement (yyyy-mm-dd) :" << endl;
      cin >> dateInput;
      year = stoi(dateInput.substr(0,4));
      month = stoi(dateInput.substr(5,2));
      day = stoi(dateInput.substr(8,2));

      cout << "Please input the ending time of measurement (hh:mm:ss) :" << endl;
      cin >> timeInput;
      hour = stoi(timeInput.substr(0,2));
      minute = stoi(timeInput.substr(3,2));
      second = stoi(timeInput.substr(6,2));

      Date * myEndingDate = new Date(year,month,day,hour,minute,second);

      return 0;

      }else{
        cout << "Please enter a valid choice" << endl;
      }
    }

      return 0;
    }
    case 2: {
      cout << "===== Calculate sensors similarity =====" << endl;
      cout << "Rank the similarity of sensors comparing to one specific sensor" << endl << endl;


      Date * startDate;
      string startDateInput;
      string startTimeInput;

      Date * endDate;
      string endDateInput;
      string endTimeInput;

      cout << "Please input the sensorID :" << endl;
      cin >> sensorID;

      cout << "Please input the starting date from which measurements are taken into account (yyyy-mm-dd) :" << endl;
      cin >> startDateInput;
      int year_start = stoi(startDateInput.substr(0,4));
      int month_start = stoi(startDateInput.substr(5,2));
      int day_start = stoi(startDateInput.substr(8,2));

      cout << "Please input the starting time of measurement (hh:mm:ss) :" << endl;
      cin >> startTimeInput;
      int hour_start = stoi(startTimeInput.substr(0,2));
      int minute_start = stoi(startTimeInput.substr(3,2));
      int second_start = stoi(startTimeInput.substr(6,2));

      startDate = new Date(year_start,month_start,day_start,hour_start,minute_start,second_start);

      cout << "Please input the ending date on which measurements are taken into account (yyyy-mm-dd) :" << endl;
      cin >> endDateInput;
      int year_end = stoi(endDateInput.substr(0,4));
      int month_end = stoi(endDateInput.substr(5,2));
      int day_end = stoi(endDateInput.substr(8,2));

      cout << "Please input the ending time of measurement (hh:mm:ss) :" << endl;
      cin >> endTimeInput;
      int hour_end = stoi(endTimeInput.substr(0,2));
      int minute_end = stoi(endTimeInput.substr(3,2));
      int second_end = stoi(endTimeInput.substr(6,2));

      endDate = new Date(year_end,month_end,day_end,hour_end,minute_end,second_end);

      list <string> similarSensors = controller->calculateSimilarity(sensorID, *startDate, *endDate);

      cout << "The sensors having measurements similar to the chosen sensor are :" << endl;
      for(auto s : similarSensors)
      {
        cout << s << endl;
      }

      delete startDate;
      delete endDate;

      return 0;
    }
    case 3: {
      cout << "===== Classify sensor's behavior =====" << endl;
      cout << "Check sensor's data validity" << endl << endl;


      float threshold;
      /*int nbDays;
      int coeff;

      cout << "Please input the sensorID (Sensor1, Sensor2,...):" << endl << endl;
      cin >> sensorID;

      cout << "Please input the date of measurement (yyyy-mm-dd) :" << endl;
      cin >> dateInput;
      int year = stoi(dateInput.substr(0,4));
      int month = stoi(dateInput.substr(5,2));
      int day = stoi(dateInput.substr(8,2));

      cout << "Please input the time of measurement (hh:mm:ss) :" << endl;
      cin >> timeInput;
      int hour = stoi(timeInput.substr(0,2));
      int minute = stoi(timeInput.substr(3,2));
      int second = stoi(timeInput.substr(6,2));*/

      //myDate = new Date(year,month,day,hour,minute,second);
      myDate = new Date(2019,01,15,12,00,00);

      cout << "Please input the threshold of discrepancy allowed (in %) :" << endl;
      cin >> threshold;

      /*cout << "Please input the number of days during which data are imported for the time comparison" << endl;
      cin >> nbDays;

      cout << "Please input the preferred factor to evaluate the consistency of this sensor's data :" << endl;
      cout << "\t0- Data from neighboring sensors " << endl;
      cout << "\t1- Time" << endl;
      cin >> coeff;*/

      //bool validity = controller->sensorSanityCheck(sensorID, *myDate, threshold/100);
      bool validity = controller->sensorSanityCheck("Sensor0", *myDate, threshold/100);

      /*if (validity)
      {
        cout << "The data provided by the sensor is valid." << endl;
      } else {
        cout << "The data provided by the sensor is NOT reliable." << endl;
    }*/

      delete myDate;

      return 0;
    }
    default: {
      cerr << "Invalid choice. Please try again." << endl;
      goto menu;
    }
  }

}

void selectProvider()
{

}

void selectIndividual()
{

}


int main()
{

   /*int choice;
    menu:
      cout << "Please select your role : " << endl;
      cout << "\t1- Government Agency" << endl;
      cout << "\t2- Air Cleaner Provider" << endl;
      cout << "\t3- Private Individual" << endl;
      cout << "\t0: Quit" << endl;

      cin >> choice;

      switch (choice)
      {
        case 0:
          return 0;

        case 1:
          if (!selectGov()){goto menu;}
          else{break;}

        case 2:
          selectProvider();
          break;

        case 3:
          selectIndividual();
          break;

        default:
          cerr << "Invalid choice. Please try again." << endl;
          goto menu;
      }*/

  /*Read * r = new Read();
  r -> readMeasurement();
  for (auto measurement : r -> getMeasurementList())
  {
    cout << measurement.getDate() << " || sensorID: " << measurement.getSensorID() <<
     " attribute: " << measurement.getAttribute() << "|| value" << measurement.getValue() << endl;
 }*/

    //selectGov();
    Date start(2010,1,1,0,0,0);
    Date end(2021,1,1,0,0,0);
    Read r;

    for (string sensorId : r.calculateSimilarity("Sensor0",start,end))
    {
      cout << sensorId << endl;
    }



  return 0;
}
