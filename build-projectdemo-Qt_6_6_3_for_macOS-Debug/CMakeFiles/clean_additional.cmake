# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/projectdemo_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/projectdemo_autogen.dir/ParseCache.txt"
  "projectdemo_autogen"
  )
endif()
