#include <iostream>
#include <string.h>
#include <vector>
#include <Statistics.h>
#include <Measurements.h>
using namespace std;

void selectGov()
{
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

      double latitude;
      double longitude;
      double radius;
      date myDate;
      string dateInput;
      string timeInput;

      cout << "Please input the latitude of the location :" << endl;
      cin >> latitude;

      cout << "Please input the longitude of the location :" << endl;
      cin >> longitude;

      cout << "Please input the date of measurement (yyyy/mm/dd) :" << endl;
      cin >> dateInput;
      myDate.year = stoi(dateInput.substr(0,4));
      myDate.month = stoi(dateInput.substr(5,2));
      myDate.day = stoi(dateInput.substr(8,2));

      cout << "Please input the time of measurement (hh:mm:ss) :" << endl;
      cin >> timeInput;
      myDate.hour = stoi(timeInput.substr(0,2));
      myDate.minute = stoi(timeInput.substr(3,2));
      myDate.second = stoi(timeInput.substr(6,2));


      // have to convert dateInput to type date here

      float maxIndex = CalculateAirQuality(latitude, longitude, radius, myDate);
      cout << "The air quality is: " <<  maxIndex << endl;
      break;
    case 2:
      cout << "===== Calculate sensors similarity =====" << endl;
      cout << "Rank the similarity of sensors comparing to one specific sensor" << endl << endl;

      string sensorID;

      date startDate;
      string startDateInput;

      date endDate;
      string endDateInput;

      cout << "Please input the sensorID :" << endl;
      cin >> sensorID;

      cout << "Please input the starting date from which measurements are taken into account :" << endl;
      cin >> startDateInput;
      startDate.year = stoi(startDateInput.substr(0,4));
      startDate.month = stoi(startDateInput.substr(5,2));
      startDate.day = stoi(startDateInput.substr(8,2));

      cout << "Please input the starting time of measurement (hh:mm:ss) :" << endl;
      cin >> startTimeInput;
      startDate.hour = stoi(startTimeInput.substr(0,2));
      startDate.minute = stoi(startTimeInput.substr(3,2));
      startDate.second = stoi(startTimeInput.substr(6,2));

      cout << "Please input the ending date on which measurements are taken into account :" << endl;
      cin >> endDateInput;
      endDate.year = stoi(endDateInput.substr(0,4));
      endDate.month = stoi(endDateInput.substr(5,2));
      endDate.day = stoi(endDateInput.substr(8,2));


      vector <string> similarSensors = calculateSimilarity(sensorID, startDate, endDate);
      vector <string> :: iterator it;
      cout << "The sensors having measurements similar to the chosen sensor are :" << endl;
        for(it = similarSensors.begin(); it != similarSensors.end(); it++)
        {
          cout << it->sensorID << endl;
        }
      break;

    case 3:
      cout << "===== Classify sensor's behavior =====" << endl;
      cout << "Check sensor's data validity" << endl << endl;

      string sensorID;
      date myDate;
      string dateInput;
      float threshold;
      int nbDays;
      int coeff;

      cout << "Please input the sensorID :" << endl << endl;
      cin >> sensorID;

      cout << "Please input the date of measurement :" << endl;
      cin >> dateInput;
      //have to convert dateInput of type string to type Date here

      cout << "Please input the threshold of discrepancy allowed (in %) :" << endl;
      cin >> threshold;

      cout << "Please input the number of days that data are imported for the time comparison" << endl;
      cin >> nbDays;

      cout << "Please input the preferred factor to evaluate the consistency of this sensor's data :" << endl;
      cout << "\t0- Data from neighboring sensors " << endl;
      cout << "\t1- Time" << endl;
      cin >> coeff;

      bool validity = sensorSanityCheck(sensorID, myDate, threshold, nbDays, coeff);
      
      if (bool = true)
      {
        cout << "The data provided by the sensor are valid." << endl;
      } else {
        cout << "The data provided by the sensor are NOT reliable." << endl;
      }
      break;

    default:
      cerr << "Invalid choice. Please try again." << endl;
      continue;
  }

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

int main()
{
    while (1)
    {
      mainMenu();
    }
}
