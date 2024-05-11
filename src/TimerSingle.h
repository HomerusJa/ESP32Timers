#pragma once

#include <Arduino.h>

#include <cstdint>

/**
 * @namespace Timers
 * @brief Namespace for timer-related classes and functions.
 */
namespace Timers {

/**
 * @class TimerSingle
 * @brief A class that represents a single timer.
 *
 * This class provides methods to set the interval of the timer,
 * check if the timer has reached its interval, and get the interval of the
 * timer.
 */
class TimerSingle {
   public:
    /**
     * @brief Construct a new Timer Single object.
     *
     * @param interval The interval of the timer in milliseconds.
     */
    TimerSingle(uint32_t interval);

    /**
     * @brief Check if the timer has reached its interval.
     *
     * @return true If the timer has reached its interval.
     * @return false Otherwise.
     */
    bool isTime();

    /**
     * @brief Get the interval of the timer.
     *
     * @return uint32_t The interval of the timer in milliseconds.
     */
    uint32_t getInterval();

    /**
     * @brief Get the remaining time until the timer reaches its interval.
     *
     * @return uint32_t The remaining time in milliseconds.
     */
    uint32_t getRemainingTime();

    /**
     * @brief Set the interval of the timer.
     *
     * @param interval The new interval of the timer in milliseconds.
     * @param reset Whether to reset the timer. If true, the timer is reset. If
     * false, the timer continues from its current state.
     */
    void setInterval(uint32_t interval, bool reset = false);

   private:
    uint32_t _interval;  ///< The interval of the timer in milliseconds.
    uint32_t _nextTime;  ///< The time when the timer will reach its interval.
};
}  // namespace Timers