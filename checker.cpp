#include <assert.h>
bool bpmisNotOk(float bpm)
{
    return (bpm < 70 || bpm > 150);
}
bool spo2isNotOk(float spo2)
{
    return (spo2 < 90);
}
bool RespRateisNotOk(float respRate)
{
    return (respRate < 30 || respRate > 95);
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
    bool result = bpmisNotOk(bpm) || spo2isNotOk(spo2) || RespRateisNotOk(respRate);
    return !result;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
