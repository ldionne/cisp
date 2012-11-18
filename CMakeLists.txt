cmake_minimum_required(VERSION 2.8)
project(cisp)

add_definitions(-std=c89 -Wall -Wextra -pedantic)

include_directories(${cisp_SOURCE_DIR}/include)
include_directories(${cisp_SOURCE_DIR}/ext/joy/include)
include_directories(${cisp_SOURCE_DIR}/ext/chaos)


file(GLOB_RECURSE editable_files ${cisp_SOURCE_DIR}/include/*.h)
set(cog_fix_pypath export PYTHONPATH=$ENV{PYTHONPATH}:${cisp_SOURCE_DIR}/tools/cog)
set(cog ${cog_fix_pypath} && python ${cisp_SOURCE_DIR}/tools/cog/scripts/cog.py)
set(macroize ${cog_fix_pypath} && python ${cisp_SOURCE_DIR}/tools/macroize/macroize.py)
set(cog_flags -I ${cisp_SOURCE_DIR}/tools/)

# Clean up the source files from generated boilerplate to facilitate editing.
add_custom_target(
    ungenerate
    DEPENDS ${editable_files}
    COMMAND ${cog} ${cog_flags} -x -r ${editable_files} > /dev/null
    COMMAND ${macroize} ${editable_files} -u
    WORKING_DIRECTORY ${cisp_SOURCE_DIR}
)

# Run Cog and ``macroize'' on the source files to regenerate boilerplate.
add_custom_target(
    generate
    DEPENDS ${editable_files}
    COMMAND ${macroize} ${editable_files}
    COMMAND ${cog} ${cog_flags} -r ${editable_files} > /dev/null
    WORKING_DIRECTORY ${cisp_SOURCE_DIR}
)

file(GLOB_RECURSE test_files ${cisp_SOURCE_DIR}/test/*.c)
set_source_files_properties(${test_files} PROPERTIES COMPILE_FLAGS -P)
add_executable(preprocess ${test_files}) # This is just to get the %.i targets.
