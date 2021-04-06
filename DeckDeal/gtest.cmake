set(GOOGLETEST_ROOT googletest/googletest CACHE STRING "google test source code")

include_directories(
    SYSTEM
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
)

foreach((_source ${GOOGLETEST_SOURCES}))
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach((_source ${GOOGLETEST_SOURCES}))

add_library(gtest ${GOOGLETEST_SOURCES})