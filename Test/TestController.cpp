#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include <map>
#include "Date.h"
#include "Controller.h"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestController : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestController);
    CPPUNIT_TEST(testCalculateAirQuality_T05);
    CPPUNIT_TEST(testCalculateSimilarity_T08);
    CPPUNIT_TEST(testSensorSanityCheck_T02);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testCalculateAirQuality_T05(void);
    void testCalculateSimilarity_T08(void);
    void testSensorSanityCheck_T02(void);
private:

    Controller *controller;
};

//-----------------------------------------------------------------------------

void TestController::testCalculateAirQuality_T05(void) //check the validity of the statistics produced
{
    //to do: calculate an index in a certain area by hand
    int pre_calculated_index = 0;
    float latitude = 0.0;
    float longitude = 0.0;
    int radius = 0;
    Date * myTestDate = new Date(2019,02,03,12,00,00);

    CPPUNIT_ASSERT(pre_calculated_index == controller->calculateAirQuality(latitude, longitude, radius, *myTestDate, *myTestDate, 1));

    delete myTestDate;
}

void TestController::testCalculateSimilarity_T08(void) //all the ranked sensors must be reliable
{
    Date * startDate = new Date(2019,02,6,12,00,00);
    Date * endDate = new Date(2019,03,5,12,00,00);
    int radius = 100;
    multimap<double,pair<string,pair<double,double>>> similarSensors = controller->calculateSimilarity("Sensor0", *startDate, *endDate);
    float threshold = 80;
    for(auto s : similarSensors)
    {
        CPPUNIT_ASSERT(true == controller->sensorSanityCheck("Sensor0", *startDate, radius, threshold/100));
    }

    delete startDate;
    delete endDate;
    //to do : define a date for sensorSanityCheck in between startDate and endDate
}

void TestController::testSensorSanityCheck_T02(void) // return true for reliable sensors, return false otherwise
{
    Date * myDate = new Date(2019,02,6,12,00,00);
    float threshold = 80;
    int radius = 100;
    bool validity = controller->sensorSanityCheck("Sensor0", *myDate, radius, threshold/100);
    CPPUNIT_ASSERT(true == validity);

    delete myDate;
    //to do: insert a non-valid sensor and assert false
}


void TestController::setUp(void)
{
    controller = new Controller();
}

void TestController::tearDown(void)
{
    delete controller;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestController );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // output XML (create an XML file to save the result of the test)
    ofstream xmlFileOut("CppTestControllerResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
