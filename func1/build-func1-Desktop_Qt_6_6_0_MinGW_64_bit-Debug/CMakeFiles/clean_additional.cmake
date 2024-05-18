# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\func1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\func1_autogen.dir\\ParseCache.txt"
  "func1_autogen"
  )
endif()
