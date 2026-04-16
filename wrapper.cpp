#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <camera/camera.h>
#include <camera/device_discovery.h>
#include <camera/ins_types.h>

namespace py = pybind11;
using namespace ins_camera;

PYBIND11_MODULE(insta360, m) {
    m.doc() = "Insta360 SDK Python bindings";

    // Enums
    py::enum_<CameraType>(m, "CameraType")
        .value("Insta360OneX", CameraType::Insta360OneX)
        .value("Insta360OneR", CameraType::Insta360OneR)
        .value("Insta360OneRS", CameraType::Insta360OneRS)
        .value("Insta360OneX2", CameraType::Insta360OneX2)
        .value("Insta360X3", CameraType::Insta360X3)
        .value("Insta360X4", CameraType::Insta360X4)
        .value("Insta360X5", CameraType::Insta360X5)
        .value("Insta360X4Air", CameraType::Insta360X4Air)
        .value("Unknown", CameraType::Unknown);

    // Structs
    py::class_<DeviceConnectionInfo>(m, "DeviceConnectionInfo")
        .def(py::init<>())
        .def_readwrite("connection_type", &DeviceConnectionInfo::connection_type);

    py::class_<DeviceDescriptor>(m, "DeviceDescriptor")
        .def(py::init<>())
        .def_readwrite("camera_type", &DeviceDescriptor::camera_type)
        .def_readwrite("serial_number", &DeviceDescriptor::serial_number)
        .def_readwrite("camera_name", &DeviceDescriptor::camera_name)
        .def_readwrite("fw_version", &DeviceDescriptor::fw_version)
        .def_readwrite("info", &DeviceDescriptor::info);

    // MediaUrl
    py::class_<MediaUrl>(m, "MediaUrl")
        .def("empty", &MediaUrl::Empty)
        .def("is_single_origin", &MediaUrl::IsSingleOrigin)
        .def("get_single_origin", &MediaUrl::GetSingleOrigin)
        .def("origin_urls", &MediaUrl::OriginUrls);

    // DeviceDiscovery
    py::class_<DeviceDiscovery>(m, "DeviceDiscovery")
        .def(py::init<>())
        .def("get_available_devices", &DeviceDiscovery::GetAvailableDevices);

    // Camera
    py::class_<Camera, std::shared_ptr<Camera>>(m, "Camera")
        .def(py::init<const DeviceConnectionInfo&>())
        .def("open", &Camera::Open)
        .def("close", &Camera::Close)
        .def("start_recording", &Camera::StartRecording)
        .def("stop_recording", &Camera::StopRecording)
        .def("get_camera_files_list", &Camera::GetCameraFilesList)
        .def("is_connected", &Camera::IsConnected);
}