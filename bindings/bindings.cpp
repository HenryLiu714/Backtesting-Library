#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "backtester.h"

namespace py = pybind11;

PYBIND11_MODULE(Backtester, m) {
    m.doc() = "C++ Backtesting engine";

    py::class_<Engine>(m, "Engine")
        .def(py::init([](py::dict params = py::dict()) { return new Engine(params); }))
        .def("run", &Engine::run, "Run the backtesting engine")
        .def("update_config", &Engine::update_config, "Update configuration value",
             py::arg("key"), py::arg("value"))
        .def("get_config", &Engine::get_config, "Retrieve configuration value by key",
             py::arg("key"));
}
