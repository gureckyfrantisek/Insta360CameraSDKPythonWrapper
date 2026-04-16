import build.insta360 as insta360
import time

discovery = insta360.DeviceDiscovery()
devices = discovery.get_available_devices()

print("Devices:", devices)

if devices:
    cam = insta360.Camera(devices[0].info)

    print(f"Opening camera: {devices[0].camera_name} of type {devices[0].camera_type}")
    cam.open()

    cam_files1 = cam.get_camera_files_list()
    print(f"Files before recording: {cam_files1}")

    print("Recording...")
    cam.start_recording()

    time.sleep(3)

    url = cam.stop_recording()
    print("Result:", url.get_single_origin())

    cam_files2 = cam.get_camera_files_list()
    print(f"Files after recording: {cam_files2}")

    new_files = list(set(cam_files2) - set(cam_files1))
    print(f"New files created: {new_files}")

    cam.close()

else:
    print("No devices found.")