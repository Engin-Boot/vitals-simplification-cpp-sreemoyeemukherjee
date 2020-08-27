#include <assert.h>
#include <iostream>
using namespace std;
bool isInsideLimits(float value, float lowerLimit, float upperLimit)
{
    return(value > lowerLimit && value < upperLimit);
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
    return (isInsideLimits(bpm, 70, 150) && isInsideLimits(spo2, 90, 100) && isInsideLimits(respRate, 30, 95));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  assert(vitalsAreOk(60, 85, 125) == false);
}
