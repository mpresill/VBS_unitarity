cmake_minimum_required(VERSION 3.16)
set(CMAKE_INSTALL_PREFIX ../)

project(StandardModel)

list(APPEND CMAKE_PREFIX_PATH /home/nyykki/root)
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})

set(CMAKE_CXX_STANDARD_REQUIRED 14)
set(CMAKE_CXX_STANDARD 14)

################### HISTOGRAMS BUILDING ###################

add_executable(split_eft_contr src/split_eft_contr.cpp)
target_link_libraries(split_eft_contr PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/test/libExRootAnalysis.so)
install(TARGETS split_eft_contr DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(definitivo src/definitivo.cpp)
target_link_libraries(definitivo PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/test/libExRootAnalysis.so)
install(TARGETS definitivo DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(merge src/merge.cpp)
target_link_libraries(merge PUBLIC ${ROOT_LIBRARIES} /home/nyykki/Scrivania/test/libExRootAnalysis.so)
install(TARGETS merge DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

################### HISTOGRAMS PLOTTING ###################

add_executable(distributions src/distributions.cpp)
target_link_libraries(distributions PUBLIC ${ROOT_LIBRARIES})
install(TARGETS distributions DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(distributions_compare src/distributions_compare.cpp)
target_link_libraries(distributions_compare PUBLIC ${ROOT_LIBRARIES})
install(TARGETS distributions_compare DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})  


