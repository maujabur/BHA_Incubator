// timing functions (MJ)
// code by Mauricio Jabur, beerware
//////////////////////////////////////////////////////////
// Interval.h
//////////////////////////////////////////////////////////

#ifndef INTERVAL_H
#define INTERVAL_H

#include "arduino.h"

class Interval {
  public:
    long t;
    long dt;

    Interval(long timeout);
    bool check();
    void reset();
};

//////////////////////////////////////////////////////////
// Interval.cpp
//////////////////////////////////////////////////////////

//#include "Interval.h"

Interval::Interval(long timeout) {
  dt = timeout;
  reset();
}

bool Interval::check() {
  if (millis() - t > dt) {
    t += dt;
    return true;
  }
  return false;
}

void Interval::reset() {
  t = millis();
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
#endif //INTERVAL_H
