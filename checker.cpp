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
  assert(isInsideLimits(80, 70, 150) == true);  //  in range
  assert(isInsideLimits(60, 70, 150) == false); //  outside lower limit
  assert(isInsideLimits(160, 70, 150) == false); // outside higher limit 
  cout << "All OK!";
  assert(vitalsAreOk(80, 95, 60) == true);
<<<<<<< HEAD
  assert(vitalsAreOk(60, 90, 40) == false);
  }
=======
  assert(vitalsAreOk(60, 95, 40) == false);
  assert(vitalsAreOk(80, 85, 60) == false);
  assert(vitalsAreOk(80, 95, 125) == false);
}
>>>>>>> d01d20eb089df030544671be8d5b3c2de4af92d8
