cmake_minimum_required(VERSION 3.12)
project(Base64Encoder)

set(CMAKE_CXX_STANDARD 14)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
ADD_LIBRARY(boost_unit_test_framework STATIC IMPORTED)
SET_TARGET_PROPERTIES(boost_unit_test_framework PROPERTIES
        IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.a)


add_executable(Base64Encoder
        Dependencies/BitBuffer.cpp
        Dependencies/BitBuffer.h
        Base64Encode.cpp
        Base64Encode.h
        Dependencies/Constants.h Tests/ModuleTest.cpp Tests/ModuleTest.h)

target_link_libraries(Base64Encoder ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})