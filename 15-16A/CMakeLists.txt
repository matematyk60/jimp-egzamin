
project(listatablic)

set(HEDEAR_FILES ListaTablic.h)
set(HEDEAR_FILES LE.h)
set(SOURCE_FILES ListaTablic.cpp)
set(SOURCE_FILES LE.cpp)

add_library(liblistatablic STATIC ${SOURCE_FILES})
target_include_directories(liblistatablic PUBLIC .)

add_executable(listatablic ${SOURCE_FILES} main.cpp)

target_link_libraries(listatablic liblistatablic)

