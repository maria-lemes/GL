/*#include <iostream>
#include <string.h>
#include <vector>
#include <iostream>
#include "Attribute.h"
#include "Cleaner.h"
#include "Measurement.h"
#include "PrivateIndividual.h"
#include "Provider.h"
#include "Sensor.h"
#include "Read.h"
#include "Date.h"
using namespace std;

int main()
{
  Read read;
  read.readSensor("./data/cleaners.csv");
  for (auto sensor : read.getCleanerList())
  {
    cout << sensor.getCleanerID() << " || lat: " << sensor.getLatitude() <<
     " lon: " << sensor.getLongitude() << "timestart : " << sensor.getStart() << "timestop : " << sensor.getStop();
  }
}
*/