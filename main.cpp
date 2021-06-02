#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Read.h"
#include "Controller.h"
#include "Admin.h"
#include "Attribute.h"
#include "Cleaner.h"
#include "Date.h"
#include "Measurement.h"
#include "PrivateIndividual.h"
#include "Provider.h"
#include "Sensor.h"
using namespace std;


//Controller * controller = new Controller();

int selectGov()
{
  string sensorID;
  Date * myDate;
  string dateInput;
  string timeInput;

  const string qualityTable[] = {"Really Good","Really Good", "Good","Good",
   "Average", "Poor", "Poor", "Bad", "Bad" ,"Really Bad"};

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
      Controller * controller = new Controller();
      cout << "===== Analyze the quality of air =====" << endl;
      cout << "Calculate the mean of the quality of air in a circular area" << endl << endl;


      float latitude;
      float longitude;
      double radius;
      int timeChoice;


      cout << "Please enter the latitude of the location :" << endl;
      cin >> latitude;

      cout << "Please enter the longitude of the location :" << endl;
      cin >> longitude;

      cout << "Please enter the radius to define the circular area (in kilometers) :" << endl;
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
      Date * endDate = new Date();
      int index = controller->calculateAirQuality(latitude, longitude, radius, *myDate, *endDate, timeChoice);
      cout << "The air quality is: " << qualityTable[index] << endl;

      delete endDate;
      delete myDate;

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

      int index = controller->calculateAirQuality(latitude, longitude, radius, *myStartDate, *myEndingDate, timeChoice);

      cout << "The air quality is: " <<  qualityTable[index] << endl;


      delete myStartDate;
      delete myEndingDate;
      goto menu;

      }else{
        cout << "Please enter a valid choice" << endl;
      }
    }

    }
    case 2: {
      Controller * controller = new Controller();
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

      multimap<double,pair<string,pair<double,double>>> similarSensors = controller->calculateSimilarity(sensorID, *startDate, *endDate);

      cout << "Here is the sensor's ranking from the most similar to the less similar to the sensor chosen :" << endl;
      int i = 1;
      for(auto s : similarSensors)
      {
        cout << i << ". " << s.second.first << " - Located at : "
        << s.second.second.first << "°, " << s.second.second.second << "°"
        << endl;
        i++;
      }

      delete startDate;
      delete endDate;

      goto menu;
    }
    case 3: {
      Controller * controller = new Controller();
      cout << "===== Classify sensor's behavior =====" << endl;
      cout << "Check sensor's data validity" << endl << endl;

      float threshold;
      int coeff;
      int radius;

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

      cout << "Please input the threshold of discrepancy allowed (in %):" << endl;
      cin >> threshold;

      cout << "Please input the radius to calculate the area to be considered around the suspicious sensor (in km): " << endl;
      cin >> radius;

      bool validity = controller->sensorSanityCheck(sensorID, *myDate, radius, threshold/100);

      if (validity)
      {
        cout << "The data provided by the sensor is valid." << endl;
      } else {
        cout << "The data provided by the sensor is NOT reliable." << endl;
      }

      delete myDate;

      goto menu;
    }
    case 4: {
        int choice;
        int index;
        cout << "Do you want to run:" << endl;
        cout << "1- Functionnality tests with short .csv" << endl;
        cout << "2- Performance tests" << endl;
        cin >> choice;

        if(choice==1){

            //AirQuality test:
            Controller * controller = new Controller("./Test/SensorTest.csv", "./Test/Test3.csv", "./data/cleaners.csv", "./data/users.csv", "./data/providers.csv", "./data/attributes.csv");
            Date date (2019, 01, 01, 12, 00, 00);
            Date endDate (2019, 01, 02, 12, 00, 00);

            index = controller->calculateAirQuality(44, -1, 0, date, date, 1);
            cout << "The air quality is: " <<  qualityTable[index] << endl;

            index = controller->calculateAirQuality(44, -1, 10, date, date, 1);
            cout << "The air quality is: " <<  qualityTable[index] << endl;

            index = controller->calculateAirQuality(44, -1, 100, date, date, 1);
            cout << "The air quality is: " <<  qualityTable[index] << endl;
            delete controller;

            controller = new Controller("./Test/SensorTest.csv", "./Test/Test4.csv", "./data/cleaners.csv", "./data/users.csv", "./data/providers.csv", "./data/attributes.csv");
            index = controller->calculateAirQuality(44, -1, 50, date, endDate, 1);
            cout << "The air quality is: " <<  qualityTable[index] << endl;
            delete controller;

            cout << "Air quality test DONE" << endl;

            //SensorSimilarity test:
            controller = new Controller("./Test/SensorTest.csv", "./Test/Test1.csv", "./data/cleaners.csv", "./data/users.csv", "./data/providers.csv", "./data/attributes.csv");
            multimap<double,pair<string,pair<double,double>>> similarSensors = controller->calculateSimilarity("Sensor0", date, date);

            cout << "Here is the sensor's ranking from the most similar to the less similar to the sensor chosen :" << endl;
            int i = 1;
            for(auto s : similarSensors)
            {
              cout << i << ". " << s.second.first << " - Located at : "
              << s.second.second.first << "°, " << s.second.second.second << "°"
              << endl;
              i++;
            }
            delete controller;

            controller = new Controller("./Test/SensorTest.csv", "./Test/Test2.csv", "./data/cleaners.csv", "./data/users.csv", "./data/providers.csv", "./data/attributes.csv");
            similarSensors = controller->calculateSimilarity("Sensor0", date, endDate);
            cout << "Here is the sensor's ranking from the most similar to the less similar to the sensor chosen :" << endl;
            i = 1;
            for(auto s : similarSensors)
            {
              cout << i << ". " << s.second.first << " - Located at : "
              << s.second.second.first << "°, " << s.second.second.second << "°"
              << endl;
              i++;
            }

            cout << "Similarity test DONE" << endl;


            //DataValidity test:
            controller->sensorSanityCheck("Sensor36", date, 500, 0.01);
            delete controller;
            cout << "Data validity test DONE" << endl;

        }if(choice==2){
            Controller * controller = new Controller();
            delete controller;

        }else{
            cout <<"Input must be 1 or 2" << endl;
        }

        break;
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

  return 0;
}
