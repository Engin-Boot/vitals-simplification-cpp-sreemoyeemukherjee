#include <assert.h>
#include <iostream>
using namespace std;
class AlertInterface
{
public:
    virtual void raiseAlert(const char* vitalName, const char* level) = 0;
};
class AlertWithSMS: public AlertInterface
{
public:
    void raiseAlert(const char* vitalName,const char* level) override
    {
        cout << "SMS: " << vitalName << " " << level<<endl;     //WHAT
    }
};
class AlertWithSound: public AlertInterface
{
public:
    void raiseAlert(const char* vitalName,const char* level) override
    {
        cout << "Sound: " << vitalName << " " << level<<endl;
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
        smsAlerter.raiseAlert(vitalName,level);
        soundAlerter.raiseAlert(vitalName,level);
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
        if (value < lower) {
            alerter->raiseAlert(vitalName, "too low");      //WHEN
        }
        else if (value > upper) {
            alerter->raiseAlert(vitalName, "too high");
        }
        else
        {
           // alerter->raiseAlert(vitalName, "is ok"); // TOO MANY NOTIFICATIONS
        }
    }
};
class VitalsIntegrator
{
private:
    RangeChecker bpmChecker, spo2Checker, respChecker;
public:
    VitalsIntegrator(AlertInterface* alerterPtr) :bpmChecker("pulse rate", 70, 150, alerterPtr),
        spo2Checker("spo2", 90, 101, alerterPtr), respChecker("resp rate", 30, 95, alerterPtr){}
    void checkAllVitals(float bpm, float spo2, float respRate)
    {
        bpmChecker.checkAgainstRange(bpm);
        spo2Checker.checkAgainstRange(spo2);
        respChecker.checkAgainstRange(respRate);
    }
};

int main() {
  /*  int alerConfig = 0;
    // read from config file 0=>SMS, 1=>SOUND
    AlertInterface* alerter = 0;
    if (alerConfig == 0)
    {
        alerter = new AlertWithSMS;
    }
    else if (alerConfig == 1)
    {
        alerter = new AlertWithSound;
    }
    VitalsIntegrator vitals(alerter);*/
    //AlertWithSMS alerter;
    //AlertWithSound alerter;
    //VitalsIntegrator vitals(&alerter);

    AlertIntegrator alerter;
    VitalsIntegrator vitals(&alerter);

    vitals.checkAllVitals(80, 95, 60); 
    vitals.checkAllVitals(60, 90, 40);
}