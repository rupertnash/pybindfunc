
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>
namespace py = pybind11;

#include "example.h"


// this is a simple example

PYBIND11_MODULE(example, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring
    m.def("add", &add, "A function which adds two numbers");

    py::class_<Pair>(m, "Pair")
      .def(py::init<int, int>())
      .def("SetOp", &Pair::SetOp)
      .def("__call__", &Pair::operator());
}
