
project(wielomian)

set(HEDEAR_FILES Wielomian.h)
set(SOURCE_FILES Wielomian.cpp)

add_library(libwielomian STATIC ${SOURCE_FILES})
target_include_directories(libwielomian PUBLIC .)

add_executable(wielomian ${SOURCE_FILES} main.cpp)

target_link_libraries(wielomian libwielomian)

