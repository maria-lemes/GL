#include <iostream>
#include <string.h>
#include <vector>
#include "Read.h"
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