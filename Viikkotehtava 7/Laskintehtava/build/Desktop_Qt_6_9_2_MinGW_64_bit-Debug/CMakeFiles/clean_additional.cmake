# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Laskintehtava_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Laskintehtava_autogen.dir\\ParseCache.txt"
  "Laskintehtava_autogen"
  )
endif()
