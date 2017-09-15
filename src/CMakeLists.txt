# TODO: Is any of that needed?!
# What needs to go into this file?

set(target_name, CppTest_src)

include_directories(${CppTest_SOURCE_DIR}/src)

message("CppTest_SOURCE_DIR=" ${CppTest_SOURCE_DIR})


# This complains about Policy CMP0037:
# The target name "/Users/julien/Software/Cpp-test/src/Boy.hpp" is reserved
# or not valid for certain CMake features, such as generator expressions, and
# may result in undefined behavior.
#file(GLOB CppTest_SRC
    #"*.hpp"
    #"*.cpp"
#)

set(CppTest_SRC_files
  Boy.cpp
  Boy.hpp
  Girl.cpp
  Girl.hpp
  Person.cpp
  Person.hpp
  # main.cpp   # TODO: include??
  )


message("CppTest_SRC=" ${CppTest_SRC_files})
# TODO: ??
add_library(${target_name} ${CppTest_SRC_files})

# TODO: Here? Or in ../CMakeLists.txt?
add_executable(CppTest main.cpp)
target_link_libraries(CppTest ${target_name})
