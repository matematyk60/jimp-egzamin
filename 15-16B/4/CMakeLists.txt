
project(simple)

set(HEDEAR_FILES Simple.h)
set(SOURCE_FILES Simple.cpp)

add_library(libsimple STATIC ${SOURCE_FILES})
target_include_directories(libsimple PUBLIC .)

add_executable(simple ${SOURCE_FILES} main.cpp)

target_link_libraries(simple libsimple)

