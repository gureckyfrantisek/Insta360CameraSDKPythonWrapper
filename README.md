# Insta360CameraSDKPythonWrapper
 A pybind11 wrapper for the Insta360 SDK

## Prerequisites

You need the following installed:

- CMake
- Python 3
- A C++ compiler (g++)

### Install cmake
Use your systems way to install it, for example:
```bash
sudo apt-get install cmake python3 python3-dev g++
```

Pybind11 is loaded in the CMake file.

### Run the compilation
Simply run the:
```bash
./setup.sh
```

This will bundle the C++ libraries included in the CMakeLists.txt which you have to supply. You can also run this when you want to recompile the libraries.

## See the example
Now you are ready to run the example main.py.

### Activate the virtual enviroment
Run this in the root directory:
```bash
python -m venv .venv`
```

and then activate using:
```bash
source .venv/bin/activate`
```

Or you don't need the venv and can run the file directly with:
`python main.py`

## Your use case
To use the wrapped SDK simply add the *.so file from the build directory to your project and import it as it is in the example.