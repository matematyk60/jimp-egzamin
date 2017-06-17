
project(mapa)

set(HEDEAR_FILES Mapa.h)
set(SOURCE_FILES Mapa.cpp)

add_library(libmapa STATIC ${SOURCE_FILES})
target_include_directories(libmapa PUBLIC .)

add_executable(mapa ${SOURCE_FILES} main.cpp)

target_link_libraries(mapa libmapa)

