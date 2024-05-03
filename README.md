# ESP32Timers

ESP32Timers is a library for managing timers on ESP32. It provides classes and functions to create, manage, and check timers.

## Classes

### TimerSingle

The `TimerSingle` class represents a single timer. It provides methods to set the interval of the timer, check if the timer has reached its interval, and get the interval of the timer.

**CAUTION:** It does not save the state of the timer. Use the Timers class for that purpose

- `TimerSingle(uint32_t interval)`: Constructs a new Timer Single object with the specified interval in milliseconds.
- `bool isTime()`: Checks if the timer has reached its interval. Returns true if the timer has reached its interval, false otherwise.
- `uint32_t getInterval()`: Returns the interval of the timer in milliseconds.
- `void setInterval(uint32_t interval, bool reset = false)`: Sets the interval of the timer. If `reset` is true, the timer is reset. If false, the timer continues from its current state.

### Timers

The `Timers` class provides a collection of timers for managing intervals. It provides methods to add a timer, check if it's time for a timer to trigger, and set the interval for a timer.

- `Timers(fs::FS &fs, const char *filename)`: Constructs a Timers object. `fs` is the file system to use for loading and saving timers. `filename` is the name of the file to load and save timers.
- `void addTimer(const String &name, uint32_t interval)`: Adds a timer with the specified name and interval in milliseconds.
- `bool isTime(const String &name)`: Checks if it is time for the timer with the specified name to trigger. Returns true if it is time for the timer to trigger, false otherwise.
- `void setInterval(const String &name, uint32_t interval)`: Sets the interval for the timer with the specified name.

## Examples

We provide two examples:

- `single.cpp`: This shows the use, when you want to use only one timer. As stated above, this does not provide the saving functionality!
- `multiple.cpp`: This shows the use of the `Timers`-class, including saving.

## License

This project is licensed under the MIT License.
