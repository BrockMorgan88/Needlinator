# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "/home/brock/.platformio/packages/framework-espidf@src-b1208ff3612f5ed4a85e916decb6f42c/components/bootloader/subproject")
  file(MAKE_DIRECTORY "/home/brock/.platformio/packages/framework-espidf@src-b1208ff3612f5ed4a85e916decb6f42c/components/bootloader/subproject")
endif()
file(MAKE_DIRECTORY
  "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader"
  "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader-prefix"
  "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader-prefix/tmp"
  "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader-prefix/src/bootloader-stamp"
  "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader-prefix/src"
  "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/brock/Documents/PlatformIO/Projects/CAM/.pio/build/esp32s3camlcd/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
