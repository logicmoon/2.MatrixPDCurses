cmake_minimum_required(VERSION 3.23)
project(2.MatrixPDCurses)

add_compile_options(
        -Wall -Werror -Wno-error=maybe-uninitialized
        $<$<CONFIG:RELEASE>:-O3>
)

set(PDCURSES_LIBRARY ${PROJECT_SOURCE_DIR}/lib/pdcurses.dll)
set(PDCURSES_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/inc/)

add_executable(2.MatrixPDCurses main.cpp TextMatrix.cpp TextMatrix.h ui.cpp ui.h)

target_compile_features(2.MatrixPDCurses PUBLIC cxx_std_20)

find_package(Boost REQUIRED)
message(STATUS "Found Boost::multiarray: ${BOOST_FOUND}")

include_directories(2.MatrixPDCurses ${Boost_INCLUDE_DIRS} ${PDCURSES_INCLUDE_DIR})
#target_include_directories(2_SimpleCursesApp PRIVATE ${PDCURSES_INCLUDES})
target_link_libraries(2.MatrixPDCurses PRIVATE ${PDCURSES_LIBRARY} ${BOOST_multi_array_LIBRARY})