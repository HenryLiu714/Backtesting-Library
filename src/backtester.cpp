#include "backtester.h"

Engine::Engine(py::object strategy, py::dict config) {
    // Initialize configurations from params
    for (auto item : config) {
        std::string key = py::cast<std::string>(item.first);

        double value = py::cast<double>(item.second);
        configs[key] = value;
    }
}
bool Engine::update_config(const std::string& key, double value) {
    // Update configuration value
    configs[key] = value;
    return true;
}

std::string Engine::get_config(const std::string& key) {
    // Retrieve configuration value by key
    if (configs.find(key) != configs.end()) {
        return std::to_string(configs[key]);
    } else {
        return "Key not found";
    }
}

void Engine::run() {
    // Implementation of the backtesting engine's run method
}
