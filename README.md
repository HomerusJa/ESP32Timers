# :hourglass: ESP32Timers

[![PlatformIO Registry](https://badges.registry.platformio.org/packages/homerusja/library/ESP32Timers.svg)](https://registry.platformio.org/libraries/homerusja/ESP32Timers)

ESP32Timers is a library for managing timers on ESP32. It provides classes and functions to create, manage, and check timers.

## :rocket: Features

- `millis()` wraparound handling
- Saving the state to the disc

## :technologist: Classes

### TimerSingle

The `TimerSingle` class represents a single timer. It provides methods to set the interval of the timer, check if the timer has reached its interval, and get the interval of the timer.

:warning: **CAUTION:** This class does not save the state of the timer. Use the Timers class for that purpose!

- `TimerSingle(uint32_t interval)`: Constructs a new Timer Single object with the specified interval in milliseconds.
- `bool isTime()`: Checks if the timer has reached its interval. Returns true if the timer has reached its interval, false otherwise.
- `uint32_t getInterval()`: Returns the interval of the timer in milliseconds.
- `void setInterval(uint32_t interval, bool reset = false)`: Sets the interval of the timer. If `reset` is true, the timer is reset. If false, the timer continues from its current state.

### Timers

The `Timers` class provides a collection of timers for managing intervals. It provides methods to add a timer, check if it's time for a timer to trigger, and set the interval for a timer.

- `Timers(fs::FS &fs, const char *filename)`: Constructs a Timers object. `fs` is the file system to use for loading and saving timers. `filename` is the name of the file to load and save timers.
- `void addTimer(const String &name, uint32_t interval)`: Adds a timer with the specified name and interval in milliseconds.
- `bool isTime(const String &name)`: Checks if it is time for the timer with the specified name to trigger. Returns true if it is time for the timer to trigger, false otherwise.
- `void setInterval(const String &name, uint32_t interval, bool create = false)`: Sets the interval for the timer with the specified name. If the create flag is true, it creates a new timer with that name if it cant find the old one.

## :books: Examples

We provide two examples:

- `single.cpp`: This shows the use, when you want to use only one timer. As stated above, this does not provide the saving functionality!
- `multiple.cpp`: This shows the use of the `Timers`-class, including saving.

## :hammer_and_wrench: Installation

### Depend on it

1. Open `platformio.ini`, a project configuration file located in the root of PlatformIO project.
2. Add the following line to the lib_deps option of [env:] section:

   ```
   homerusja/ESP32Timers@^1.0.0
   ```

3. Build a project, PlatformIO will automatically install dependencies.

### Include it

ESP32Timers library provides the following header files that can be included in your project:

- ESP32Timers.h
- TimerSingle.h
- Timers.h

Note that it is recommended to include the ESP32Timers.h.

```cpp
#include <ESP32Timers.h>
```

### Command Line Interface

1. Open PlatformIO Core CLI
2. Change directory (cd) to the PlatformIO project where platformio.ini is located.
3. Copy the following pio pkg install command and paste into the CLI shell, press Enter:

   ```
   pio pkg install --library "homerusja/ESP32Timers@^1.0.0"
   ```

## :scroll: License

This project is licensed under the MIT License.
