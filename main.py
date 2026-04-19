import build.camerasdk as insta360
import time
import os

# This example shows an example workflow
# 1. connects to the first camera it discovers
# 2. opens it and starts recording
# 3. after 3 seconds ends the recording
# 4. gives you the option to downloaded the new files
# (5.) if you choose to do so, it downloads them to data_dir and removes them from the camera

def progress(current, total):
    """Callback function for the download progress"""
    percent = (current / total) * 100
    print(f"Downloading file: {round(percent, 3)} %")

# Config
data_dir = "/tmp/Insta360Data"
os.makedirs(data_dir, exist_ok=True)

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

    if input("Write one if you want to download the new files: ") == str(1):
        for file in new_files:
            file_name = os.path.basename(file)
            local_file = os.path.join(data_dir, file_name)

            cam.download_file(file, local_file, progress)

            # Cleanup after a succesfull download
            # Note: doesn't give feedback by itself
            cam.delete_file(file)
            print(f"File removed from the camera: {file}")

    cam.close()

else:
    print("No devices found.")