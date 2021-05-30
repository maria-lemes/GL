#include <iostream>
#include <string.h>
#include <vector>
#include <iostream>
#include "Attribute.cpp"
#include "Cleaner.cpp"
#include "Measurement.cpp"
#include "PrivateIndividual.h"
#include "PrivateIndividual.cpp"
#include "Provider.cpp"
#include "Sensor.cpp"
#include "Read.cpp"
#include "Date.cpp"
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