# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\chapter4_SimpleObject_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\chapter4_SimpleObject_autogen.dir\\ParseCache.txt"
  "chapter4_SimpleObject_autogen"
  )
endif()
