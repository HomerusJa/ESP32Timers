#include "Timers.h"

namespace Timers {
Timers::Timers(fs::FS &fs, const char *filename) : _fs(fs), _filename(filename) { load(); }

Timers::~Timers() {
    save();
    for (auto &timer : _timers) {
        delete timer.second;
    }
}

void Timers::addTimer(const String &name, uint32_t interval) {
    if (_timers.find(name) != _timers.end()) {
        // Timer with the same name already exists
        return;
    }
    _timers[name] = new TimerSingle(interval);
    save();
}

bool Timers::isTime(const String &name) {
    if (_timers[name]->isTime()) {
        save();
        return true;
    }
    return false;
}

void Timers::setInterval(const String &name, uint32_t interval, bool create) {
    if (_timers.find(name) == _timers.end()) {
        // Timer with the given name does not exist, so we create a new one
        this->addTimer(name, interval);
    } else {
        _timers[name]->setInterval(interval);
    }
    save();
}

void Timers::load() {
    // This is going to create the file if it doesn't exist
    File file = _fs.open(_filename, "r", true);
    if (file) {
        JsonDocument doc;
        deserializeJson(doc, file);
        JsonObject obj = doc.as<JsonObject>();
        for (JsonPair p : obj) {
            _timers[p.key().c_str()] = new TimerSingle(p.value().as<uint32_t>());
        }
        file.close();
    }
}

void Timers::save() {
    File file = _fs.open(_filename, FILE_WRITE);
    if (file) {
        JsonDocument doc;
        JsonObject obj = doc.to<JsonObject>();
        for (auto &t : _timers) {
            obj[t.first] = t.second->getInterval();
        }
        serializeJson(doc, file);
        file.close();
    }
}
}  // namespace Timers