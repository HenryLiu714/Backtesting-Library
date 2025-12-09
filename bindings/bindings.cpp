#include <pybind11/pybind11.h>

namespace py = pybind11;

// Example function in C++ to expose
int add(int a, int b) {
    return a + b;
}

PYBIND11_MODULE(Backtester, m) {
    m.doc() = "Quickstart module to verify pybind11 + CMake build";

    m.def("add", &add, "A function that adds two integers");
}
