#pragma once

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <unordered_map>
#include <string>

namespace py = pybind11;

class Engine {
    public:
        Engine(py::object strategy, py::dict config = py::dict());
        bool update_config(const std::string& key, double value);
        std::string get_config(const std::string& key);
        void run();

    private:
        void on_bar();

        void on_event(); // Event router

        std::unordered_map<std::string, double> configs; // Configuration settings
};