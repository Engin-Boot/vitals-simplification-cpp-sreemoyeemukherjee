#include <assert.h>
bool BPM(float bpm)
{
    return (bpm < 70 || bpm > 150);
}
bool SPO2(float spo2)
{
    return (spo2 < 90);
}
bool RespRate(float respRate)
{
    return (respRate < 30 || respRate > 95);
}
bool vitalsAreOk(float bpm, float spo2, float respRate) {
    bool result = BPM(bpm) || SPO2(spo2) || RespRate(respRate);
    return !result;
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
