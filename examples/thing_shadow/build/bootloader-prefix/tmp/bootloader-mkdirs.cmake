# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/Dizr/esp/esp-idf/components/bootloader/subproject"
  "/Users/Dizr/Documents/iot_aws_shadow_common4/aws_iot_/examples/thing_shadow/build/bootloader"
  "/Users/Dizr/Documents/iot_aws_shadow_common4/aws_iot_/examples/thing_shadow/build/bootloader-prefix"
  "/Users/Dizr/Documents/iot_aws_shadow_common4/aws_iot_/examples/thing_shadow/build/bootloader-prefix/tmp"
  "/Users/Dizr/Documents/iot_aws_shadow_common4/aws_iot_/examples/thing_shadow/build/bootloader-prefix/src/bootloader-stamp"
  "/Users/Dizr/Documents/iot_aws_shadow_common4/aws_iot_/examples/thing_shadow/build/bootloader-prefix/src"
  "/Users/Dizr/Documents/iot_aws_shadow_common4/aws_iot_/examples/thing_shadow/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/Dizr/Documents/iot_aws_shadow_common4/aws_iot_/examples/thing_shadow/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
