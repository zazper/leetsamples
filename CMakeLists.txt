# CMakeList.txt : CMake project for myLeetCode, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("myLeetCode")

# Add source to this project's executable.
#add_executable (myLeetCode "myLeetCode.cpp" "myLeetCode.h "myLeetCode (2).cpp"")

set(COMMON_SOURCES file1.cpp file2.cpp)
set(TARGET_SOURCES main.cpp)
set(TEST_SOURCES  run_tests.cpp test_file1.cpp test_file2.cpp)
add_executable (myLeetCode "test/leetSamples.cpp" "src/leetSamples.h")
add_executable (two_sum "src/TwoSum.cpp" "src/leetSamples.h")
add_executable (add_number "src/AddNumber.cpp" "src/leetSamples.h" )
add_executable (med_two_sort_arr "src/MedianTwoSortedArrays.cpp" "src/leetSamples.h" )
add_executable (long_pal_substr "src/LongestPalindromicSubstring.cpp" "src/leetSamples.h" )

#add_executable(tests ${COMMON_SOURCES} ${TEST_SOURCES})


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET myLeetCode PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
