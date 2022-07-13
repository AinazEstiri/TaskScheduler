cmake_minimum_required(VERSION 3.0.2)

SET(CMAKE_CXX_STANDARD 11)

project(addTaskMenu)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(test
	unit_test.cpp
)

ADD_EXECUTABLE(TaskManager
        main.cpp
)


TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
