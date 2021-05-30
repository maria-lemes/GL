#include <iostream>
#include <string.h>
#include <vector>
//#include "Controller.cpp"
#include "Read.cpp"
//#include "Measurement.cpp"
//#include "Controller.cpp"
using namespace std;

int main()
{
  Read read;
  read.readSensor("./data/sensors.csv");
  for (auto sensor : read.getSensorList())
  {
    cout << sensor.getSensorID() << " || lat: " << sensor.getLatitude() <<
     " lon: " << sensor.getLongitude() << endl;
  }
}