#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Read.h"
#include "Controller.h"
#include "Admin.h"
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
      break;
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

      cout << "Please input the time of measurement (hh:mm) :" << endl;
      cin >> timeInput;
      int hour = stoi(timeInput.substr(0,2));
      int minute = stoi(timeInput.substr(3,2));

      myDate = new Date(year,month,day,hour,minute);
      int index = controller->calculateAirQuality(latitude, longitude, radius, *myDate);
      cout << "The air quality is: " <<  index << endl;

      goto menu;

      } else if (timeChoice == 2){

      cout << "Please input the starting date of measurement (yyyy-mm-dd) :" << endl;
      cin >> dateInput;
      int year = stoi(dateInput.substr(0,4));
      int month = stoi(dateInput.substr(5,2));
      int day = stoi(dateInput.substr(8,2));

      cout << "Please input the starting time of measurement (hh:mm) :" << endl;
      cin >> timeInput;
      int hour = stoi(timeInput.substr(0,2));
      int minute = stoi(timeInput.substr(3,2));

      Date * myStartDate = new Date(year,month,day,hour,minute);


      cout << "Please input the ending date of measurement (yyyy-mm-dd) :" << endl;
      cin >> dateInput;
      year = stoi(dateInput.substr(0,4));
      month = stoi(dateInput.substr(5,2));
      day = stoi(dateInput.substr(8,2));

      cout << "Please input the ending time of measurement (hh:mm) :" << endl;
      cin >> timeInput;
      hour = stoi(timeInput.substr(0,2));
      minute = stoi(timeInput.substr(3,2));

      Date * myEndingDate = new Date(year,month,day,hour,minute);

      goto menu;

      }else{
        cout << "Please enter a valid choice" << endl;
      }
    }

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

      cout << "Please input the sensorID (Sensor1, Sensor2,...) :" << endl;
      cin >> sensorID;

      cout << "Please input the starting date from which measurements are taken into account (yyyy-mm-dd) :" << endl;
      cin >> startDateInput;
      int year_start = stoi(startDateInput.substr(0,4));
      int month_start = stoi(startDateInput.substr(5,2));
      int day_start = stoi(startDateInput.substr(8,2));

      cout << "Please input the starting time of measurement (hh:mm) :" << endl;
      cin >> startTimeInput;
      int hour_start = stoi(startTimeInput.substr(0,2));
      int minute_start = stoi(startTimeInput.substr(3,2));

      startDate = new Date(year_start,month_start,day_start,hour_start,minute_start);

      cout << "Please input the ending date on which measurements are taken into account (yyyy-mm-dd) :" << endl;
      cin >> endDateInput;
      int year_end = stoi(endDateInput.substr(0,4));
      int month_end = stoi(endDateInput.substr(5,2));
      int day_end = stoi(endDateInput.substr(8,2));

      cout << "Please input the ending time of measurement (hh:mm) :" << endl;
      cin >> endTimeInput;
      int hour_end = stoi(endTimeInput.substr(0,2));
      int minute_end = stoi(endTimeInput.substr(3,2));

      endDate = new Date(year_end,month_end,day_end,hour_end,minute_end);

      multimap<double,string> similarSensors = controller->calculateSimilarity(sensorID, *startDate, *endDate);

      cout << "The sensors having measurements similar to the chosen sensor are :" << endl;
      int i = 1;
      for(auto s : similarSensors)
      {
        cout << i << ". " << s.second << endl;
        i++;
      }

      goto menu;
    }
    case 3: {
      cout << "===== Classify sensor's behavior =====" << endl;
      cout << "Check sensor's data validity" << endl << endl;


      float threshold;
      int nbDays;
      int coeff;

      cout << "Please input the sensorID (Sensor1, Sensor2,...):" << endl << endl;
      cin >> sensorID;

      cout << "Please input the date of measurement (yyyy-mm-dd) :" << endl;
      cin >> dateInput;
      int year = stoi(dateInput.substr(0,4));
      int month = stoi(dateInput.substr(5,2));
      int day = stoi(dateInput.substr(8,2));

      cout << "Please input the time of measurement (hh:mm) :" << endl;
      cin >> timeInput;
      int hour = stoi(timeInput.substr(0,2));
      int minute = stoi(timeInput.substr(3,2));


      myDate = new Date(year,month,day,hour,minute);


      cout << "Please input the threshold of discrepancy allowed (in %) :" << endl;
      cin >> threshold;

      cout << "Please input the number of days during which data are imported for the time comparison" << endl;
      cin >> nbDays;


      bool validity = controller->sensorSanityCheck(sensorID, *myDate, threshold/100);

      if (validity)
      {
        cout << "The data provided by the sensor is valid." << endl;
      } else {
        cout << "The data provided by the sensor is NOT reliable." << endl;
      }

      goto menu;
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

/*
   int choice;
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
          selectGov();
          goto menu;

        case 2:
          selectProvider();
          goto menu;

        case 3:
          selectIndividual();
          goto menu;

        default:
          cerr << "Invalid choice. Please try again." << endl;
          goto menu;
      }
*/
  selectGov();
  return 0;
}
