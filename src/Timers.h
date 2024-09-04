#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <FS.h>

#include <map>

#include "TimerSingle.h"

namespace Timers {
/**
 * @brief The Timers class provides a collection of timers for managing
 * intervals.
 */
class Timers {
   public:
    /**
     * @brief Constructs a Timers object.
     * @param fs The file system to use for loading and saving timers. Examples
     * of file systems are SPIFFS, SD_MMC and LittleFS.
     * @param filename The name of the file to load and save timers. This could
     * also be a path if the file system supports it.
     * @param load If true, the timers are loaded from the file system. This
     * crashes if the filesystem is not mounted.
     */
    Timers(fs::FS &fs, const char *filename, bool load = true);

    /**
     * @brief Destroys the Timers object.
     */
    ~Timers();

    /**
     * @brief Adds a timer with the specified name and interval. If a timer with
     * the same name already exists, it is not added and the old configuration is
     * kept.
     * @param name The name of the timer.
     * @param interval The interval in milliseconds.
     */
    void addTimer(const String &name, uint32_t interval);

    /**
     * @brief Checks if it is time for the timer with the specified name to
     * trigger.
     * @param name The name of the timer.
     * @return True if it is time for the timer to trigger, false otherwise.
     */
    bool isTime(const String &name);

    /**
     * @brief Sets the interval for the timer with the specified name.
     * @param name The name of the timer.
     * @param interval The new interval in milliseconds.
     * @param create If true, a new timer is created if there is no timer with
     * the specified name.
     */
    void setInterval(const String &name, uint32_t interval, bool create = false);

    /**
     * @brief Checks if a timer with the specified name exists.
     * @param name The name of the timer.
     * @return True if a timer with the specified name exists, false otherwise.
     */
    bool timerExists(const String &name) { return _timers.find(name) != _timers.end(); }

    uint32_t getRemainingTime(const String &name);

   private:
    /**
     * @brief Loads the timers from the file system.
     */
    void load();

    /**
     * @brief Saves the timers to the file system.
     */
    void save();

    fs::FS &_fs; /**< The file system used for loading and saving timers. */
    std::map<String, TimerSingle *> _timers; /**< The collection of timers. */
    const char *_filename;                   /**< The name of the file to load and save timers. */
};
}  // namespace Timers