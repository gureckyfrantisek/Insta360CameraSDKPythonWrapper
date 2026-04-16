#!/usr/bin/env bash

set -e  # stop on first error

PROJECT_ROOT="$(pwd)"
BUILD_DIR="$PROJECT_ROOT/build"

# Clean build if exists
if [ -d "$BUILD_DIR" ]; then
    echo "Cleaning old build cache..."
    rm -rf "$BUILD_DIR"
fi

echo "Creating build directory..."
mkdir "$BUILD_DIR"

cd "$BUILD_DIR"

echo "Running CMake..."
cmake ..

echo "Building libraries..."
make -j"$(nproc)"

echo "Build complete!"