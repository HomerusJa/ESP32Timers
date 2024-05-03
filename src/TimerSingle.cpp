#include "TimerSingle.h"

namespace Timers {

bool TimerSingle::isTime() {
  uint32_t now = millis();
  // This statement handles the case where the timer has wrapped around
  bool wrapped = _nextTime < _interval;
  if (now >= _nextTime || !wrapped) {
    _nextTime = now + _interval;
    return true;
  }
  return false;
}

uint32_t TimerSingle::getInterval() { return _interval; }

uint32_t TimerSingle::getRemainingTime() {
  uint32_t now = millis();

  bool wrapped = _nextTime < _interval;

  if (wrapped) {
    return UINT32_MAX - now + _nextTime;
  } else {
    return _nextTime > now ? _nextTime - now : 0;
  }
}

void TimerSingle::setInterval(uint32_t interval, bool reset) {
  if (reset) {
    _interval = interval;
    _nextTime = millis() + interval;
  } else {
    uint32_t now = millis();
    uint32_t remainingTime = (_nextTime > now) ? _nextTime - now : 0;
    _interval = interval;
    _nextTime = now + interval - remainingTime;
  }
}
} // namespace Timers