cmake_minimum_required(VERSION 3.25.0)

# Uncomment for (gdbserver) debugging
if(BOARD MATCHES "qemu_.*")
  list(APPEND QEMU_EXTRA_FLAGS -serial tcp:127.0.0.1:5678,server)
endif()

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(dds_hello_world)

include(ExternalProject)

include(CMakePrintHelpers)

zephyr_get_system_include_directories_for_lang_as_string(C ext_system_includes)
zephyr_get_include_directories_for_lang_as_string(C ext_includes)
zephyr_get_compile_definitions_for_lang_as_string(C ext_defs)
zephyr_get_compile_options_for_lang_as_String(C ext_opts)

if(CONFIG_POSIX_API)
  # cmake_print_properties(TARGETS posix_subsys 
  #   PROPERTIES COMPILE_DEFINITIONS COMPILE_FEATURES COMPILE_FLAGS COMPILE_OPTIONS INCLUDE_DIRECTORIES INTERFACE_INCLUDE_DIRECTORIES
  # )
  get_target_property(posix_incs posix_subsys INTERFACE_INCLUDE_DIRECTORIES)
  #get_target_property(posix_defs posix_subsys COMPILE_DEFINITIONS)
else()
  message(FATAL_ERROR "CycloneDDS requires POSIX API support (CONFIG_POSIX_API=y)")
endif()

set(ext_cflags
    "${ext_defs} -D_POSIX_C_SOURCE=200809L ${ext_system_includes} ${ext_includes} -I${posix_incs} ${ext_opts}"
)

set(CDDS_LIB_DIR ${CMAKE_CURRENT_BINARY_DIR}/cyclonedds-prefix/lib)
set(CDDS_INCLUDE_DIR ${CMAKE_CURRENT_BINARY_DIR}/cyclonedds-prefix/include)

ExternalProject_Add(cyclonedds
  SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cyclonedds
  BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/cyclonedds
  BUILD_COMMAND ${CMAKE_COMMAND} --build .
  CMAKE_ARGS
  -DBUILD_SHARED_LIBS=0 -DENABLE_SECURITY=0 -DENABLE_SSL=0 -DENABLE_SOURCE_SPECIFIC_MULTICAST=0 -DENABLE_IPV6=1 -DENABLE_SHM=0 -DWITH_ZEPHYR=1 
    -DCMAKE_TRY_COMPILE_TARGET_TYPE=STATIC_LIBRARY
    -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>
    -DCMAKE_VERBOSE_MAKEFILE=1
    -DCMAKE_C_FLAGS=${ext_cflags}
    -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
    -DCMAKE_SYSTEM_NAME=Generic
    -DCMAKE_BUILD_TYPE=Debug
  DEPENDS zephyr_interface
  BUILD_BYPRODUCTS ${CDDS_LIB_DIR}/libddsc.a
)

add_library(cdds_lib STATIC IMPORTED GLOBAL)
add_dependencies(cdds_lib cyclonedds)
set_target_properties(cdds_lib PROPERTIES IMPORTED_LOCATION ${CDDS_LIB_DIR}/libddsc.a)

#set_target_properties(cdds_lib PROPERTIES INTERFACE_INCLUDE_DIRECTORIES ${CDDS_INCLUDE_DIR})
zephyr_library_compile_options(-fno-inline)
target_include_directories(app PUBLIC ${CDDS_INCLUDE_DIR})
target_link_libraries(app PUBLIC cdds_lib)
target_sources(app
  PRIVATE
  src/main.c
  src/HelloWorldData.c
  src/HelloWorldData.h
  #src/threads.c
    #src/gdbstub.c
)
