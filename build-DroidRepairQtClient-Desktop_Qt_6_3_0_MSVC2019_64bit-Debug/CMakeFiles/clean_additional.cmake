# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DroidRepairQtClient_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DroidRepairQtClient_autogen.dir\\ParseCache.txt"
  "DroidRepairQtClient_autogen"
  )
endif()
