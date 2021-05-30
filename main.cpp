#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Read.h"
#include "Sensor.h"
using namespace std;

/*
void selectGov()
{
  string userID;
  cout << "Please provide your UserID :" << endl;
  cin >> userID;
  Admin * ad = new Admin(userID);

  int choice;
  cout << "===== Government Agency =====" << endl;
  cout << "1- Analyze the quality of air" << endl;
  cout << "2- Calculate sensors similarity" << endl;
  cout << "3- Classify sensor's behavior" << endl;
  cout << "0- Return to main menu" << endl;
  cin >> choice;

  switch(choice)
  {
    case 0:
      mainMenu();
    case 1:
      cout << "===== Analyze the quality of air =====" << endl;
      cout << "Calculate the mean of the quality of air in a circular area" << endl << endl;

      float latitude;
      float longitude;
      int radius;
      Date * myDate;
      string dateInput;
      string timeInput;

      cout << "Please input the latitude of the location :" << endl;
      cin >> latitude;

      cout << "Please input the longitude of the location :" << endl;
      cin >> longitude;

      cout << "Please input the radius to define the circular area (with the chosen location as center) :" << endl;
      cin >> radius;

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

      int index = CalculateAirQuality(latitude, longitude, radius, *myDate);
      cout << "The air quality is: " <<  index << endl;

      delete myDate;

      break;
    case 2:
      cout << "===== Calculate sensors similarity =====" << endl;
      cout << "Rank the similarity of sensors comparing to one specific sensor" << endl << endl;

      string sensorID;

      Date * startDate;
      string startDateInput;
      string startTimeInput;

      Date * endDate;
      string endDateInput;
      string endTimeInput;

      cout << "Please input the sensorID :" << endl;
      cin >> sensorID;

      cout << "Please input the starting date from which measurements are taken into account :" << endl;
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

      cout << "Please input the ending date on which measurements are taken into account :" << endl;
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

      vector <string> similarSensors = calculateSimilarity(sensorID, *startDate, *endDate);
      vector <string> :: iterator it;
      cout << "The sensors having measurements similar to the chosen sensor are :" << endl;
      for(it = similarSensors.begin(); it != similarSensors.end(); it++)
      {
        cout << it->sensorID << endl;
      }

      delete startDate;
      delete endDate;

      break;

    case 3:
      cout << "===== Classify sensor's behavior =====" << endl;
      cout << "Check sensor's data validity" << endl << endl;

      string sensorID;
      Date * myDate;
      string dateInput;
      float threshold;
      int nbDays;
      int coeff;

      cout << "Please input the sensorID :" << endl << endl;
      cin >> sensorID;

      cout << "Please input the date of measurement :" << endl;
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

      cout << "Please input the threshold of discrepancy allowed (in %) :" << endl;
      cin >> threshold;

      cout << "Please input the number of days during which data are imported for the time comparison" << endl;
      cin >> nbDays;

      cout << "Please input the preferred factor to evaluate the consistency of this sensor's data :" << endl;
      cout << "\t0- Data from neighboring sensors " << endl;
      cout << "\t1- Time" << endl;
      cin >> coeff;

      bool validity = sensorSanityCheck(sensorID, *myDate, threshold, nbDays, coeff);

      if (bool = true)
      {
        cout << "The data provided by the sensor are valid." << endl;
      } else {
        cout << "The data provided by the sensor are NOT reliable." << endl;
      }

      delete myDate;

      break;

    default:
      cerr << "Invalid choice. Please try again." << endl;
      continue;
  }
  delete ad;
}

void selectProvider()
{

}

void selectIndividual()
{

}

void mainMenu()
{
  int choice;

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
      break;

    case 2:
      selectProvider();
      break;

    case 3:
      selectIndividual();
      break;

    default:
      cerr << "Invalid choice. Please try again." << endl;
      continue;
   }
}
*/
int main()
{
  /*
  while (1)
  {
    mainMenu();
  }
  */
  Read * r = new Read();
  r -> readSensor("./data/sensors.csv");
  for (auto sensor : r -> getSensorList())
  {
    cout << sensor.getSensorID() << " || lat: " << sensor.getLatitude() <<
     " lon: " << sensor.getLongitude() << endl;
  }
}
