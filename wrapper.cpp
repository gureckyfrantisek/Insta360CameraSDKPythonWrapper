#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

float sum_two_nums(float arg1, float arg2) {
    return arg1 + arg2;
}

class ClassName {
    float multiplier;

    public:
        ClassName(float multiplier_) : multiplier(multiplier_) {};
        float multiply(float input) {
            return multiplier * input;
        };

        std::vector<float> multiply_list(std::vector<float> items) {
            for (auto i = 0; i < items.size(); i++) {

                items[i] = multiply(items.at(i));
            
            }
            
            return items;
        };
};

// Change module_name to whatever the file is called, so better to be library here
PYBIND11_MODULE(module_name, handle) {
    handle.doc() = "Returns a sum of two given float numbers.";
    handle.def("python_sum_two_nums", &sum_two_nums);

    py::class_<ClassName>(
        handle, "PyClassName"
    )
    .def(py::init<float>())
    .def("multiply", &ClassName::multiply)
    .def("multiply_list", &ClassName::multiply_list)
    ;
}