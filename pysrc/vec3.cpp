#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include "vec3.h"

namespace py = pybind11;
using namespace pybind11::literals;

namespace jtrace {
    void pyExportVec3(py::module &m) {
        py::class_<Vec3>(m, "Vec3")
            .def(py::init<double,double,double>(), "init", "x"_a, "y"_a, "z"_a)
            .def(py::init<>())
            .def("MagnitudeSquared", &Vec3::MagnitudeSquared)
            .def("Magnitude", &Vec3::Magnitude)
            .def("UnitVec3", &Vec3::UnitVec3)
            .def("__repr__", &Vec3::repr)
            .def_readonly("x", &Vec3::x)
            .def_readonly("y", &Vec3::y)
            .def_readonly("z", &Vec3::z)
            .def(py::self + py::self)
            .def(py::self += py::self)
            .def(py::self - py::self)
            .def(py::self -= py::self)
            .def(py::self * float())
            .def(py::self *= float())
            .def(py::self / float())
            .def(py::self /= float())
            .def(py::self == py::self)
            .def(py::self != py::self)
            .def(-py::self);
        m.def("DotProduct", &DotProduct);
        m.def("CrossProduct", &CrossProduct);

        py::class_<Mat3>(m, "Mat3", py::buffer_protocol())
            .def(py::init<>())
            .def_buffer([](Mat3 &mm) -> py::buffer_info {
                return py::buffer_info(
                    mm.data.data(),
                    sizeof(double),
                    py::format_descriptor<double>::format(),
                    2,
                    {3, 3},
                    {sizeof(double) * 3, sizeof(double)}
                );
            });
    }
}
