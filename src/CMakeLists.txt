#cmake#
#cmake_minimum_required (VERSION 2.6)
#project (mask_lyc)

set(SRC_LIST mask_lyc.cpp)

set (INCLUDE_DIRECTORIES  ../include)
set (LINK_DIR  ../resource)
set (CMAKE_BUILD_TYPE Release)

set (CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DEMBED")

include_directories(${INCLUDE_DIRECTORIES}
                    /usr/include
                    /usr/include/c++/5.3.1
                    /usr/include/c++/5.3.1/x86_64-redhat-linux
                    /usr/lib/gcc/x86_64-redhat-linux/5.3.1/incude
                    /usr/local/include)


link_directories(${LINK_DIR})
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/${LIBRARY_DIRECTORIES})

#add_library(iimod SHARE  ${LIB_SRC_LIST})
add_executable(Test_mask ${SRC_LIST})

#target_link_libraries(Test_Mask mask_lyc)
