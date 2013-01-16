cmake_minimum_required(VERSION 2.8)
project(iris)

find_package(catkin)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES iris-printf
)

include_directories(include)

add_library(iris-printf
  src/logger-printf.cpp
)

add_executable(iris_example1
  test/example.cpp)
target_link_libraries(iris_example1 iris-printf -lstdc++)

add_executable(iris_example2
  test/example2.cpp)
target_link_libraries(iris_example2 iris-printf -lstdc++)

install(TARGETS iris-printf
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION})

install(DIRECTORY include/
  DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp")
