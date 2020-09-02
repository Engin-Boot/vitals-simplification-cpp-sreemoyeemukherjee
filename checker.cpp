#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;
class AlertInterface
{
  public:
    virtual void raiseAlert(const char* vitalName, const char* level) = 0;
};

class AlertWithSMS: public AlertInterface
{
  public:
    void raiseAlert(const char* vitalName, const char* level) override
    {
      std::cout << "SMS: " << vitalName << " " << level << std::endl;
    }
};

class AlertWithSound: public AlertInterface
{
  public:
    void raiseAlert(const char* vitalName, const char* level) override
    {
      std::cout << "Sound: " << vitalName << " " << level << std::endl;  //'what'
    }
};

class AlertIntegrator : public AlertInterface
{
  private:
    AlertWithSMS smsAlerter;
    AlertWithSound soundAlerter;
  public:
    void raiseAlert(const char* vitalName, const char* level) override
    {
      smsAlerter.raiseAlert(vitalName, level);
      soundAlerter.raiseAlert(vitalName, level);
    }
};

class RangeChecker
{
  private:
    int lower;
    int upper;
    const char* vitalName;
    AlertInterface* alerter;
  public:
    RangeChecker(const char* name, int low, int up, AlertInterface* alerterPtr)
    {
      vitalName = name;
      lower = low;
      upper = up;
      alerter = alerterPtr;
    }
    void checkAgainstRange(float value)
    {
      if(value < lower) {
        alerter->raiseAlert(vitalName, "too low");  //'when'
      } else if(value > upper) {
        alerter->raiseAlert(vitalName, "too high");
      }
    }
};

class VitalsIntegrator
{
private:
    vector<RangeChecker> VitalUnits;
    public:
    VitalsIntegrator(AlertInterface* alertPtr)
    {
        RangeChecker r1("pulse rate", 70, 150, alertPtr), r2("spo2", 90, 101, alertPtr), r3("resp rate", 30, 95, alertPtr);
        VitalUnits.push_back(r1);
        VitalUnits.push_back(r2);
        VitalUnits.push_back(r3);
    }
    void checkAllVitals(const vector<float>& units)
    {
        for (int i = 0; i < units.size(); i++)
        {
            VitalUnits[i].checkAgainstRange(units[i]);
        }
    }
};

int main() {
  //AlertIntegrator alerter;  
  AlertInterface* alerter1;             // base class pointer
  alerter1 = new AlertWithSMS;          // Alert with SMS
  VitalsIntegrator vitals1(alerter1);
  
  vitals1.checkAllVitals({80, 95, 60});       // All OK condition
  vitals1.checkAllVitals({60, 90, 140 });      // pulse rate 'too low', resp rate 'too high' 

  AlertInterface* alerter2;             
  alerter2 = new AlertWithSound;        // Alert with Sound
  VitalsIntegrator vitals2(alerter2);
  vitals2.checkAllVitals({ 160, 95, 60 });      // pulse rate 'too high'

}
